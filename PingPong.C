/**La codificacion de caracteres es: ANSI.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>//struct clock_t, clock_t clock(void);
#include <curses.h>
#include <pthread.h>
#include "recurso_h.h"
#include "presentacion_inicial.h"
#include "./GAME.h"
/******** Este es mi intento del Juego de atary del los años 90°. *******/
void sleep(long int milisegundos){
     clock_t tiempo_futuro=milisegundos+clock();             //Definimos el tiempo proximo para determinar cuando paso un milisegundo.
     while(clock() < tiempo_futuro);                        //Esperamos hasta que el tiempo actual llegue hasta el limite.
}
/***To..Do: Agregar un logo y informacion del jugador.
    Añadir comentarios a las demas funciones y agregarle un color al modo color.
    Añadir una lista de opciones que permita modificar el color de los jugadores.**/
int main(void){
	short cantidad_de_jugadores;                            //1 or 2
	short codigo;                                           //Modo texto or modo Color.
	int nivel_de_difilculta=FACIL;                          //Facil---IMPOSIBLE
	chtype color[4];                                           //Esta variable definirá el color del jugador.
    inicializar_stdsrc();
    for (short i=0;i<3;i++)
        color[i]=A_STANDOUT;
    color[3]=COLOR_PAIR(8);
    while((codigo=presentacion_inicial(&cantidad_de_jugadores,&nivel_de_difilculta,color))!=EXIT){
          bkgd(color[3]);
          if(codigo==MODO_TEXTO)
             bkgd(COLOR_PAIR(8));//Default
          if((codigo=inicio(cantidad_de_jugadores,codigo,nivel_de_difilculta,color))==__ERROR__)
                 return __ERROR__;
          bkgd(color[3]);
    }
	endwin();//Por ultimo reglesamos la consola al modo normal.
	return 0;
}
//Windows:
          //gcc -Wall PingPong.C -o PingPong.exe -lPDcurses -lpthread
//Linux:
        //gcc -Wall PingPong.C -lPDcurses -lpthread -o PingPong.o
