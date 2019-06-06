#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct {
	int numero;
} Record;

typedef struct aux {
	Record record;
	struct aux* next;
} Element;

typedef struct {
	Element* top;
} Stack;

void init(Stack* stack){
	stack->top = NULL;
}

void show(Stack* stack){
	Element* address = stack->top;
	printf("O numero em binario eh: \" ");
	while (address != NULL){
		printf("%i ", address->record.numero);
		address = address->next;
	}
	printf("\"\n");
}

bool push(Stack* stack, Record record) {
	Element* toAdd = (Element*) malloc(sizeof(Element));
	toAdd->record = record;
	toAdd->next = stack->top;
	stack->top = toAdd;
	return true;
}

int main () {
	Stack pilha;
	Record key;
	init(&pilha);
	
	printf("\nEscolha um numero decimal qualquer: \n");
	scanf("%d", &key.numero);
	
	int aux;
	int cont = key.numero;
	
	while (cont != 0) {
		if (cont % 2 == 0) {
			key.numero = 0;
		} else {
			key.numero = 1;
		}
		push(&pilha, key);
		cont = cont / 2;
	}
	
	show(&pilha);
}


