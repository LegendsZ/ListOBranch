@echo off
REM ======================================================
REM Build the terminal frontend (and the library)
REM ======================================================

echo [INFO] Configuring CMake for terminal build...
cmake -S . -B build -DBUILD_TERMINAL=ON -DBUILD_GUI=OFF

if %errorlevel% neq 0 (
    echo [ERROR] CMake configuration failed.
    exit /b %errorlevel%
)

echo [INFO] Building terminal executable...
cmake --build build --target listobranch_terminal

if %errorlevel% neq 0 (
    echo [ERROR] Build failed.
    exit /b %errorlevel%
)

echo [SUCCESS] Terminal frontend built successfully!
