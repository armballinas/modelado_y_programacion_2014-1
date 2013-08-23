El archivo funcads.c contiene las funciones vistas hoy 22 de agosto en el laboratorio de modelado y programación.

El archivo funcads.h contiene las definiciones de estas funciones.

El archivo mainfuncads.c es un main que usa las declaraciones de funcads.h y lee varias líneas de texto de la entrada estándar, con el fin 
de obtener la más grande, para luego imprimirla, para dejar de escribir en el teclado es necesario enviar la señal de EOF, esto en sistemas tipo Unix se puede hacer con la combinación de teclas Ctrl + D.

Solo se encuentran los archivos de código fuente sin compilar, para compilar se hace lo siguiente:

1.- Se compila funcads.c.

		$gcc -c funcads.c -o funcads.o(*)
		
2.- Se compila el mainfuncads.c

		$gcc -c mainfuncads.c -o main.o
		
3.- Se enlazan los códigos objetivos y se crea el ejecutable(la opción -c le dice al compilador que no enlace los códigos fuente**)

		$gcc main.o funcads.o -o main
		
4.- Se ejecuta el ejecutable

		$./main
		
*El .o usualmente significa que el archivo está compilado pero sus funciones externas no están enlazadadas. La o significa que el archivo es un código objeto para otros archivos.
		
**Por enlazar me refiero a encontrar los caminos de archivos de funciones que no estén definidas en el archivo origen, en este caso, las funciones
migetline, copy, están definidas en el archivo funcads.c, por lo que se deben de enlazar a él(saber en dónde se encuentran definidas), por lo que
primero se compila este archivo en funcads.o.

Enlazar es encontrar el camino, así que con la opción -o se le dice al compilador "si no encuentras esta función, no importa, sigue compilando".

En este paso se dice usa ambos códigos objeto y compilalos juntos(enlazándolos) para crear el ejecutable main.
		
