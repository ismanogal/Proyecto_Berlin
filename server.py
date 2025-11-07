import asyncio
import os
from aiohttp import web

routes = web.RouteTableDef()

@routes.get('/')
async def index(request):
    return web.FileResponse('index.html')

@routes.get('/ws')
async def websocket_handler(request):
    ws = web.WebSocketResponse()
    await ws.prepare(request)

    proc = await asyncio.create_subprocess_exec(
        './main',
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
            await ws.send_str(line.decode('utf-8', errors='ignore').rstrip('\n'))

    async def read_ws_and_forward():
        async for msg in ws:
            if msg.type == web.WSMsgType.TEXT:
                proc.stdin.write((msg.data + '\n').encode('utf-8'))
                await proc.stdin.drain()
            else:
                break

    task1 = asyncio.create_task(read_proc_and_forward())
    task2 = asyncio.create_task(read_ws_and_forward())

    done, pending = await asyncio.wait([task1, task2], return_when=asyncio.FIRST_COMPLETED)
    for t in pending:
        t.cancel()

    if proc.returncode is None:
        proc.kill()
    await ws.close()
    return ws

app = web.Application()
app.add_routes(routes)

if __name__ == '__main__':
    port = int(os.getenv('PORT', 8080))
    web.run_app(app, host='0.0.0.0', port=port)
