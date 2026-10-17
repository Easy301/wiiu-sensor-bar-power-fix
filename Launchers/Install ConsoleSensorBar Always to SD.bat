@echo off
setlocal EnableExtensions
cd /d "%~dp0.."

set "SRC=%~dp0..\releases\consolesensorbar-always.wps"
set "DEFAULT=E:"

if not exist "%SRC%" (
  echo.
  echo   consolesensorbar-always.wps is not built yet.
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

copy /Y "%SRC%" "%PLUGINS%\consolesensorbar-always.wps"
if errorlevel 1 (
  echo Copy failed.
  pause
  exit /b 1
)

echo.
echo   Installed ALWAYS variant: %PLUGINS%\consolesensorbar-always.wps
echo   Bar stays powered in games and menu. Do not install both variants at once.
echo.
pause
