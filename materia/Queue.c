#include "TP6.h"


//---------------Aux------------------
void printSQueue(SQueue q){
	int i;
	putchar('|');

	for (i = 0; i < q->length; i++)
		printf("%d%s", q->values[q->front+i],i == q->length-1 ? "" : "| " );

	putchar('|');

}

void printDQueue(DQueue q){
    int i;

    putchar('[');
    for (i = q->front; i < q->length; i++){
    	printf("%d%s" ,q->values[i], i == q->length-1 ? "" : "| ");
    }

	putchar(']');
   
}







//-----------Static Queues-----------



void SinitQueue(SQueue q){
	q->length = 0;

}

int SisEmptyQ(SQueue q){
	return (q->length == 0);
}

int Senqueue(SQueue q, int x){
	int r = 0, p;
	if (q->length == MAX) r = 1;
	else q->values[q->front + q->length++] = x;   

	return r;
}

int Sdequeue(SQueue q, int *x){
	int r = 0;

	if (q-> length == 0) r = 1;
	else *x = q->values[(q->front++) + (q->length--)];

	return r;
}
int Sfront(SQueue q, int *x){
	int r = 0;

	if (q->length == 0) r = 1;
	else *x = q->values[q->front];

	return r;
}

//---------Dynamic Queues---------

void DinitQueue(DQueue q){
	q->size = 5;
	q->length = 0;
	q->front = 0;
	q->values = malloc(sizeof(int)*q->size);
}

int DisEmptyQ(DQueue q){
	return (q->length == 0);

}

int Denqueue(DQueue q, int x){
	if (q->front + q->length == q->size){
		q->values = realloc(q->values, 2*q->size * sizeof(int));
		q->size *= 2;
	}
	q->values[q->front + q->length++] = x;

	return 0;
}


int Ddequeue(DQueue q, int *x){
	int r = 0;	
	if (q->length == 0) r = 1;
	else *x = q->values[q->front++ + q->length];

	return r;
}

int Dfront(DQueue q, int *x){
	int r = 0;

	if (q->length == 0) r = 1;
	else *x = q->values[q->front]; 

	return r;
}