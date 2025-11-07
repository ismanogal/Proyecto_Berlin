import asyncio
from aiohttp import web

routes = web.RouteTableDef()

@routes.get('/')
async def index(request):
    return web.FileResponse('index.html')

@routes.get('/ws')
async def websocket_handler(request):
    ws = web.WebSocketResponse()
    await ws.prepare(request)

    # Arranca el proceso C++ (ajusta el path si es necesario)
    proc = await asyncio.create_subprocess_exec(
        './build/main',
        stdin=asyncio.subprocess.PIPE,
        stdout=asyncio.subprocess.PIPE,
        stderr=asyncio.subprocess.STDOUT
    )

    async def read_proc_and_forward():
        while True:
            line = await proc.stdout.readline()
            if not line:
                await ws.send_str('[process closed]')
                break
            # convierte bytes → texto
            decoded = line.decode('utf-8', errors='ignore').rstrip('\n')
            await ws.send_str(decoded)

    async def read_ws_and_forward():
        async for msg in ws:
            if msg.type == web.WSMsgType.TEXT:
                # convierte texto → bytes
                proc.stdin.write((msg.data + '\n').encode('utf-8'))
                await proc.stdin.drain()
            else:
                break

    # Ejecuta ambas tareas en paralelo
    task1 = asyncio.create_task(read_proc_and_forward())
    task2 = asyncio.create_task(read_ws_and_forward())

    done, pending = await asyncio.wait(
        [task1, task2],
        return_when=asyncio.FIRST_COMPLETED
    )
    for t in pending:
        t.cancel()

    # Cierra proceso y socket
    if proc.returncode is None:
        proc.kill()
    await ws.close()
    return ws

app = web.Application()
app.add_routes(routes)

if __name__ == '__main__':
    web.run_app(app, host='0.0.0.0', port=8080)
