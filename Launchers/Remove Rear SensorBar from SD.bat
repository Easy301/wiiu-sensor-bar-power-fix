@echo off
setlocal EnableExtensions
set "DEFAULT=E:"
set /p "DRIVE=%DEFAULT%  SD drive letter (e.g. E:): "
if "%DRIVE%"=="" set "DRIVE=%DEFAULT%"
if "%DRIVE:~-1%"==":" set "DRIVE=%DRIVE%"
if not "%DRIVE:~-1%"==":" set "DRIVE=%DRIVE%:"

set "PLUGINS=%DRIVE%\wiiu\environments\aroma\plugins"
for %%F in (
  consolesensorbar.wps consolesensorbar-menu.wps consolesensorbar-always.wps
  rearsensorbar-menu.wps rearsensorbar-always.wps
) do (
  if exist "%PLUGINS%\%%F" (
    del "%PLUGINS%\%%F"
    echo Removed %PLUGINS%\%%F
  )
)
pause
