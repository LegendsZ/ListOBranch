@echo off
REM ======================================================
REM Build the listobranch library only
REM ======================================================

REM Default: DEBUG off
set LOG_DEBUG=1

REM Parse command line args
for %%A in (%*) do (
    if /I "%%~A"=="--debug" set LOG_DEBUG=1
)

echo [INFO] LOG_DEBUG flag set to %LOG_DEBUG%

echo [INFO] Configuring CMake for listobranch library...
cmake -S . -B build -DBUILD_TERMINAL=OFF -DBUILD_GUI=OFF -DLOG_DEBUG=%LOG_DEBUG%

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

echo [SUCCESS] ListOBranch library built successfully!