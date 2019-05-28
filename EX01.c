#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>

#define MAX 50

typedef struct {
  char Cod[10];
} Aviao;

typedef struct {
  Aviao A[MAX];
  int size;
  int head;
  int tail;
} Pista;


void Inicializar(Pista* pista){
  pista->head = -1;
  pista->tail = -1;
}

bool isEmpty(Pista* pista) {
	return pista->head == -1 && pista->tail == -1;
}

bool isFull(Pista* pista) {
	int tmp = (pista->tail+1)%MAX;
	return  tmp == pista->head;
}

bool Add(Pista* pista, Aviao aviao){
	if (isFull(pista)) {
		printf("Pista Cheia \n");
		return false;
	} else if(isEmpty(pista)) {
		pista->head = 0;		
	}
	int tmp = (pista->tail+1)%MAX;
	pista->tail = tmp;
	pista->A[pista->tail] = aviao;
	pista->size = pista->size + 1;
    return true;
}

Aviao* ProximoADecolar(Pista* pista) {
	Aviao* response = (Aviao*) malloc(sizeof(Aviao));
	*response = pista->A[pista->head];
	return response;
}

Aviao* Decolar(Pista* pista) {

	if (isEmpty(pista)) {
		return NULL;
	}
	int aux = pista->head;
	if (pista->head == pista->tail) {
		pista->head = -1;
		pista->tail = -1;
	} else {
		int tmp = (pista->head+1)%MAX;
		pista->head = tmp;
	}
	
	Aviao* response = (Aviao*) malloc(sizeof(Aviao));
	*response = pista->A[aux];
	pista->size = pista->size-1;
	return response;
}

PrintAll(Pista* pista)
{
	int i;
	for ( i = 0; i < pista->size; i++ ) {
		printf( "Aviao Codigo %d esta na posicao %d\n",pista->A[ i ].Cod ,i );
	}		
}

