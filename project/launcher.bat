setlocal
set PYTHONPATH=%PYTHONPATH%;..\source\Game\scripts
set RESOURCEPATH=%RESOURCEPATH%;..\resources
cmake --build .
Debug\Core.exe

pause