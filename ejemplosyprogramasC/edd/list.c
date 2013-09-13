#include "list.h"

enum op_codes {OK = 0,NIL = -1,NO_MEM = 1, BAD_IDX = 2};

/*
*Función dependiente del tipo de elemento, es usada para imprimir la representación del elemento.
*CAMBIARLA CUANDO SE CAMBIA EL TIPO DE ELEMENTO.
*/
void imprime_elemento(Elemento e){
	printf("%d",e);
}
/*
*Función que inicializa una lista vacía,
*regresa un apuntador a una lista vacía
*/
Lista *inicializa_lista_vacia(){
	Lista *l = (Lista*)malloc(sizeof(Lista));
	if(l!=NULL){
		l->cabeza = NULL;
		l->longitud = 0;
	}
	return l;
}

/*
*Función que inicializa una lista a partir de un elemento que será el valor de su nodo cabeza.
*recibe un elemento que será el valor de la cabeza de la lista
*regresa un apuntador a una lista con un elemento.
*/
Lista *inicializa_lista_elem(const Elemento e){
	NodoL *elem = (NodoL*)malloc(sizeof(NodoL));
	if(elem!=NULL){
		elem->valor = e;
		elem->siguiente = elem->anterior = NULL;
		Lista *l = (Lista*)malloc(sizeof(Lista));
		if(l!=NULL){
			l->cabeza = elem;
			l->longitud = 1;
			return l;
		}
	}
	return NULL;
}

/*
*Función que dada una lista, devuelve su longitud
*recibe una lista a la que se le quiere obtener su longitud
*devuelve un elemento entero no negativo con el valor de la longitud de la lista
*/
size_t dame_longitud(const Lista* l){
	if(l!=NULL)	return l->longitud;
	return 0;
}

/*
*Función que agrega un elemento en un índce dado a una lista.
*recibe l-un apuntador a una lista a la que se le agregará un elemento
*		e-el elemento a agregar a l.
*		idx-el índice a donde se quiere añadir el elemento. Si el índice excede la longitud de la lista, el elemento se 
*		tratará de agregar al final.
*devuelve un entero con el resultado de la operación de inserción bajo el siguiente código:
	- 0 la inserción se llevó a cabo correctamente
	- (-1) la lista no estaba inicializada. La inserción no se llevó a cabo.
	- 1 El elemento no pudo crearse por falta de memoria o por un error de malloc. La inserción no se llevó a cabo.
*El valor devuelto sirve para propósitos de depuración de errores y detección de los mismos. Al hacer una inserción verificar que el valor devuelto sea cero (0).
*/
short int agrega(Lista *l,const Elemento e, int idx){
	if(l==NULL) return NIL;
	NodoL *aux = l->cabeza;
	if(idx<0) idx = 0;
	size_t len = l->longitud;
	if(idx>len) idx =len;
	if(idx==0){
		NodoL *elem = (NodoL*)malloc(sizeof(NodoL));
		if(elem==NULL) return NO_MEM;
		elem->valor = e;
		elem->anterior = NULL;
		elem->siguiente = aux;
		l->cabeza = elem;
		l->longitud++;
		return OK;
	}
	else{
		int i;
		for(i=0;i<idx-1;i++){
			aux=aux->siguiente;
		}
		NodoL *elem = (NodoL*)malloc(sizeof(NodoL));
		if(elem==NULL) return NO_MEM;
		elem->valor = e;
		elem->anterior = aux;
		NodoL *siguiente = (aux->siguiente);
		elem->siguiente = siguiente;
		if(siguiente !=NULL){
		siguiente->anterior = elem;
		}
		aux->siguiente = elem; 
		
		l->longitud++;
		return OK;
	}
}

/*
*Función que agrega un elemento a una lista al inicio de la misma, usa la función agrega con el índice 0 y los mismos argumentos que recibe.
*recibe l - un apuntador a una lista a la que se le quiere agregar un elemento.
		e - el elemento que se quiere agregar a l.
*devuelve el valor devuelto por agrega(l.e.0).
*/
short int agrega_inicio(Lista *l,const Elemento e){
	return agrega(l,e,0);
}

