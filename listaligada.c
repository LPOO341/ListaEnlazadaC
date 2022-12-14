// Practica 2 Listas Enlazadas Jorge Omar Torres Sosa
// Inserting and deleting nodes in a list
#include <stdio.h>
#include <stdlib.h>

struct nodoLista
{
	int dato;												// cada nodo Lista contiene un dato entero
	struct nodoLista *ptrSiguiente; // apuntador al siguiente nodo
};

// sestructura auto referenciada
typedef struct nodoLista NodoLista; // sinonimo para struct nodoLista
typedef NodoLista *ptrNodoLista;		// synonym for ListNode*

// prototypes
void insertar(ptrNodoLista *ptrS, int valor);
void insertarFinal(ptrNodoLista *ptrS, int valor);
void insertarCentro(ptrNodoLista *ptrS, int valor, int posicion);
void borrar(ptrNodoLista *sPtr);
void borrarUltimo(ptrNodoLista *sPtr);
void borrarCentro(ptrNodoLista *ptrS, int valor);
int estaVacia(ptrNodoLista ptrS);
void imprimeLista(ptrNodoLista ptrActual);
void instrucciones(void);
int obtenerEntero(char mensaje[]);

int main()
{
	ptrNodoLista ptrInicial = NULL; // inicialmente no existen nodos
	int opcion, opcion2;						// eleccion del usuario
	int var, posicion;							// entero ingresado por el usuario

	// ciclo while para que el usuario no elija 3
	while (opcion != 3)
	{
		instrucciones();
		opcion = obtenerEntero("opcion: ");
		switch (opcion)
		{
		case 1: // insertar un elemento
			var = obtenerEntero("Entero a ingresar: ");
			printf("1. Ingresar al inicio\n2. Ingresar al final\n3. Ingresar al centro"); // Menu del tipo de insercion
			opcion2 = obtenerEntero("opcion: ");
			switch (opcion2)
			{
			case 1:
				insertar(&ptrInicial, var);
				break;
			case 2:
				if (!estaVacia(ptrInicial)) // valida que el arreglo no este vacio antes de insertar en el centro o al final
				{
					insertarFinal(&ptrInicial, var);
				}
				else
				{
					printf("La lista no esta inicializada, ingrese primero un valor al inicio");
				}
				break;
			case 3:
				if (!estaVacia(ptrInicial))
				{
					posicion = obtenerEntero("Posicion a insertar (2~n):");
					insertarCentro(&ptrInicial, var, posicion);
				}
				else
				{
					printf("La lista no esta inicializada, ingrese primero un valor al inicio\n");
				}
				break;
			default:
				printf("Opcion no valida");
				break;
			}
			break;
		case 2:
			// si la lista no esta vacia
			if (!estaVacia(ptrInicial))
			{
				printf("1. Borrar al inicio\n2. Borrar al final\n3. Borrar al centro");
				opcion2 = obtenerEntero("opcion: ");
				switch (opcion2)
				{
				case 1:
					borrar(&ptrInicial);
					break;
				case 2:
					borrarUltimo(&ptrInicial);
					break;
				case 3:
					posicion = obtenerEntero("Posicion a borrar: ");
					borrarCentro(&ptrInicial, posicion);
					break;
				default:
					printf("Opcion no valida");
					break;
				}
			}
			else
			{
				printf("La lista esta vacia, ingrese elementos primero\n");
			}
			break;
		default:
			printf("Opcion invalida.\n");
			break;
		} // fin del switch
		imprimeLista(ptrInicial);
		printf("\n\n");
	} // fin while

	printf("Termino el programa.");
	return 0;
}

// display program instructions to user
void instrucciones(void)
{
	printf("Introduce una opcion:\n 1. Insertar un elemento a la lista.\n 2. Borrar un elemento de la lista.\n 3: Salir del programa.");
}

// insertar un valor nuevo al inicio de la lista
void insertar(ptrNodoLista *ptrS, int valor)
{
	ptrNodoLista ptrNuevo;
	ptrNuevo = malloc(sizeof(NodoLista)); // crear nodo

	if (ptrNuevo != NULL)
	{													// hay espacio disponible?
		ptrNuevo->dato = valor; // coloca el valor en el nodo
		// inserta un nuevo nodo al principio de la lista
		ptrNuevo->ptrSiguiente = *ptrS;
		*ptrS = ptrNuevo;
	}
	else
	{
		printf("%d no se inserto. Memoria no disponible.\n", valor);
	}
}

int obtenerEntero(char mensaje[]) // Elimina la redundacia al obtener los int
{
	int var;
	printf("\n%s", mensaje);
	scanf("%d", &var);
	return var;
}

