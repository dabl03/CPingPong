/**La codificacion de caracteres es: ANSI.*/
#ifndef recurso_h
	#define recurso_h
	/**
		Bienvenido a mi fichero de recurso. Aqui defino muchas macros que seran usadas por todo el programa y tambien defino los prototipos de muchas funciones. Algunas funciones las contrui aqui y otras en los arhivos donde se usan.
		Estas son las funciones que defino aqu?
		void inicializar   //Inicializo: curses.h
		int tratarkey      //Trato el codigo ANSI de las teclas.
		void tratarCoords  //Trato las coordenadas y verifico las iteraciones.
		void dibujar_pelota//Dibujo la pelota
		void boot          //Esto determina la direccion de la pelota y determina si el jugador debe moverse para arriba o para abajo.
		void sleep         //Esta funcion determina el retraso que se debe hacer. Acepta long int.
		void *pedir_tecla  //Esta funcion sera usada en un hilo aparte.
		int pause          //Si el jugador preciono pausa.
		void crearMarcos   //Creo el marco del juego.
		void draw          //Dibujo la informacion de los personajes.
	*/
	//Gran parte de mis calculo se basa en estas constantes.
	#define MIN_X 2
	#define MIN_Y 5
	#define MAX_WIDTH 100
    #define MAX_HEIGHT 40
	#define MAX_X (MAX_WIDTH-2)
	#define MAX_Y (MAX_HEIGHT-2)
	//Estas constantes son para indicar si es solo un jugador o dos.
	#define UN_JUGADOR 1
	#define DOS_JUGADORES 2
	//si el juego debe dibujarse en modo texto o a color.
	#define MODO_COLOR 0
	#define MODO_TEXTO 1
	//Dificulta del juego
	#define FACIL 42
	#define NORMAL 25
	#define DIFICIL 20
	#define EXPERTO 17
	#define IMPOSIBLE 0
	//Teclas del jugador
	#define a__ARRIBA_W__a 87
	#define a__ARRIBA_w__a 119
	#define a__ABAJO_S__a 83
	#define a__ABAJO_s__a 115
	#define a__ARRIBA__a 259
	#define a__ABAJO__a 258
	#define a__IZQUIERDA__a 260
	#define a__IZQUIERDA_a_a 97
	#define a__IZQUIERDA_A_a 65
	#define a__DERECHA__a 261
	#define a__DERECHA_d_a 100
	#define a__DERECHA_D_a 68
	#define a__PAUSA__a 112
	#define a__PAUSA_P_a 80
	#define a__QUIT__a 113
	#define a__QUIT_Q_a 81
	#define a__INTRO__a 13
	#define a__KEY_PRESS__a 459
	#define a__SPACE__a 32
	
	//Entidades booleanas mas error.
	#define __TRUE__ 1
	#define __FALSE__ 0
	#define __ERROR__ -1
	#define CLEAR_SCREEN erase()
	typedef struct{
		int x;																								// Coords "x" of screen.
		int y;																								// Coords "y" of screen
		int anterior_x;//La coordenada anterior x de la pantalla.                                          //Para los jugadores no es necesaria.
		int anterior_y;																						//La coordenada anterior y de la pantalla.
		short modo_texto;
		chtype color;//El color del jugador.
	}coords;
	typedef struct{
		int vida;/*** The life of game*/
		long int puntaje;/*** La puntuación del jugador.*/
		char* name;/*** Id of games */
		short height;/**Height del jugador.**/
		coords cords;/*** The coords of person*/
		void draw(){
             if(cords.modo_texto){//Modo solo texto.
                for (short h=0;h<height;h++){
                    mvaddch(cords.anterior_y-h,cords.x,' ');
                    mvaddch(cords.anterior_y+h,cords.x,' ');
                 }
                for (short h=0;h<height;h++){
                    mvaddch(cords.y-h,cords.x,'|');
                    mvaddch(cords.y+h,cords.x,'|');
                 }
                cords.anterior_y=cords.y;
             }else{
                 attroff(cords.color);//Nos aseguramos de que alguna otra instruccion tenga el resaltado esendido y si es as?o apagamos.
                 for (short h=0;h<height;h++){
                    mvaddch(cords.anterior_y-h,cords.x,' ');
                    mvaddch(cords.anterior_y+h,cords.x,' ');
                 }
                 cords.anterior_y=cords.y;//Obtenemos las coordenadas anterior para saber donde borrar.
                 attron(cords.color);//Prendemos el resaltado para dibujar.
                 for (short h=0;h<height;h++){
                     mvaddch(cords.y-h,cords.x,'1');
                     mvaddch(cords.y+h,cords.x,'1');
                 }
                 attroff(cords.color);//Apagamos el resaltado para el proximo sicro
             }
        }
	}person;
		#ifdef __WIN32 																						//Si es Windows
			#define CAMBIAR_TITULO system("title Ping Pong de consola.:)")/*Le cambiamos el titulo a la ventana.*/
																											//#elif __unix__ //En un futuro estará disponible.
		#elif __linux__
              /*Hacemos nuestro propio comando de escape para cambiar el titulo de la stdscr en bash:*/
	          #define CAMBIAR_TITULO system("echo -e \"\\033]0;title Ping Pong de consola.\\007\" ")/*Le cambiamos el titulo a la ventana.*/
																											/*Si no funciona puede cambiarlo por esto:*/
	                          //#define CAMBIAR_TITULO system("echo \"\\[\\e]2;title Ping Pong de consola.\\a\\ \"")
	                                                                                                         /*Si no funciona puedes cambiarlo a esto*/
                             //#define CAMBIAR_TITULO system("PS1=\"\\[\\e]2;title Ping Pong de consola.\\a\\ \"")
																											//#elif __Apple__		//En un futuro pienso hacerlo compatible con esto.
	#endif
    int get_nivel(int case_facil,int case_medio,int case_dificil,int case_experto,int case_imposible,const int nivel_de_dificulta){
        switch(nivel_de_dificulta){
            case FACIL:
                 return case_facil;
            case NORMAL:
                 return case_medio;
            case DIFICIL:
                 return case_dificil;
            case EXPERTO:
                 return case_experto;
            case IMPOSIBLE:
                 return case_imposible;
        }
        return ERR;
    }
    char inicializar_stdsrc(){
        char si_colores='N';//(si_colores=='Y')?Este juego tiene soporte para color.:Este juego no tiene color.
	    initscr();
	    if (has_colors()){
           //Inicializamos los colores.
	       si_colores='Y';
           start_color();//Activamos los colores en la consola.:)
           init_pair(2,COLOR_RED,COLOR_RED);
           init_pair(3,COLOR_GREEN,COLOR_GREEN);
           init_pair(4,COLOR_BLUE,COLOR_BLUE);
           init_pair(5,COLOR_CYAN,COLOR_CYAN);
           init_pair(6,COLOR_MAGENTA,COLOR_MAGENTA);
           init_pair(7,COLOR_YELLOW,COLOR_YELLOW);
           init_pair(8,COLOR_WHITE,COLOR_BLACK);
           
           /**To...Do: Hacer las paletas personalizada. Recuerda: Para saber si la consola tiene soporte para una paleta personalizada usar la funcion can_change_color()*/
        }
        cbreak();                              //Queremos que la ventana reconosca la teclas y la envie por la funcion: getch()
	    init_pair(1,COLOR_WHITE,COLOR_GREEN);
        keypad(stdscr,TRUE);                  //Nesecitamos que esté en FALSE para que detenga el hilo creado y así evitar errores.
	    noecho();                             //No queremos eco de las teclas presionadas.
        nonl();                              //No se que hace pero provee un buen resultado.
	    curs_set(0);						//QUITAMOS LA VISIBILIDAD DEL CURSOR DE LA VENTANA.
	    resize_term(MAX_HEIGHT,MAX_WIDTH);/// Para cambiar el tamano de la ventana: int resize_term(int y, int x);
	    nodelay(stdscr,FALSE);
        CAMBIAR_TITULO;                                                                                     //Le cambiamos el titulo a la terminal.
        return si_colores;
    }
    int pause(int* key_codes){
        *key_codes=0;//No queremos que se termine apenas precionemos "p"
        clear();
        mvprintw(MAX_Y/2,MAX_X/3,"Precione Enter, intro o espacio para seguir.");
        refresh();
        while(1)
             switch(*key_codes){
                   case a__INTRO__a:
                   case a__KEY_PRESS__a:
                   case a__SPACE__a:
                        goto end;
             }
        end:
        *key_codes=0;
        return *key_codes;
    }
    void mv_at_printw(int y,int x,chtype color,const char* text){
         attron(color);//Prendemos el resaltado con el color especificado.
         mvprintw(y,x,"- %s",text);//Escribimos el texto con el resaltado esendido.
         attroff(color);//Apagamos el resaltado.
    }
   	void inicializar(person* p,short height,int x,int y,int vida,chtype color,int puntaje,char* name,short modo_texto);	//Aquí inicializaré la estructura person.
	int tratarkey(person* jugador_1,person* jugador_2,short cantidad_de_jugadores,int _key_codes_);			//Aquí trataré la tecla para mover al personaje.
	void tratarCoords(person* p1,person* p2,coords* pong,short indicar[ ],short boot,const int scoore,const int nivel_de_dificulta);//Aquí se trata la posicion de la pelota. Manipularé su coordenadas para hacer que se mueva. Tambien trataré su interacciones con el tablero y los personajes.**/
	void dibujar_pelota(coords* pong);                 														//Aqui dibujaré a los jugadores y la pelota en modo texto.
	void boot(person* p2,short indicar[ ]);																	//Aquí si es un solo jugador esta funcion determinará donde esta la pelota y deacuerdo a ello se moverá
	void sleep(long int milisegundos);
	void *pedir_tecla(void* argv);
	void crearMarcos(short modo_texto);
	void draw(const person p1,const person p2,const int nivel_de_dificulta);
#endif
