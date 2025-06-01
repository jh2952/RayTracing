@echo off
cd /d "%~dp0..\bin\Debug-windows-x86_64\Application"
echo Rendering image in debug
Application.exe > "%~dp0..\image.ppm"
pause