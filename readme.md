/**La codificacion de caracteres es: ANSI.*/
 #        Console Ping Pong       #
 -----------------------------------
                Instroduccion:
---------------------------------------------
        Este juego se basa en un antiguo juego de consola. Esta hecho con la finalidad de apartarse un poco de la interfaces visuales moderna y hacercarse un poco a la antigua interfaces de consola.
---------------------------------------------
                Como compilarlo:
---------------------------------------------
        Estoy intentando de que sea facil de configurar y ejecutar.
        Utilizo preprocesores para identificar el sistema operativo.
        Deberia poder ejecutar el programa sin ploblema solo con compilar main y el compilador se encargar  del resto.
        Uso PDcurses y pthread por lo que debes linkearlo al compilador:
            -lPDcurses -lpthread
        En windows el comando completo quedaria asi:
                   gcc -Wall PingPong.C -o PingPong.exe -lpthread -lPDcurses
        En Linux no se:?
        Tambien dejo un archivo *.bat que llamara al copilador y compilara el archivo para despues poder jugarlo. Su nombre es: compile.bat
		Tambien deje dos archivos:
		- compilar.sh //Este sirve para compilar en version de Linux.
		- compile.bat //Este sirve para compilar en version de Windows.
		En el de Linux puede que no funcione. No se mucho sobre bash.
		Si en compilar.sh te trae ploblemas puedes cambiar la parte -lPDcurses por -lncurses.
		Los dos archivos pueden que no funcionen. Necesitas tener el compilador gcc en las variables de sistema para que funcionen, en caso contrario replacen gcc por el compilador y la ruta de la carpeta.
----------------------------------------------
                Como ejecutarlo:
----------------------------------------------
Para jugarlo solo debe elegir iniciar el juego, la cantidad de jugadores y listo.
Tambien coloque una opcion para saber como jugarlo. Que tecla debo usar y todo lo demas.
----------------------------------------------
               Que debo saber?
----------------------------------------------
El juego me presenta problemas y no entiendo de donde probiene.
Al salir del juego a el menu principal varias veces el juego se me daña.
El juego trae 3 encabezados:
    presentacion_inicial.h o menu principal. Aqui dibuja toda la precentacion que el usuario verá.
    GAME.h Ya aqui se dibujará el juego y comenzará todo.
    recurso_h.h Es la ultima pero no la menos importante:
        - Aqui defino gran parte del las macros.
        - Dos estructuras grobales.
        - 3 funciones.
        - Los prototipos de las funciones usadas por la funcion inicio y pedir_tecla del encabezado: GAME.h-.
El juego tiene 4 niveles de dificulta que cambiara la cantidad de vida del jugador y los puntos que recive o pierde. Esos niveles son:
	- Facil. Son 10 de vidas y 100 de puntos tiene un retraso de 42 milisegundos.
	- Medio. Son 5 de vidas y 150 de puntos tiene un retraso de 25 milisegundos.
	- Dificil. Son 3 de vidas y 250 de puntos tiene un retraso de 20 milisegundos.
	- Experto. Son 2 de vidas y 350 puntos tiene un retraso de 17 milisegundos.
	- Imposible. Son 100 de vida y 100000 de puntos. Este modo es un chiste. Porque le quite todo el retraso a la pelota.

	
------------------------------------------------
                CREO QUE ESO ES TODO AMIGO.:)

