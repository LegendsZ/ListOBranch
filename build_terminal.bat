@echo off
REM ======================================================
REM Build the terminal frontend (and the library)
REM ======================================================

REM Default: DEBUG off
set LOG_DEBUG=0

REM Parse command line args
:parse_args
if "%~1"=="" goto args_done
if /I "%~1"=="--LOG_DEBUG=1" set LOG_DEBUG=1
if /I "%~1"=="--LOG_DEBUG=0" set LOG_DEBUG=0
shift
goto parse_args
:args_done

echo [INFO] LOG_DEBUG flag set to %LOG_DEBUG%

echo [INFO] Configuring CMake for terminal build...
cmake -S . -B build -DBUILD_TERMINAL=ON -DBUILD_GUI=OFF -DLOG_DEBUG_MODE=%LOG_DEBUG%

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
