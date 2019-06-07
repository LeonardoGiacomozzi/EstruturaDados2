#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define MAX 50

typedef struct {
	int  connectionType;
	char address[30];
} PageDate;

typedef struct {
	int top;
	PageDate A[MAX];
} Stack;

int size(Stack* stack) {
	int size = stack->top+1;
	return size;
}

bool isEmpty(Stack* stack) {
	if (size(stack) == 0) {
		return true;
	} 		
	return false;
}

bool isFull(Stack* stack) {
	if (size(stack) >= MAX) {
		return true;
	} 
	return false;
}

void init(Stack* stack){
	stack->top = -1;
}

void showAtual(Stack* stack) {
	if (isEmpty(stack)) {
		printf("\nSeu site atual foi fechado.\nVoce nao acessou nenhum site antes desse!\n\n");
	} else {
		printf("\nVoce acessou e esta na pagina: \" ");
		int i;
		int cont;
	
		for (i = stack->top; i>=0 ;i--){
			cont = stack->top;
		}
		
		printf("Conexao %d: ", stack->A[cont].connectionType);
		printf("%s ", stack->A[cont].address);
		printf("\"\n\n");
	}
}

void showAll(Stack* stack){
	if(isEmpty(stack)) {
		printf("\nNao tem nenhuma aba aberta =/\n\n");
	} else {
		printf("\nTodas essas abas estao abertas: \" ");
		int i;
		for (i = stack->top; i>=0 ;i--){
			printf("Conexao %d: ", stack->A[i].connectionType);
			printf("%s | ", stack->A[i].address);
		}
		printf("\"\n\n");
	}
}

bool push(Stack* stack, PageDate pagina){
	 if (isFull(stack)) 
	 	return false;
	 	
	 stack->top = stack->top+1;
	 stack->A[stack->top] = pagina;
	 return true;
}

PageDate* pop(Stack* stack){
	if (isEmpty(stack)) 
		return NULL;
	
	PageDate* response = (PageDate*) malloc(sizeof(PageDate));
	*response = stack->A[stack->top];
	
	stack->top = stack->top-1;
	return response;
}

void restart(Stack* stack) {
     stack->top = -1;
     printf("\nTodas as abas foram fechadas!\n\n");
}

int main() {
	Stack pilha;
	PageDate page;
	page.connectionType = 0;
	init(&pilha);
	
	int op = 10000;
	while (op != 0) {	
		printf("1 - Acessar um site. \n");
		printf("2 - Voltar ao site anterior. \n");
		printf("3 - Visualizar abas abertas. \n");
		printf("4 - Fechar todas as abas. \n");
		printf("5 - Mostrar em qual site eu estou. \n");
		printf("0 - Sair. \n");
		scanf("%d",&op);
		
		switch(op) {
			case 0:
				printf("\nSistema finalizado!");
				op = 0;
				break;
			
			case 1:
				printf("\nDigite o site em que voce deseja acessar: \n");
				scanf("%s", &page.address);
				page.connectionType++;
				push(&pilha, page);
				showAtual(&pilha);
				break;
				
			case 2:
				if(isEmpty(&pilha)) {
					printf("\nVoce nao acessou nenhum site ainda!\n\n");
				} else {
					pop(&pilha);
					showAtual(&pilha);
				}
				break;
			
			case 3:
				showAll(&pilha);
				break;
				
			case 4:
				if (isEmpty(&pilha)) {
					printf("\nNao tem nenhuma aba aberta ainda!\n\n");
				} else {
					restart(&pilha);
					page.connectionType = 0;
				}
				break;
				
			case 5:
				if (isEmpty(&pilha)) {
					printf("\nVoce nao esta em nenhum site no momento!\n\n");
				} else {
					showAtual(&pilha);
				}
				break;
				
			default:
				printf("\nOpcao %d eh invalida!\n\n", op);
				break;	
		}
	}	
}
