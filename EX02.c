#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>

#define MAX 100


typedef struct {
	int customerId;
	double price;
} PrintingData;


typedef struct aux {
  PrintingData item;
  struct aux* next;
} Element;

typedef struct {
  Element* front;
  Element* rear;
} Queue;
	
	
	
void init(Queue* queue){
  queue->front = NULL;
  queue->rear = NULL;
}

bool isEmpty(Queue* queue) {
	return queue->front == NULL;
}

bool enqueue(Queue* queue, PrintingData pd){
	Element* element = (Element*) malloc(sizeof(Element));
	if (element == NULL) {
		return false;
	}
	element->item = pd;
	element->next = NULL;
	
	if (isEmpty(queue)) {
		queue->front = element;
	} else {
		queue->rear->next = element;
	}
	queue->rear = element;
    return true;
}

PrintingData* dequeue(Queue* queue) {

	if (isEmpty(queue)) {
		return NULL;
	}
	Element* toRemove = queue->front;
	
	PrintingData* response = (PrintingData*) malloc(sizeof(PrintingData));
	*response = toRemove->item;
	
	queue->front = toRemove->next;	
	if (queue->front == NULL) {
		queue->rear = NULL;
	}
	
	free(toRemove);
	return response;
}

void restart(Queue* queue) {
	Element* atual;
	Element* next;
	if(!isEmpty(queue)){
		next = queue->front;
		while (next != NULL){
			atual = next;
			next = atual->next;
			free(atual);
		}
	}
	init(queue);
}

PrintingData* front(Queue* queue) {
	if (isEmpty(queue)) {
		return NULL;
	}
	PrintingData* response = (PrintingData*) malloc(sizeof(PrintingData));
	*response = queue->front->item;
	return response;
}

void main()
{
	Queue queue;
	init(&queue);
	PrintingData pd ;
	pd.customerId=1;
	pd.price=5.60;
	enqueue(&queue,pd);
	
	
	pd.customerId=2;
	pd.price=6.60;
	enqueue(&queue,pd);
	
	
	pd.customerId=3;
	pd.price=4.60;
	enqueue(&queue,pd);
	
	
	pd.customerId=4;
	pd.price=3.20;
	enqueue(&queue,pd);

	printf(" Proximo elemento a ser processado e o de ID: %d \n",front(&queue)->customerId);
	dequeue(&queue);
	printf(" Proximo elemento a ser processado e o de ID: %d \n",front(&queue)->customerId);
	restart(&queue);
}

