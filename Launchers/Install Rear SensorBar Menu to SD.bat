@echo off
setlocal EnableExtensions
cd /d "%~dp0.."

set "SRC=%~dp0..\releases\rearsensorbar-menu.wps"
set "DEFAULT=E:"

if not exist "%SRC%" (
  echo.
  echo   rearsensorbar-menu.wps is not built yet.
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

copy /Y "%SRC%" "%PLUGINS%\rearsensorbar-menu.wps"
if errorlevel 1 (
  echo Copy failed.
  pause
  exit /b 1
)

echo.
echo   Installed: %PLUGINS%\rearsensorbar-menu.wps
echo.
pause
