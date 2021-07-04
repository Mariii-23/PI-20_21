#include "TP6.h"


//---------------Aux-----------------------

void printSStack(SStack s){
	for (int i = s->sp-1; i > 0; i--)
		printf("|\t%d\t|\n", s->values[i]);

}

void printDStack(DStack s){
    int i;
    printf ("%d Items\n", s->sp);
    for (i=s->sp-1; i>=0; i--) 
        printf ("|\t%d\t|\n", s->values[i]);
    putchar ('\n');
}

//------------Static Stacks -------------------------
void SinitStack(SStack s){
	s->sp = 0; //(*s).sp = 0
}

int SisEmpty(SStack s){
	return (s->sp == 0);
}

int Spush(SStack s, int *x){
	int r = 0;

	if (s->sp == MAX) r = 1;
	else s->values[s->sp++] = *x;

	return r;
}

int Spop(SStack s, int *x){
	int r = 0;

	if (s->sp == 0) r = 1;
	else *x = s->values[s->sp--];

	return r;
}

int Stop(SStack s, int *x){
	int r = 0;

	if (s->sp == MAX) r = 1;
	else *x = s->values[s->sp-1];

	return r;
}

//-----------------Dynamic Stacks---------------
void DinitStack(DStack s){
	s->size = 5;
	s->values = malloc(sizeof(int)*s->size);
	s->sp = 0;

}

int DisEmpty(DStack s){
	return (s->sp == 0);
}

int Dpush(DStack s, int *x){
	int r = 0;
	//quando está cheia
	if (s->sp == s->size){
		s->values = realloc(s->values, 2*s->size);
		s->size *= 2;
	}

	s->values[s->sp++] = *x;
	return r;
}

int Dpop(DStack s, int *x){
	int r = 0;

	if (s->sp == 0) r = 1;
	else *x = s->values[s->sp--];

	return r;

}

int Dtop(DStack s, int *x){
	int r = 0;

	if (s->sp == 0) r = 1;
	else *x = s->values[s->sp-1];

	return r; 

}