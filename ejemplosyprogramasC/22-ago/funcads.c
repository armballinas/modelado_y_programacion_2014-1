#include<stdio.h>
#include "funcads.h"


int migetline(char line[], int maxline){
	int c,i;
	
	for(i=0;i<maxline-1 && (c = getchar()) != EOF && c!='\n';++i){
		line[i] = c;
	}
	if(c=='\n'){
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

void copy(char to[], char from[]){
	int i;
	i = 0;
	while((to[i] = from[i]) != '\0'){
		i++;
	}
}


