@echo off
REM ======================================================
REM Build the listobranch library only
REM ======================================================

echo [INFO] Configuring CMake for listobranch library...
cmake -S . -B build -DBUILD_TERMINAL=OFF -DBUILD_GUI=OFF

if %errorlevel% neq 0 (
    echo [ERROR] CMake configuration failed.
    exit /b %errorlevel%
)

echo [INFO] Building listobranch library...
cmake --build build --target listobranch

if %errorlevel% neq 0 (
    echo [ERROR] Build failed.
    exit /b %errorlevel%
)

echo [SUCCESS] listobranch library built successfully!
