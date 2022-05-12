@echo off

rem Comentarios
rem -L"D:/app/Dev-Cpp/lib" -L"./" --> Path de busca de bibliotecas


g++ -O0 -g3 -Wall -c *.cpp


rem Geracao da Lib
rem del *.a
rem ar r libcanvas2d32.a canvas2d.o
rem ranlib libcanvas2d32.a


rem LINK
g++ -o debug/app.exe     canvas_cpp.o Relogio.o gl_canvas2d.o -L"e:/app/Dev-Cpp/lib" -L"./"  -lglut32 -lglu32 -lopengl32 



