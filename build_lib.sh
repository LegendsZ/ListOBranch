#!/bin/bash
# ======================================================
# Build the listobranch library only
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

echo "[INFO] Configuring CMake for listobranch library..."
cmake -S . -B build -DBUILD_TERMINAL=OFF -DBUILD_GUI=OFF -DLOG_DEBUG=$LOG_DEBUG
if [ $? -ne 0 ]; then
    echo "[ERROR] CMake configuration failed."
    exit 1
fi

echo "[INFO] Building listobranch library..."
cmake --build build --target listobranch
if [ $? -ne 0 ]; then
    echo "[ERROR] Build failed."
    exit 1
fi

echo "[SUCCESS] ListOBranch library built successfully!"
