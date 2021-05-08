/**La codificacion de caracteres es: ANSI.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*struct clock_t, clock_t clock(void);*/
#include <curses.h>
#include <pthread.h>
#include "recurso_h.h"
#include "presentacion_inicial.h"
#include "./GAME.h"
/******** Este es mi intento del Juego de atary del los a�os 90�. *******/
/***Debo Agregar un logo y informacion del jugador.
    A�adir una lista de opciones que permita modificar el color de los jugadores.**/
int main(void){
	short cantidad_de_jugadores;                            /*1 or 2*/
	short codigo;                                           /*Modo texto or modo Color.*/
	short i;
    int nivel_de_difilculta=FACIL;                          /*Facil---IMPOSIBLE*/
	chtype color[4];                                           /*Esta variable definir� el color del jugador.*/
    
    inicializar_stdsrc();
    for (i=0;i<3;i++)
        color[i]=A_STANDOUT;
    color[3]=COLOR_PAIR(8);
    while((codigo=presentacion_inicial(&cantidad_de_jugadores,&nivel_de_difilculta,color))!=EXIT){
          bkgd(color[3]);
          if(codigo==MODO_TEXTO)
             bkgd(COLOR_PAIR(8));/*Default*/
          if((codigo=inicio(cantidad_de_jugadores,codigo,nivel_de_difilculta,color))==__ERROR__)
                 return __ERROR__;
		  bkgd(color[3]);
    }
	endwin();/*Por ultimo reglesamos la consola al modo normal.*/
	return 0;
}
/*
Windows:
        gcc -Wall PingPong.c -o PingPong.exe -lPDcurses -lpthread
Linux:
        gcc -Wall PingPong.c -lPDcurses -lpthread -o PingPong.o
*/
