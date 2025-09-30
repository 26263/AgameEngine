
del /f /q "AgameEngine.sln"
rd /s /q "bin"
rd /s /q "bin-int"
echo "Deleted old .sln,bin/,bin-int/"
call vendor\bin\premake\premake5.exe vs2017
PAUSE