#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define LECTURA "r"
#define ERROR "No se pudo abrir el archivo"

/*Una funcion que intenta abrir el archivo de nombre cad
	*Devuelve un apuntador a archivo si lo consigue o termina el programa imprimiendo un mensaje
	de error en otro caso
*/
FILE *abreArchivo(const char *cad); 

/*main del programa*/
int main(){	
	char entrada = 1; //si queremos que se lea de entrada estandar poner un uno
	FILE *ar;
	if(entrada){
		ar = stdin;
	}
	else{
		ar = abreArchivo("prueba.txt");//abro el archivo
	}
		
	int vertices = 0;
	int i;
	int x,y;
	float radio;
	do{//mientras haya mas casos de prueba
		fscanf(ar,"%d", &vertices);//leo el numero de vertices
		printf("Quieres %d vertices\n",vertices);//los prints se deben quitar
		i = 0;
		for(i=0;i<vertices;i++){//leo los vertices pedidos
			fscanf(ar,"%d %d",&x,&y);//leo la pareja de puntos
			//aqui va el procesamiento de los puntos(guardarlos, etc)
			printf("el punto es: (%d,%d)\n",x,y); //solo la imprimo
		}
		if(vertices){//si hay vertices tengo que leer el tamaño del radio
			fscanf(ar,"%f",&radio);//leo el radio
			printf("el radio es: %f\n",radio);//quitar
			printf("Termine caso de prueba\n");//quitar
		}
		
	}while(vertices > 0);
	printf("Ya no hay mas casos de prueba\n");//quitar
	return 0;
}

FILE *abreArchivo(const char *cad){
	FILE *inicioar = fopen(cad,LECTURA); //la funcion fopen intenta abrir el archivo
	//la "r" significa read, es decir queremos abrir el archivo para leer, "w" es para write y "a" para append
	if(inicioar == NULL) { //fopen regresa NULL si no pudo abrir el archivo
		fprintf(stderr,"%s",ERROR); //fprintf imprime cosas en un archivo, en este caso la
		//salida estandar de error
		exit(1); //la funcion exit termina el programa y su argumento es el codigo con el que termina el programa.
		//exit cero es como si el main regresara un cero.
	}
	return inicioar;//regreso el apuntador
}

