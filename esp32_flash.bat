@echo off
echo ===============================
echo ESP32 Auto Compile and Flash
echo ===============================

set PORT=COM6
set FQBN=esp32:esp32:esp32
set SKETCH=uart_loopback

arduino-cli.exe compile --fqbn %FQBN% %SKETCH%
IF ERRORLEVEL 1 (
  echo Compile failed
  pause
  exit /b
)

arduino-cli.exe upload -p %PORT% --fqbn %FQBN% %SKETCH%
IF ERRORLEVEL 1 (
  echo Upload failed
  pause
  exit /b
)

echo DONE SUCCESSFULLY
pause
