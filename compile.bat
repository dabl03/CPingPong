@echo off
	gcc PingPong.C -o Proyecto_consola.exe -Wall -ansi -g3 -lpthread -lPDcurses
	strip Proyecto_consola.exe
	echo Eso es todo amigo.
	if not %errorlevel%==0 ( PAUSE )
exit