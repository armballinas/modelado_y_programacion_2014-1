#include "list.h"
#include<stdio.h>


int main(){
	Lista *l1 = inicializa_lista_elem(2);
//	printf("l: %u, elem: %d\n",dame_longitud(l1),(l1->cabeza)->valor);
	printf("resultado: %d\n",agrega(l1,4,3));
	printf("l: %u\n",dame_longitud(l1));
	imprime_lista(l1);
	printf("resultado: %d\n",elimina(l1,1));
	imprime_lista(l1);
	printf("resultado: %d\n",elimina(l1,0));
	imprime_lista(l1);
	
}
