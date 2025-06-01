@echo off
REM Go up one directory from the location of this script
cd /d "%~dp0.."

REM Find the first .sln file in the directory
for %%f in (*.sln) do (
    start "" "%%f"
    exit /b
)

echo No .sln file found in %cd%
pause