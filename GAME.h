/**La codificacion de caracteres es: ANSI.*/
#ifndef GAME_H
	#define GAME_H
	void *pedir_tecla(void* argv){
        void* todo[6]={((void**)argv)[0],((void**)argv)[1],((void**)argv)[2],((void**)argv)[3],((void**)argv)[4]};
        person* p1;
        person* p2;
        int* _key_codes_;
        short* GAME_OVER;
        short* cantidad_de_jugadores;
        p1=(person*)todo[0];
        p2=(person*)todo[1];
        _key_codes_=(int*)todo[2];
        GAME_OVER=(short*)todo[3];
        cantidad_de_jugadores=(short*)todo[4];
        //Dibujamos a los jugadores.
        p1->draw();
	    p2->draw();
	    while(*GAME_OVER!=a__QUIT__a && *GAME_OVER!=a__QUIT_Q_a && p1->vida > 0 && p2->vida > 0){
	    	*_key_codes_=getch();
	    	*GAME_OVER=tratarkey(p1,p2,*cantidad_de_jugadores,*_key_codes_);
	    	sleep(1);
	    	//usleep(1);
        }
     	return NULL;
    }
    int inicio(const short cantidad_de_jugadores,const short modo_texto,const int nivel_de_dificulta,chtype color[4]){
	    pthread_t tid;
   	    pthread_attr_t attr;
        person jugador_1,jugador_2;
 //void inicializar(person* p,short height,int x,int y,      int vida,            chtype color,int puntaje,char* name,short modo_texto);
		inicializar(&jugador_1,2,MIN_X,MAX_Y/2,get_nivel(10,5,3,3,100,nivel_de_dificulta),color[0],0,(char*)"Jugador 1 .",modo_texto);	//INICIALIZAMOS EL JUGADORES.
		inicializar(&jugador_2,2,MAX_X,MAX_Y/2,get_nivel(10,5,3,3,100,nivel_de_dificulta),color[1],0,(char*)"Jugador 2 .",modo_texto); //INICIALIZAMOS EL JUGADORES.
        coords pong={MAX_X/2,MAX_Y/2,0,-4,modo_texto,color[2]};	       		     										// INCIALIZAMOS PONG
		short indicar[2]={0,1};					/*Es para saber si la pelota debe moverse arriba o abajo, izquierda o derecha.*/
		int _key_codes_=0;
		short GAME_OVER=0;
		int scoore;
		const void* todo[5]={
        &jugador_1,
        &jugador_2,
        &_key_codes_,
        &GAME_OVER,
        &cantidad_de_jugadores
        };
        //Iniciamos lo necesario para crear el hilo.
	    pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
        if(pthread_create(&tid,&attr,pedir_tecla,(void*)todo)){//Si al momento de crear el hilo hubo un error: Nesecitamos reglesar la consola en modo normal y terminar el programa.
          endwin();
          return __ERROR__;
        }
        scoore=get_nivel(100,150,250,350,100000,nivel_de_dificulta);
        clear();
        crearMarcos(modo_texto);
		draw(jugador_1,jugador_2,nivel_de_dificulta);
		do{
			tratarCoords(&jugador_1,&jugador_2,&pong,indicar,cantidad_de_jugadores,scoore,nivel_de_dificulta);
			if (cantidad_de_jugadores==UN_JUGADOR)																	//El boot jugando.
				boot(&jugador_2,indicar);
			dibujar_pelota(&pong);
			if (GAME_OVER==a__PAUSA__a){
			   pause(&_key_codes_);
               clear();
               crearMarcos(modo_texto);
        	   draw(jugador_1,jugador_2,nivel_de_dificulta);
           }
			sleep(nivel_de_dificulta);
			refresh();

		}while(jugador_1.vida>0 && jugador_2.vida>0 && GAME_OVER!=a__QUIT__a);
		nodelay(stdscr,TRUE);
        sleep(100);
        nodelay(stdscr,FALSE);
    	GAME_OVER=1;
		return a__QUIT__a;																						//Si el jugador presionó la tecla salir.
	}
	void inicializar(person* p,short height,int x,int y,int vida,chtype color,int puntaje,char* name,short modo_texto){
		p->vida=vida;
		p->puntaje=puntaje;
		p->name=name;
		p->height=height;
		p->cords.modo_texto=modo_texto;
		p->cords.x=x;
		p->cords.y=y;
		p->cords.color=color;
		//Indico que no hay una cordenada anterior.
			//p->cords.anterior_x=-1;//No es necesario iniciarlo.
			p->cords.anterior_y=-4;
	}
	int tratarkey(person* jugador_1,person* jugador_2,short cantidad_de_jugadores,int _key_codes_){
		switch (_key_codes_){																					//Mediante código ASSI vemos que tecla presionó el usuario. Nota: Todos los caracteres será mayusculas.
			case a__ARRIBA_w__a:
            case a__ARRIBA_W__a:
				if(jugador_1->cords.y>=MIN_Y)
					jugador_1->cords.y-=1;
				else if (jugador_1->cords.y==MIN_Y)
					jugador_1->cords.y=MAX_Y-1;
				jugador_1->draw();//Solo dibujamos a los jugadores si el usuario preciono la tecla correspondiente.
				break;
			case a__ABAJO_s__a:
			case a__ABAJO_S__a:
				if(jugador_1->cords.y<=MAX_Y)
					jugador_1->cords.y+=1;
				else if(jugador_1->cords.y==MAX_Y)
					jugador_1->cords.y=MIN_Y+1;
				jugador_1->draw();//Solo dibujamos a los jugadores si el usuario preciono la tecla correspondiente.
				break;
			case a__ARRIBA__a:
				if (cantidad_de_jugadores==UN_JUGADOR)
					break;
				if (jugador_2->cords.y>MIN_Y)
					jugador_2->cords.y--;
				jugador_2->draw();//Solo dibujamos a los jugadores si el usuario preciono la tecla correspondiente.
				break;
			case a__ABAJO__a:
				if (cantidad_de_jugadores==UN_JUGADOR)
					break;
				if (jugador_2->cords.y<MAX_Y)
					jugador_2->cords.y++;
				jugador_2->draw();//Solo dibujamos a los jugadores si el usuario preciono la tecla correspondiente.
				break;
			case a__PAUSA__a:
            case a__PAUSA_P_a:
				return a__PAUSA__a;
			case a__QUIT__a:
            case a__QUIT_Q_a:
				return a__QUIT__a;
		}
		return 0;
	}
    
	void tratarCoords(person* p1,person* p2,coords* pong,short indicar[ ],short boot,const int scoore,const int nivel_de_dificulta){
         if (indicar[0])
		   	pong->x++;																						//pong->x+=derecha
         else
		       	pong->x--;																					//pong->x+=Izquierda
		 if (indicar[1])
		      pong->y++;																					//pong->y+=abajo
		 else
		      pong->y--;																					//pong->y+=arriba;
																											//Si la pelota choca contra el techo o suelo: rebota
         if (pong->y>=MAX_Y-1)
		    indicar[1]=__FALSE__;
         else if (pong->y<=MIN_Y+1)
			 indicar[1]=__TRUE__;
        switch (pong->x){
			//case la pelota choca contra la raqueta: rebota:
				case (MIN_X+1):
					if (p1->cords.y+p1->height > pong->y && p1->cords.y-p1->height < pong->y){																//rebota
					    p1->puntaje+=scoore;
                    	indicar[0]=__TRUE__;
			            draw(*p1,*p2,nivel_de_dificulta);
                    }
                    break;
				case (MAX_X-1):
					if (p2->cords.y+p2->height > pong->y && p2->cords.y-p2->height < pong->y){																//Rebota
					    p2->puntaje+=scoore;
                    	indicar[0]=__FALSE__;
		             	draw(*p1,*p2,nivel_de_dificulta);
                     }
                	break;
				//break;
			//case la pelota choca contra la barrera
				case MIN_X:																					//Jugador uno pierde una vida.
					p1->vida--;
					p1->puntaje-=scoore;
					indicar[0]=__TRUE__;
					pong->x=MAX_X/2;
		         	draw(*p1,*p2,nivel_de_dificulta);
					break;
				case MAX_X:																					//Jugador dos pierde una vida.
					if (boot==DOS_JUGADORES){
						p2->vida--;
						p2->puntaje-=scoore;
						pong->x=MAX_X/2;
			            draw(*p1,*p2,nivel_de_dificulta);
					}
					indicar[0]=__FALSE__;
					
					break;
				//break;
		}

	}
	void boot(person* p2,short indicar[ ]){
		if(indicar[1])
			p2->cords.y++;
		else
			p2->cords.y--;
		p2->draw();
	}

	void dibujar_pelota(coords* pong){
        //Dibujamos la pelota
        if(pong->modo_texto){
           mvaddch(pong->anterior_y,pong->anterior_x,' ');															//Borramos la pelota.
		   mvaddch(pong->y,pong->x,'O');
        }else{
           attroff(pong->color);
           mvaddch(pong->anterior_y,pong->anterior_x,' ');															//Borramos la pelota.
           attron(pong->color);
           mvaddch(pong->y,pong->x,'O');
           attroff(pong->color);
        }
        pong->anterior_x=pong->x;   																				//Dibujamos la pelota
        pong->anterior_y=pong->y;
	}
	void crearMarcos(short modo_texto){//Creamos nuestro marco.:)
	    int x,y=MIN_Y;
	    if(!modo_texto)
            attron(A_STANDOUT);
		for (int ini=1;ini<=2;ini++){
			for(x=MIN_X;x<MAX_X;x++)
				mvaddch(y,x,'_');
			y=MAX_Y;
		}
		x=MIN_X-1;
		for(int ini=1;ini<=2;ini++){
			for (y=0;y<MAX_Y;y++)
				mvaddch(y,x,'|');
			x=MAX_X+1;
		}
		if(!modo_texto)
            attroff(A_STANDOUT);
	}
	void draw(const person p1,const person p2,const int nivel_de_dificulta){
         for (int y=0;y<MIN_Y;y++)
             for (int x=0;x<=MAX_X;x++)
                 mvaddch(y,x,' ');
         const char* texto[]={"Vida del jugador %d es: %d","Puntaje del jugador %d es: %d"};
         const char* nivel[]={"Facil.","Normal.","Dificil.","Experto.","Imposible."};
         int width[2]={MIN_X,MAX_X-30};
         int datos[INDICE_DE_LISTA(texto)][2]={{p1.vida,p2.vida},{p1.puntaje,p2.puntaje}};
         for (short y=0;y<2;y++)
              for (short x=0;x<2;x++)
                  mvprintw(y,width[x],texto[y],x+1,datos[y][x]);
         mvprintw(MIN_Y-1,MAX_WIDTH/3,"  Nivel: %s",nivel[get_nivel(0,1,2,3,4,nivel_de_dificulta)]);
    }
#endif