/*
*Función que agrega un elemento a una lista al final de la misma, usa la función agrega con el índice longitud de l y los mismos argumentos que recibe.
*recibe l - un apuntador a una lista a la que se le quiere agregar un elemento.
		e - el elemento que se quiere agregar a l.
*devuelve el valor devuelto por agrega(l.e.l->longitud).
*/
short int agrega_final(Lista *l,const Elemento e){
	return  agrega(l,e,l->longitud);
}

/*
*Función que imprime los elementos de una lista, uno seguido del otro y separados por un espacio.
*NOTA, USA LA FUNCIÓN imprime_elemento.
*recibe un apuntador a una lista l que es la que se quiere imprimir.
*/
void imprime_lista(Lista *l){
	if(l!=NULL){
		int i;
		NodoL *aux = l->cabeza;
		for(i=0;i<l->longitud;i++){
			printf(" ");
			imprime_elemento(aux->valor);
			printf(" ");
			aux=aux->siguiente;		
		}
		printf("\n");
	}
}


/*
*Función que elimina un elemento en un índce dado de una lista.
*recibe l-un apuntador a una lista a la que se le eliminará un elemento
*devuelve un entero con el resultado de la operación de inserción bajo el siguiente código:
	- 0 la eliminación se llevó a cabo correctamente
	- (-1) la lista no estaba inicializada. La eliminación no se llevó a cabo.
	- 2 El índice no es correcto. La eliminación no se llevó a cabo.
*El valor devuelto sirve para propósitos de depuración de errores y detección de los mismos. Al hacer una eliminación verificar que el valor devuelto sea cero (0).
*/


short int elimina(Lista *l,int idx){
	if(l==NULL) return NIL;
	NodoL *aux = l->cabeza;
	if(idx<0) return BAD_IDX;
	size_t len = l->longitud;
	if(idx>len-1) return BAD_IDX; 
	if(idx==0){
		NodoL* siguiente = aux->siguiente;
		if(siguiente!= NULL){
			siguiente->anterior = NULL;
			aux->siguiente = NULL;
			l->cabeza = siguiente;
			l->longitud--;
			free(aux);
		}
		else{
			free(l->cabeza);
			l->cabeza = NULL;
			l->longitud = 0;
		}
		return OK;
	}
	else{
		int i;
		for(i=0;i<idx-1;i++){
			aux=aux->siguiente;
		}

		NodoL *quitar = (aux->siguiente);
		NodoL *sig = (quitar->siguiente);
		if(sig!=NULL){
			sig->anterior = aux;
			
		}
		aux->siguiente = sig;
		free(quitar);
		l->longitud--;
		return OK;
	}
}	


/*
*Función que elimina la cabeza de la lista.
+recibe un apuntador a una lista de la que se quiere eliminar la cabeza.
*devuelve el valor devuelto por elimina(l,0);
*/
short int elimina_cabeza(Lista *l){
	return elimina(l,0);
}

/*
*Función que elimina el último elemento de la lista.
+recibe un apuntador a una lista de la que se quiere eliminar el últmo elemento.
*devuelve el valor devuelto por elimina(l,l->longitud-1);
*/
short int elimina_ultimo(Lista *l){
	return elimina(l,l->longitud-1);
}


/*
*Función que devuelve el índice de la primera aparición de un elemento o -1 si no se ha encontrado.
*recibe: l - un apuntador a una lista donde se buscará un elemento.
*		 e - el elemento a buscar en l.
*devuelve el índice en l de la primera aparición de e o (-1) si no se encontró e en la lista.
*/
int busca_elemento(Lista *l,Elemento e){
	if(l!=NULL){
		Nodo *aux = l->cabeza;
		int i;
		for(i=0;i<l->longitud;i++){
			if(aux->elemento == e) return i;
			else aux = aux->siguiente;
		}
		return NIL;
	}
	return NIL;
}


