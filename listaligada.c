// Inserting and deleting nodes in a list
#include <stdio.h>
#include <stdlib.h>

struct nodoLista{
	int dato; //cada nodo Lista contiene un dato entero
	struct nodoLista *ptrSiguiente; //apuntador al siguiente nodo
};

// sestructura auto referenciada
typedef struct nodoLista NodoLista; // sinonimo para struct nodoLista
typedef NodoLista *ptrNodoLista; // synonym for ListNode*

// prototypes
void insertar(ptrNodoLista *ptrS, int valor);
void insertarFinal(ptrNodoLista *ptrS, int valor);
void insertarCentro(ptrNodoLista *ptrS, int valor, int posicion);
int borrar(ptrNodoLista *sPtr, int valor);
int borrarUltimo(ptrNodoLista *sPtr);
int borrarCentro(ptrNodoLista *ptrS, int valor);
int estaVacia(ptrNodoLista ptrS);
void imprimeLista(ptrNodoLista ptrActual);
void instrucciones(void);

int main() {
	ptrNodoLista ptrInicial = NULL; // inicialmente no existen nodos
	int opcion; //eleccion del usuario
	int var ; // entero ingresado por el usuario

	instrucciones(); // despliega el menu
	printf("%s", "? ");
	scanf("%d", &opcion);

	// ciclo while para que el usuario no elija 3
	while (opcion != 3) {
		switch (opcion) {
			case 1: // insertar un elemento
				printf("%s", "Introduce un valor entero: ");
				scanf("\n%d", &var);
				insertar(&ptrInicial, var); // insertar el elemento en la lista
				imprimeLista(ptrInicial);
				break;
			case 2: 
				 // si la lista no esta vacia
				if(!estaVacia(ptrInicial)) {
					printf("%s", "Introduce el valor que sera eliminado: ");
					scanf("\n%d", &var);
				
					// si el valor es econtrado, se remueve
					if (borrar(&ptrInicial, var)) { // elemento borrado
						printf("%d borrado.\n", var);
						imprimeLista(ptrInicial);
					}
					else {
						printf("%d No se encontro.\n\n", var);
					}
				}//fin del if
				
			
			
			else {
					printf("La lista esta vacia.\n");
			}
			break;
			case 4:
				printf("%s", "Introduce un valor entero: ");
				scanf("\n%d", &var);
				insertarFinal(&ptrInicial, var); // insertar el elemento en la lista
				imprimeLista(ptrInicial);
				break;			
			case 5:
				printf("%s", "Introduce un valor entero: ");
				scanf("\n%d", &var);
				insertarCentro(&ptrInicial, var, 7); // insertar el elemento en la lista
				imprimeLista(ptrInicial);
				break;			
			default:
				printf("Opcion invalida.\n");
				instrucciones();
				break;
			}//fin del switch
			printf("%s", "? ");
			scanf("%d", &opcion);
		} // fin while

		printf("Termino el programa.");
		return 0;
}

	// display program instructions to user
void instrucciones(void) {
		printf("Introduce una opcion:\n 1. Insertar un elemento a la lista.\n 2. Borrar un elemento de la lista.\n 3: Salir del programa.");

	}
	
// insertar un valor nuevo en la lista en order
void insertar(ptrNodoLista *ptrS, int valor) {
	ptrNodoLista ptrNuevo;
	
	ptrNuevo = malloc(sizeof(NodoLista)); // crear nodo
	
	if(ptrNuevo != NULL) { // hay espacio disponible?
		ptrNuevo->dato = valor; // coloca el valor en el nodo
		// inserta un nuevo nodo al principio de la lista
		ptrNuevo->ptrSiguiente=*ptrS;
		*ptrS = ptrNuevo;

	}
	else {
		printf("%d no se inserto. Memoria no disponible.\n", valor);
	}
}

