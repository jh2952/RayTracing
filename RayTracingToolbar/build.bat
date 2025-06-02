@echo off
cd /d "%~dp0.."
echo Generating Visual Studio 2022 project files...
premake5 vs2022
pause