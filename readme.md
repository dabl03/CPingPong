/**La codificacion de caracteres es: ANSI.*/
 #        Console Ping Pong       #
<h2>Instroduccion:</h2>
 <p> Este juego se basa en un antiguo juego de consola. Esta hecho con la falidad de pasar un rato divirtiendose con la consola.<br/></p>
<h2>Como compilarlo:</h2>
<p>
   Estoy intentando de que sea facil de configurar y ejecutar.<br/>
   Utilizo preprocesores para identificar el sistema operativo.<br/>
   Deberia poder ejecutar el programa sin ploblema solo con descargar la biblioteca curses debe compilar main y el compilador se encargar  del resto.<br/>
   Uso PDcurses y pthread por lo que debes linkearlo al compilador:<br/>
   <pre><codes> -lPDcurses -lpthread </codes></pre>
   En windows el comando completo quedaria asi:
   <pre><codes>  gcc -Wall PingPong.c -o PingPong.exe -lpthread -lPDcurses </codes></pre>
   En Linux no se. No he tenido la suerte de tener a mi disposición un sistema operativo GNU/LINUX por lo que no se como se compilaria aquí. Pero por suerte curses esta disponible tambien para GNU/LINUX.<br/>
   Tambien dejo un archivo *.bat y un archivo bash que llamaran al copilador y compilara el archivo para despues poder jugarlo. Su nombre es: compile.bat(Solo para windows) y *.sh(Solo para GNU/LINUX, NOTA:No se si sirve.)<br/>
   <ul>
       <li>
           <pre><codes>compilar.sh //Este sirve para compilar en version de Linux.</codes></pre>
       </li>
       <li>
           <pre><codes>compile.bat //Este sirve para compilar en version de Windows.</codes></pre>
       </li>
   </ul>
   En el de Linux puede que no funcione. No tengo GNU/LINUX para provarlo.<br/>
   Si en compilar.sh te trae ploblemas puedes cambiar la parte:
    <pre><codes>-lPDcurses</codes></pre>
     por
    <pre><codes>-lncurses o -lcurses</codes></pre>
    Los dos archivos pueden que no funcionen. Necesitas tener el compilador gcc en las variables de sistema para que funcionen, en caso contrario replacen gcc por el compilador y la ruta de la carpeta.
</p>
<h2>Como ejecutarlo:</h2>
<p>
   Para jugarlo solo debe elegir iniciar el juego, la cantidad de jugadores y listo.<br/>
   Tambien coloque una opcion para saber como jugarlo. Que tecla debo usar y todo lo demas.
</p>
<h2>¿Que debo saber?.</h2>
<p>El juego trae 3 encabezados:
   <ul>
       <li>
          presentacion_inicial.h o menu principal. Aqui dibuja toda la precentacion que el usuario verá en el menú de inicio.
       </li>
       <li>
          GAME.h Ya aqui se dibujará el juego y los jugadores.
       </li>
       <li>
          recurso_h.h Es la ultima pero no la menos importante:
          <ul>
              <li>
                  Aqui defino gran parte del las macros usadas en el juego.
              </li>
              <li>
                   Dos estructuras grobales.
              </li>
              <li>
                  Algunas funciones.
              </li>
              <li>
                   Los prototipos de las funciones usadas por la funcion inicio y pedir_tecla del encabezado: GAME.h.
              </li>
          </ul>
      </li>
   </ul>
   El juego tiene 4 niveles de dificulta que cambiara la cantidad de vida del jugador y los puntos que recive o pierde. Esos niveles son:
      <ol>
          <li>
	      Facil. Son 10 de vidas y 100 de puntos tiene un retraso de 42 milisegundos.
          </li>
          <li>
	      Medio. Son 5 de vidas y 150 de puntos tiene un retraso de 25 milisegundos.
          </li>
          <li>
	      Dificil. Son 3 de vidas y 250 de puntos tiene un retraso de 20 milisegundos.
          </li>
          <li>
	      Experto. Son 2 de vidas y 350 puntos tiene un retraso de 17 milisegundos.
          </li>
          <li>
	      Imposible. Son 100 de vida y 100000 de puntos. Este modo es un chiste. Porque le quite todo el retraso a la pelota.
          </li>
      </ol>
</p>
<h1>CREO QUE ESO ES TODO AMIGO.:)</h1>
