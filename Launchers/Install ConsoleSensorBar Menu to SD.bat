@echo off
setlocal EnableExtensions
cd /d "%~dp0.."

set "SRC=%~dp0..\releases\consolesensorbar-menu.wps"
set "DEFAULT=E:"

if not exist "%SRC%" (
  echo.
  echo   consolesensorbar-menu.wps is not built yet.
  echo   Build with Docker in plugin\ or copy from GitHub releases\.
  echo.
  pause
  exit /b 1
)

set /p "DRIVE=%DEFAULT%  Enter SD card drive letter (with colon, e.g. E:): "
if "%DRIVE%"=="" set "DRIVE=%DEFAULT%"
if "%DRIVE:~-1%"==":" set "DRIVE=%DRIVE%"
if not "%DRIVE:~-1%"==":" set "DRIVE=%DRIVE%:"

set "PLUGINS=%DRIVE%\wiiu\environments\aroma\plugins"
if not exist "%DRIVE%\wiiu" (
  echo.
  echo   Could not find wiiu folder on %DRIVE%
  echo.
  pause
  exit /b 1
)

if not exist "%PLUGINS%" mkdir "%PLUGINS%"

copy /Y "%SRC%" "%PLUGINS%\consolesensorbar-menu.wps"
if errorlevel 1 (
  echo Copy failed.
  pause
  exit /b 1
)

echo.
echo   Installed MENU variant: %PLUGINS%\consolesensorbar-menu.wps
echo   Bar ON on Wii U Menu only. Remove the ALWAYS plugin if you use both.
echo.
pause
