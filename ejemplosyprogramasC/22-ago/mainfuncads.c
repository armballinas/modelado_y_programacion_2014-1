#include<stdio.h>
#include"funcads.h"

#define MAXLINE 1000

/*
Este main lee varias lineas de la entrada estándar usando la función get line y extrae la más larga de ellas usando la función copy
Al final imprime la cadena más larga escrita por el usuario. 
OBS: para enviar al programa la señal de EOF en los sistemas tipo Unix se puede usar Ctrl + D(control mas la tecla D).
*/
int main(){
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];
	
	max = 0;
	while((len = migetline(line, MAXLINE))>0){
		if(len>max){
			max = len;
			copy(longest,line);
		}
	}
	if(max > 0){
		printf("%s", longest);
	}
	return 0;
}
