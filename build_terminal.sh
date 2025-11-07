#!/bin/bash
# ======================================================
# Build the terminal frontend (and the library)
# ======================================================

# Default: DEBUG off
LOG_DEBUG=0

# Parse command line args
for arg in "$@"; do
    if [[ "$arg" == "--debug" ]]; then
        LOG_DEBUG=1
    fi
done

echo "[INFO] LOG_DEBUG flag set to $LOG_DEBUG"

echo "[INFO] Configuring CMake for terminal build..."
cmake -S . -B build -DBUILD_TERMINAL=ON -DBUILD_GUI=OFF -DLOG_DEBUG=$LOG_DEBUG
if [ $? -ne 0 ]; then
    echo "[ERROR] CMake configuration failed."
    exit 1
fi

echo "[INFO] Building terminal executable..."
cmake --build build --target listobranch_terminal --config Debug
if [ $? -ne 0 ]; then
    echo "[ERROR] Build failed."
    exit 1
fi

echo "[SUCCESS] Terminal frontend built successfully!"
