#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
typedef struct {
  char key[10];
  } Aviao;

typedef struct aux {
  Aviao aviao;
  struct aux* next;
} Element;

typedef struct {
  Element* front;
  Element* rear;
} Pista;

void init(Pista* pista){
  pista->front = NULL;
  pista->rear = NULL;
}


bool isEmpty(Pista* pista) {
	if( pista->front == NULL){
		return true;
	}
	return false;
}

bool enqueue(Pista* pista, Aviao aviao){
	Element* element = (Element*) malloc(sizeof(Element));
	if (element == NULL) {
		return false;
	}
	element->aviao = aviao;
	element->next = NULL;
	
	if (isEmpty(pista)) {
		pista->front = element;
	} else {
		pista->rear->next = element;
	}
	pista->rear = element;
    return true;
}

Aviao* dequeue(Pista* pista) {

	if (isEmpty(pista)) {
		printf("Lista vazia");
		return NULL;
	}
	Element* toRemove = pista->front;
	
	Aviao* response = (Aviao*) malloc(sizeof(Aviao));
	*response = toRemove->aviao;
	
	pista->front = toRemove->next;	
	if (pista->front == NULL) {
		pista->rear = NULL;
	}
	
	free(toRemove);
	return response;
}

void restart(Pista* pista) {
	while (!isEmpty(pista)){
		free(dequeue(pista));
	}
	init(pista);
}

Aviao* front(Pista* pista) {
	if (isEmpty(pista)) {
		return NULL;
	}
	Aviao* response = (Aviao*) malloc(sizeof(Aviao));
	*response = pista->front->aviao;
	return response;
}


void show(Pista pista){
	printf("\n Pista Show\n");
	while(!isEmpty(&pista)){
		printf("Aviao codigo %s eh o proximo a decolar\n",front(&pista)->key);
		free(dequeue(&pista));
	}
}

int main(){
	Pista pista ;
	Aviao aviao ;
	int op=10000;
	init(&pista);
	while (op != 0) 
	{
		printf("Qual operação deseja fazer? \n");
		printf("1 - Adicionar um avião na pista de decolagem \n");
		printf("2 - Verificar qual o proximo avião a decolar \n");
		printf("3 - Autorizar a decolagem do proximo avião na pista \n");
		printf("4 - Listar a fila de espera da pista\n");
		printf("0 - Encerrar as operaçoes\n");
		scanf("%d",&op);
		
		switch(op)
		{
			case 1:
				printf("Informe o codigo do avião com no maximo 10 caracteres \n");
				scanf("%s",&aviao.key);
				enqueue(&pista,aviao);
				break;
			case 2:
				printf("Proximo avião a decolar e o de codigo %s\n",front(&pista)->key);
				break;
			case 3:
				printf("Aviao de codigo %s esta autorizado a decolar \n",dequeue(&pista)->key);
				break;
			case 4:
				show(pista);
				break;
			case 0:
				printf("Sistema Finalizado!!");
				op=0;
				break;
			default:
				printf("opcao %d eh invalida",op);
		}
		
	}
	free(&op);
	
	
	

}
