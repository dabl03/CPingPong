#!system/bin/sh
#no se si en linux existe PDcurses
#Si no funciona cambielo por: lncurse
gcc -Wall -lPDcurse -lpthread -ansi -o PingPong PingPong.c
#strip PingPong
exit