void insertarFinal(ptrNodoLista *ptrS, int valor) // Inserta un valor al final de la lista
{
	ptrNodoLista ptrNuevo;
	ptrNodoLista ptrActual;
	ptrNuevo = malloc(sizeof(NodoLista)); // crear nodo

	if (ptrNuevo != NULL)
	{													// hay espacio disponible?
		ptrNuevo->dato = valor; // coloca el valor en el nodo
		ptrActual = *ptrS;
		while (ptrActual->ptrSiguiente != NULL) // Recorre la lista hasta encontrar el ultimo valor
		{
			ptrActual = ptrActual->ptrSiguiente; // ... siguiente nodo
		}
		ptrActual->ptrSiguiente = ptrNuevo; // inserta el nuevo nodo al final
		ptrNuevo->ptrSiguiente = NULL;
	}
	else
	{
		printf("%d no se inserto. Memoria no disponible.\n", valor);
	}
}

void insertarCentro(ptrNodoLista *ptrS, int valor, int posicion)
{
	ptrNodoLista ptrNuevo;
	ptrNodoLista ptrActual;
	ptrNodoLista ptrAnterior;
	ptrNuevo = malloc(sizeof(NodoLista)); // crear nodo
	int i = 2;
	if (ptrNuevo != NULL) // Revisa si hay espacio en memoria
	{

		ptrNuevo->dato = valor; // coloca el valor en el nodo
		ptrActual = *ptrS;
		while (i <= posicion && ptrActual != NULL) // Iteramos el nodo hasta que se encuentra la posicion pedida o llega al final de la lista
		{
			ptrAnterior = ptrActual;						 // entra al...
			ptrActual = ptrActual->ptrSiguiente; // ... siguiente nodo
			i++;
		}
		if (ptrActual != NULL && posicion >= 2) // valida el rango, si posicion es menor dos esta debajo y si ptrActual es nulo esta sobrepasado
		{
			// inserta un nuevo nodo al principio de la lista
			ptrAnterior->ptrSiguiente = ptrNuevo;
			ptrNuevo->ptrSiguiente = ptrActual;
		}
		else
		{
			printf("%d no se inserto. Fuera del rango de valor (2-n)\n", valor);
		}
	}
	else
	{
		printf("%d no se inserto. Memoria no disponible.\n", valor);
	}
}

// Borra el primer elemento de la lista
void borrar(ptrNodoLista *ptrS)
{
	ptrNodoLista ptrTemporal;

	// borrar el primero nodos
	ptrTemporal = *ptrS;					 // almacena el nodo a eliminar
	*ptrS = (*ptrS)->ptrSiguiente; // desata el nodo
	free(ptrTemporal);						 // libera el nodo
}

void borrarUltimo(ptrNodoLista *ptrS) // borra el ultim nodo de la lista
{
	ptrNodoLista ptrAnterior;
	ptrNodoLista ptrActual;

	ptrActual = *ptrS;

	while (ptrActual->ptrSiguiente != NULL) // itera la lista hasta llegar al ulimo nodo
	{
		ptrAnterior = ptrActual;						 // entra al...
		ptrActual = ptrActual->ptrSiguiente; // ... siguiente nodo
	}
	// almacena el nodo a eliminar
	ptrAnterior->ptrSiguiente = ptrActual->ptrSiguiente;
	free(ptrActual); // desata el nodo
}

void borrarCentro(ptrNodoLista *ptrS, int valor) // borra un elemeno intermedio de la lista
{
	ptrNodoLista ptrAnterior;
	ptrNodoLista ptrActual;
	ptrActual = *ptrS;
	int i = 2;
	while (i <= valor && ptrActual != NULL)
	{
		ptrAnterior = ptrActual;						 // entra al...
		ptrActual = ptrActual->ptrSiguiente; // ... siguiente nodo
		i++;
	}
	if (ptrActual != NULL && valor >= 2)
	{
		ptrAnterior->ptrSiguiente = ptrActual->ptrSiguiente; // enlaza el nodo anterior al siguienet
		free(ptrActual);																		 // desata el nodo
	}
	else
	{
		printf("Fuera del rango de valor (2-n)\n");
	}
}

int estaVacia(ptrNodoLista ptrS)
{
	return ptrS == NULL;
}

// imprime la lista
void imprimeLista(ptrNodoLista ptrActual)
{
	// Si la lista esta vacia
	if (estaVacia(ptrActual))
	{
		printf("La lista esta vacia.\n");
	}
	else
	{
		printf("La lista es:");

		// mientras no sea el final de la lista
		while (ptrActual != NULL)
		{
			printf("%d --> ", ptrActual->dato);
			ptrActual = ptrActual->ptrSiguiente;
		}
		printf("NULL\n");
	}
}