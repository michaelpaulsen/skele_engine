@echo off
cls
CALL "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
set lSDL=C:\vclib\sdl\lib\x64
set win32=Shell32
set SDL=C:\vclib\sdl\include
set CPATH=%SDL%;%lSDL%
set windows_is_stupid= /subsystem:windows
set defines=-D win32 -D WINDOWS
set CoreLibDep= -lShell32
clang++ %defines%=1 -L%lSDL% %CoreLibDep% -lSDL2 -lSDL2main -std=c++20 main.cpp -Xlinker %windows_is_stupid%
.\a.exe
rem -lkernel32 -luser32 -lgdi32 -lwinspool -lcomdlg32 -ladvapi32 -lshell32 -lole32 -loleaut32 -luuid -lodbc32 -lodbccp32
