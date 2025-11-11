ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
N = len(ALPHABET)  # 62 símbolos

def byte_to_base62(b: int) -> str:
    """Convierte un byte (0–255) a 2 caracteres base62"""
    return ALPHABET[b // N] + ALPHABET[b % N]

def base62_to_byte(s: str) -> int:
    """Convierte 2 caracteres base62 de vuelta a un byte"""
    return ALPHABET.index(s[0]) * N + ALPHABET.index(s[1])

def encrypt(message: str, key: str) -> str:
    key_bytes = key.encode("utf-8")
    key_len = len(key_bytes)
    encrypted = []

    for i, b in enumerate(message.encode("utf-8")):
        c = (b + key_bytes[i % key_len]) % 256
        encrypted.append(byte_to_base62(c))

    return "".join(encrypted)

def decrypt(ciphertext: str, key: str) -> str:
    key_bytes = key.encode("utf-8")
    key_len = len(key_bytes)
    decrypted_bytes = []

    for i in range(0, len(ciphertext), 2):
        c = base62_to_byte(ciphertext[i:i+2])
        b = (c - key_bytes[(i//2) % key_len]) % 256
        decrypted_bytes.append(b)

    return bytes(decrypted_bytes).decode("utf-8")


# ======================
# Ejemplo de uso
# ======================
if __name__ == "__main__":
    clave = "clave_ejemplo"
    mensaje = "Ejemplo"
    cifrado = encrypt(mensaje, clave)
    print("Cifrado:", cifrado)

    descifrado = decrypt(cifrado, clave)
    print("Descifrado:", descifrado)
