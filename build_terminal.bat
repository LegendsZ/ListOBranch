@echo off
REM ======================================================
REM Build the terminal frontend (and the library)
REM ======================================================

REM Default: DEBUG off
set LOG_DEBUG=0

REM Parse command line args
for %%A in (%*) do (
    if /I "%%~A"=="--LOG_DEBUG=1" set LOG_DEBUG=1
    if /I "%%~A"=="--LOG_DEBUG=0" set LOG_DEBUG=0
)

echo [INFO] LOG_DEBUG flag set to %LOG_DEBUG%
echo [INFO] Configuring CMake for terminal build...
cmake -S . -B build -DBUILD_TERMINAL=ON -DBUILD_GUI=OFF -DLOB_DEBUG=%LOG_DEBUG%

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
