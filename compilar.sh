#!system/bin/sh
#no se si en linux existe PDcurses
#Si no funciona cambielo por: lncurse
gcc -Wall -lPDcurse -lpthread -ansi -g3 -o Proyecto_consola PingPong.C
exit
