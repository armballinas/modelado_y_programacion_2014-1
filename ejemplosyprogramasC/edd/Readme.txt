Este es un ejemplo de implemntación en listas de C, usando la separación de archivos en cabeceras e implementación.

El archivo funcads.c contiene las funciones vistas hoy 22 de agosto en el laboratorio de modelado y programación.

El archivo list.h contiene las definiciones de una lista ligada.

El archivo main.c es un main que usa las declaraciones de list.h y prueba una lista.

Solo se encuentran los archivos de código fuente sin compilar, para compilar se hace lo siguiente:

1.- Se compila list.c.

		$gcc -c list.c -o list.o
		(*)
		
2.- Se compila el main.c

		$gcc -c main.c -o main.o
		
3.- Se enlazan los códigos objetivos y se crea el ejecutable(la opción -c le dice al compilador que no enlace los códigos fuente**)

		$gcc main.o list.o -o main
		
4.- Se ejecuta el ejecutable

		$./main
		
*El .o usualmente significa que el archivo está compilado pero sus funciones externas no están enlazadadas. La o significa que el archivo es un código objeto para otros archivos.
		
**Por enlazar me refiero a encontrar los caminos de archivos de funciones que no estén definidas en el archivo origen, en este caso, las funciones
migetline, copy, están definidas en el archivo funcads.c, por lo que se deben de enlazar a él(saber en dónde se encuentran definidas), por lo que
primero se compila este archivo en funcads.o.

Enlazar es encontrar el camino, así que con la opción -o se le dice al compilador "si no encuentras esta función, no importa, sigue compilando".

En este paso se dice usa ambos códigos objeto y compilalos juntos(enlazándolos) para crear el ejecutable main.
		
