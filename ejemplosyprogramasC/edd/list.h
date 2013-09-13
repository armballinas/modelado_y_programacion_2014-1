#include<stdlib.h>
#include<stdio.h>

typedef int Elemento;




struct NodoLista{
	Elemento valor;
	struct NodoLista *siguiente;
	struct NodoLista *anterior;
};

typedef struct NodoLista NodoL;

struct ListaC{
	NodoL* cabeza;
	size_t longitud;
};

typedef struct ListaC Lista;


Lista *inicializa_lista_vacia();

Lista *inicializa_lista_elem(const Elemento);

size_t dame_longitud(const Lista*);

short int agrega(Lista*,const Elemento,int);

short int agrega_inicio(Lista*,const Elemento);

short int agrega_final(Lista*,const Elemento);

void imprime_elemento(Elemento);

short int elimina(Lista *, int);

short int elimina_cabeza(Lista *);

short int elimina_ultimo(Lista *);

int busca_elemento(Lista*,Elemento);



void imprime_lista(Lista*);