void insertarFinal(ptrNodoLista *ptrS, int valor) {
	ptrNodoLista ptrNuevo;
	ptrNodoLista ptrActual;
	ptrNuevo = malloc(sizeof(NodoLista)); // crear nodo
	
	if(ptrNuevo != NULL) { // hay espacio disponible?
		ptrNuevo->dato = valor; // coloca el valor en el nodo
		ptrActual = *ptrS;
	while (ptrActual->ptrSiguiente != NULL) 
	{ 
		ptrActual = ptrActual->ptrSiguiente; // ... siguiente nodo
	}
		// inserta un nuevo nodo al principio de la lista
	ptrActual->ptrSiguiente = ptrNuevo;
	ptrNuevo->ptrSiguiente = NULL;

	}
	else {
		printf("%d no se inserto. Memoria no disponible.\n", valor);
	}
}

void insertarCentro(ptrNodoLista *ptrS, int valor, int posicion) {
	ptrNodoLista ptrNuevo;
	ptrNodoLista ptrActual;
	ptrNodoLista ptrAnterior;
	ptrNuevo = malloc(sizeof(NodoLista)); // crear nodo
	int i = 1;
	if(ptrNuevo != NULL) { // hay espacio disponible?

		ptrNuevo->dato = valor; // coloca el valor en el nodo
		ptrActual = *ptrS;
	while (i < posicion || ptrActual != NULL)
	{
		ptrAnterior = ptrActual; // entra al...
		ptrActual = ptrActual->ptrSiguiente; // ... siguiente nodo
		i++;
	} 
	if (ptrActual != NULL)
	{
		// inserta un nuevo nodo al principio de la lista
	ptrAnterior->ptrSiguiente = ptrNuevo;
	ptrNuevo->ptrSiguiente = ptrActual;
	}else {
		printf("%d no se inserto. Fuera del rango de valor.\n", valor);
	}
		
	
	

	}
	else {
		printf("%d no se inserto. Memoria no disponible.\n", valor);
	}
}

// Borrar una elemento de la lista
int borrar(ptrNodoLista *ptrS, int valor) {
	ptrNodoLista ptrTemporal;
	   
   // borrar el primero nodos 
		ptrTemporal = *ptrS; // almacena el nodo a eliminar
		*ptrS = (*ptrS)->ptrSiguiente; // desata el nodo
		free(ptrTemporal); // libera el nodo
		return valor;

	 return '\0';
}

int borrarUltimo(ptrNodoLista *ptrS) {
	
	ptrNodoLista ptrAnterior;
	ptrNodoLista ptrActual;

	ptrActual = *ptrS;

	while (ptrActual->ptrSiguiente != NULL) 
	{ 
		ptrAnterior = ptrActual; // entra al...
		ptrActual = ptrActual->ptrSiguiente; // ... siguiente nodo
	}
	 // almacena el nodo a eliminar
	ptrAnterior->ptrSiguiente = ptrActual->ptrSiguiente;
	free(ptrActual); // desata el nodo
	return 1;
	}

	int borrarCentro(ptrNodoLista *ptrS, int valor){
	ptrNodoLista ptrAnterior;
	ptrNodoLista ptrActual;

	ptrActual = *ptrS;

	for (int i = 0; i < valor; i++)
	{ 
		ptrAnterior = ptrActual; // entra al...
		ptrActual = ptrActual->ptrSiguiente; // ... siguiente nodo
	}
	 // almacena el nodo a eliminar
	ptrAnterior->ptrSiguiente = ptrActual->ptrSiguiente;
	free(ptrActual); // desata el nodo
	return 1;

	}


	// regrasa 1 si la lista esta vacia de lo contrario 0. 
	int estaVacia(ptrNodoLista ptrS) {
		return ptrS == NULL;
	}

// imprime la lista
void imprimeLista(ptrNodoLista ptrActual) {
	// Si la lista esta vacia
	if (estaVacia(ptrActual)) {
		printf("La lista esta vacia.\n");
	}
	else {
		printf("La lista es:");
		
		//mientras no sea el final de la lista
		while (ptrActual != NULL) {
			printf("%d --> ", ptrActual->dato);
			ptrActual = ptrActual->ptrSiguiente;
		}
		printf("NULL\n");
	}
}