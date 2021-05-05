/**La codificacion de caracteres es: ANSI.*/
#ifndef PRESENTACION
	#define PRESENTACION
	#define INDICE_DE_LISTA(x) (sizeof(x)/sizeof(char*))
	#define INICIAR_JUEGO 0
	#define INICIAR_JUEGO_EN_MODO_TEXTO 1
	#define NIVEL_DE_DIFICULTA 2
	#define COLORS 3
	#define INSTRUCCIONES 4
	#define CREDITOS 5
	#define EXIT 6
	#define JUGADOR_1 0
	#define JUGADOR_2 1
	#define PELOTA  2
	#define X_OSC (MAX_X/5)
	#define X_CLARO ((MAX_X/2)+1)
	int dibujar_opciones(const char* list[],int indice,int height,int width);
	short mostrar_y_elejir_colores(const char* personaje,chtype* color_elegido,short fondo);
	int presentacion_inicial(short* cantidad_de_jugadores,int* nivel_de_difilculta,chtype* color){
		const char* list[ ]={
             "Iniciar juego.",
             "Iniciar juego en modo texto.",
             "Nivel de dificulta.",
             "Colores.",
             "Instrucciones.",
             "creditos.",
             "exit."
        };
		const char* list_opciones_incio[]={
             "Un jugador.",
             "Dos jugadores.",
             "    - Reglesar."
        };
		const char* list_difilculta[]={
              "- Facil.",
              "- Normal.",
              "- Dificil.",
              "- Nivel experto.",
              " - Imposible.:)",
              "    - Reglesar."
        };
        const char* instrucciones[ ]={
             "Si eliges solo un jugador entonces estos son los controles:",
             "                 - \"W\" para mover a jugador 1 para arriba.",
             "                 - \"S\" Para mover al jugador 1 hacia abajo.",
             "Para el modo dos jugador estos son los controles:",
             "                 - \"W\" Para mover al jugador uno para arriba.",
             "                 - \"S\" Para mover al jugador 1 para abajo.",
             "                 - \"/|\\\" Para mover al jugador 2 para arriba.",
             "                 - \"\\|/\" Para mover al jugador 2 para abajo.",
             "En los dos modos se admiten estas teclas:",
                   "\"Q\" Para salir.","\"P\" Para pausa.",
                   "Para jugar solo debes mover la raqueta a donde esta la pelota y hacer que la misma rebote. Si la pelota toca la pared:",
                   " ",
                   "Desaparecera la pelota y el jugador perdera una vida y una cantidad de puntos deacuerdo al nivel de dificulta.",
                   " ",
                   "El juego termina si uno de los jugadores pierde todas su vida o si se perciona la tecla \"Q\".",
                   " ",
                   "Para pausar el juego solo debe precionar la letra \"P\" y listo.",
                   "¿Estas aburrido con los colores de la terminal?. No te preocupes agrege una opcion para ti. Solo ve al menu de inicio, entra en la seccion de colores y pulsas la tecla enter y veras tres opciones:",
                   "",
                   "1- Jugador 1. - Esta opcion le cambia la apariencia al jugador 1.",
                   "",
                   "2- Jugador 2. - Esta opcion le cambia la apariencia al jugador 2.",
                   "",
                   "3- Pelota. - Esta opcion le cambia la apariencia a la pelota.",
                   "",
                   "4- Fondo. - Esta opcion es especial. Esta opcion te permitirá cambiar el color del fondo. Pero tiene una limitacion:",
                   "",
                   "                 - No se puede elegir colores oscuros.",
                   "",
                   "Ya a dentro de cualquiera de las tres opciones solo debes mover el cursor con el teclado. Cuando encuentres el color de tu gustos debes precionar la teclas: Intro o espacio y se fijara el color.",
                   "",
                   "Enhora buena. Ya creo que estas preparado para jugar mi juego. Espero que te guste."
        };
        const char* creditos[]={
              "Desarrollado por:",
              "         - Daniel Briceño.",
              "Graficos por:",
              "          - Daniel Briceño.",
              "Libreria usadas:",
              "          - PDcurses: Para los graficos.",
              "          - pthread: Para la creacion y ejecucion de un hilo.",
              "Encabezados usados:",
              "          - <stdio.h>",
              "          - <stdlib.h>",
              "          - <time.h>",
              "          - <pthread.h>",
              "          - <curses.h>",
              "          - \"recurso_h.h\"",
              "          - \"presentacion_inicial.h\"",
              "          - \"./GAME.h\""
        };
        const char* personajes[ ]={"Jugador 1.","Jugador 2.","Pelota.","Fondo.","      - Reglesar."};
        int _key_codes_=0;
		clear();
		while(true){
            switch(dibujar_opciones(list,INDICE_DE_LISTA(list),MAX_HEIGHT/3,MAX_WIDTH/3)){
              case INICIAR_JUEGO:
                 //  mvprintw();
                   switch(dibujar_opciones(list_opciones_incio,INDICE_DE_LISTA(list_opciones_incio),MAX_HEIGHT/3,MAX_WIDTH/3)){
                         case 0:
                              *cantidad_de_jugadores=UN_JUGADOR;
                              return MODO_COLOR;
                         case 1:
                              *cantidad_de_jugadores=DOS_JUGADORES;
                              return MODO_COLOR;
                         case 2:
                              continue;//Re-dibujamos la lista y comenzamos de nuevo.
                   }
                   break;
              case INICIAR_JUEGO_EN_MODO_TEXTO:
                   switch(dibujar_opciones(list_opciones_incio,INDICE_DE_LISTA(list_opciones_incio),MAX_HEIGHT/3,MAX_WIDTH/3)){
                         case 0:
                              *cantidad_de_jugadores=UN_JUGADOR;
                              break;
                         case 1:
                              *cantidad_de_jugadores=DOS_JUGADORES;
                              break;
                         case 2:
                              continue;
                         case EXIT:
                              continue;
                   }
                   return MODO_TEXTO;
          
              case NIVEL_DE_DIFICULTA:
                   switch(dibujar_opciones(list_difilculta,INDICE_DE_LISTA(list_difilculta),MAX_HEIGHT/3,MAX_WIDTH/3)){
                        case 0://FACIL.
                             *nivel_de_difilculta=FACIL;
                             continue;
                        case 1://Normal
                             *nivel_de_difilculta=NORMAL;
                             continue;
                        case 2://Dificil:
                             *nivel_de_difilculta=DIFICIL;
                             continue;
                        case 3://Nivel Experto.
                             *nivel_de_difilculta=EXPERTO;
                             continue;
                        case 4:
                             *nivel_de_difilculta=IMPOSIBLE;
                   }
                   //case 5://Reglesar:
                   continue;
              case COLORS:
                   while(1)
                        if (((_key_codes_=dibujar_opciones(personajes,INDICE_DE_LISTA(personajes),MAX_HEIGHT/3,MAX_WIDTH/3))!=INDICE_DE_LISTA(personajes)-1) && _key_codes_!=EXIT)
                            mostrar_y_elejir_colores(personajes[_key_codes_],&color[_key_codes_],_key_codes_-2);
                        else
                             break;
                   bkgd(color[3]);
                   continue;
              case INSTRUCCIONES:
                   dibujar_opciones(instrucciones,INDICE_DE_LISTA(instrucciones),MIN_X,MIN_Y);
                   continue;
              case CREDITOS:
                   dibujar_opciones(creditos,INDICE_DE_LISTA(creditos),MIN_X,MIN_Y);
                   continue;
              case EXIT:
                   return EXIT;
		}
       }
	}
	
	int dibujar_opciones(const char* list[],int indice,int height,int width){
        int _key_codes_=0;
		short posicion_tecla=0;
		clear();
        mv_at_printw(height,width,A_STANDOUT,list[posicion_tecla]);
		for(int i=1;i<indice;i++){
			mvprintw(i+height,width,"%s",list[i]);//Escribimos las palabras sin resaltado de letras.
		}
		while (1){
            _key_codes_=getch();
			refresh();
            mvprintw(height+posicion_tecla,width,"%s  ",list[posicion_tecla]);//Escribimos sin resaltado el indice anterior para que paresca como si fuera un texto normal.
            switch(_key_codes_){//Tratamos las teclas como queramos.
				case KEY_UP:
                case a__ARRIBA_W__a:
                case a__ARRIBA_w__a:
					posicion_tecla--;
					posicion_tecla=(posicion_tecla<=-1)?indice-1:posicion_tecla;
					break;
				case KEY_DOWN:
                case a__ABAJO_S__a:
                case a__ABAJO_s__a:
					posicion_tecla++;
					posicion_tecla=(posicion_tecla>=indice)?0:posicion_tecla;
					break;
				case a__INTRO__a:
				case a__KEY_PRESS__a:
                case a__SPACE__a:
					return posicion_tecla;
				case a__QUIT__a:
				case a__QUIT_Q_a:
                     return EXIT;
			}
			mv_at_printw(height+posicion_tecla,width,A_STANDOUT,list[posicion_tecla]);
		}
		return ERR;
	}
	void draw_2(chtype color){
       attron(color);
       for (short y=1;y<=3;y++)
           for(short x=10;x<MAX_X-10;x++)
               mvaddch(MIN_Y+y,MIN_X+x,'|');
       attroff(color);
    }
	short mostrar_y_elejir_colores(const char* personaje,chtype* color_elegido,short fondo){
          short cantidad_de_paletas_total_de_colores=0;
          short y=0,x=X_OSC;//Pocicion actual es la de la primera lista y el primer elemento.
          int _key_codes_=0;
          const char* colores_oscuros[]={
                "- Color blanco predeterminado.",
                "- Color rojo oscuro.",
                "- Color verde oscuro.",
                "- Color azul oscuro.",
                "- Color cyan oscuro.",
                "- Color margenta oscuro.",
                "- Color cafe.",
                "- Color negro.",
                "        - Exit."
          };
          const char* colores_claros[]={
                "- Color blanco predeterminado.",
                "- Color rojo claro.",
                "- Color verde claro.",
                "- Color azul claro.",
                "- Color cyan claro.",
                "- Color margenta claro.",
                "- Color amarillo.",
                "- Color negro.",
                "        - Exit."
          };
          chtype paletas[INDICE_DE_LISTA(colores_oscuros)-1];//El tamaño de la matris "colores_oscuros" -1 por exit  debe coincidir con la cantidad de las paletas reservadas.
          chtype paletas_de_colores_claros[INDICE_DE_LISTA(colores_claros)-1];//El tamaño de la matris "colores_claros" -1 por exit  debe coincidir con la cantidad de las paletas reservadas.
          
          cantidad_de_paletas_total_de_colores=INDICE_DE_LISTA(colores_oscuros)-1;
          clear();
          /****To...DO: crear paletas de colores claros y dibujarla aquí.
          Usa la lista ya creada en: C:\C_CPP\Experimentos\Experimentando_con_colores_con_ncurses.c
          */
          mvprintw(MIN_Y,MAX_X/3,"Cambiar el color del personaje: %s",personaje);
          for(unsigned short i=0;i<sizeof(colores_oscuros)/sizeof(char*)-1/**Nota el menos 1 es por exit.**/;i++){
                    if (i==0){
                       paletas[i]=A_STANDOUT;
                       paletas_de_colores_claros[i]=A_STANDOUT;
                       mvprintw(MAX_Y/3+i,X_CLARO,"%s",colores_claros[i]);
                       mv_at_printw(MAX_Y/3+i,X_OSC,paletas[i],colores_oscuros[y]);
                       continue;
                    }
                    paletas[i]=COLOR_PAIR(i+1);
                    paletas_de_colores_claros[i]=COLOR_PAIR(i+1) | A_BOLD;
                    mvprintw(MAX_Y/3+i,X_OSC,"%s",colores_oscuros[i]);
                    mvprintw(MAX_Y/3+i,X_CLARO,"%s",colores_claros[i]);
          }
          mvprintw(MAX_Y/3+sizeof(colores_oscuros)/sizeof(char*)-1,X_OSC,"        - Exit.");
          mvprintw(MAX_Y/3+sizeof(colores_oscuros)/sizeof(char*)-1,X_CLARO,"        - Exit.");
          draw_2(*color_elegido);
          while(1){
               _key_codes_=getch();
               mvprintw(MAX_Y/3+y,X_OSC,"%s  ",colores_oscuros[y]);
               mvprintw(MAX_Y/3+y,X_CLARO,"%s  ",colores_claros[y]);
               switch(_key_codes_){
                     case 'q':
                     case 'Q':
                          return a__QUIT__a;
                     case a__ARRIBA__a:
                     case a__ARRIBA_W__a:
                     case a__ARRIBA_w__a:
                          y=(y<=0)?cantidad_de_paletas_total_de_colores:y-1;
                          break;
                     case a__ABAJO__a:
                     case a__ABAJO_S__a:
                     case a__ABAJO_s__a:
                          y=(y>=cantidad_de_paletas_total_de_colores)? 0 : y+1 ;
                          break;
                     case a__INTRO__a:
                     case a__KEY_PRESS__a:
                     case a__SPACE__a:
                          if(y!=cantidad_de_paletas_total_de_colores){
                             if (fondo)
                                *color_elegido=paletas_de_colores_claros[y];
                             else
                                *color_elegido=(x==X_OSC)?paletas[y]:paletas_de_colores_claros[y];
                             draw_2(*color_elegido);
                          }else{
                              return -1;
                          }
                          break;
                     case a__IZQUIERDA__a:/**Nota: se pone lenta cuando se deja presionado.*/
                     case a__IZQUIERDA_a_a:
                     case a__IZQUIERDA_A_a:
                     case a__DERECHA__a:
                     case a__DERECHA_d_a:
                     case a__DERECHA_D_a:
                          x=(x==X_OSC)?X_CLARO:X_OSC;
                          break;
               }
               if (x==X_OSC){
                  if (y!=cantidad_de_paletas_total_de_colores+1)
                      mv_at_printw((MAX_Y/3)+y,X_OSC,paletas[y],colores_oscuros[y]);
                  else
                      mv_at_printw((MAX_Y/3)+y,X_OSC,paletas[y],colores_oscuros[0]);
               }else{
                  if (y!=cantidad_de_paletas_total_de_colores+1)
                      mv_at_printw((MAX_Y/3)+y,X_CLARO,paletas_de_colores_claros[y],colores_claros[y]);
                  else
                      mv_at_printw((MAX_Y/3)+y,X_CLARO,paletas_de_colores_claros[y],colores_claros[y]);
                     
               }
                    
               refresh();
               
          }
          return 0;
    }
#endif
