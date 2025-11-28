@echo off
if not exist build mkdir build
cd build

cmake ..
cmake --build .

if %errorlevel% neq 0 (
    echo BLAD KOMPILACJI
    exit /b %errorlevel%
)

echo.
echo === URUCHAMIANIE APLIKACJI ===
if exist Debug\MergeSortApp.exe (
    Debug\MergeSortApp.exe
) else (
    MergeSortApp.exe
)
pause