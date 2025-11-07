#!/usr/bin/env bash
set -e

# Instalar Meson y Ninja si no están disponibles
pip install meson ninja

# Crear el directorio de compilación y compilar
meson setup build
meson compile -C build

# Mover el ejecutable a la raíz para que server.py lo encuentre
cp build/main .
