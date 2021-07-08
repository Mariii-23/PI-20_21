/* #include "51_-_100_Questoes.h" */
#include <math.h>
#include <stdbool.h> // boolean
#include <stdio.h>
#include <stdlib.h> // malloc
#include <string.h>

typedef struct lligada {
  int valor;
  struct lligada *prox;
} * LInt;

/* -------------- 1 ---------------- */
int length(LInt l) {
  int count = 0;
  while (l) {
    l = l->prox;
    count++;
  }
  return count;
}

/* -------------- 2 ---------------- */
//.
void freeL(LInt l) {
  while (l) {
    LInt aux = l;
    l = l->prox;
    free(aux);
  }
}

/* -------------- 3 ---------------- */
void imprimeL(LInt l) {
  while (l) {
    printf("%d\n", l->valor);
    l = l->prox;
  }
}

/* -------------- 4 ---------------- */
LInt reverseL(LInt l) {
  LInt l2, l1 = NULL;
  while (l) {
    l2 = l->prox;
    l->prox = l1;
    l1 = l;
    l = l2;
  }
  return l1;
}

/* -------------- 5 ---------------- */
void insertOrd(LInt *l, int x) {
  LInt novonodo;
  while (*l && (*l)->valor < x)
    l = &((*l)->prox);

  novonodo = malloc(sizeof(struct lligada));
  novonodo->valor = x;
  novonodo->prox = *l;
  *l = novonodo;
}

/* -------------- 6 ---------------- */
int removeOneOrd(LInt *l, int x) {
  while (*l && (*l)->valor < x)
    l = &((*l)->prox);

  if (*l && (*l)->valor == x) {
    {
      LInt aux = *l;
      *l = (*l)->prox;
      free(aux);
    }
    return 0;
  }
  return 1;
}

/* -------------- 7 ---------------- */
void merge(LInt *r, LInt a, LInt b) {
  while (a != NULL && b != NULL) {
    if (a->valor <= b->valor) {
      *r = a;
      a = a->prox;
    } else {
      *r = b;
      b = b->prox;
    }
    r = &((*r)->prox);
  }
  if (a == NULL)
    *r = b;
  else
    *r = a;
}

/* -------------- 8 ---------------- */
void splitQS(LInt l, int x, LInt *mx, LInt *Mx) {
  while (l) {
    if (l->valor < x) {
      *mx = l;
      mx = &((*mx)->prox);
    } else {
      *Mx = l;
      Mx = &((*Mx)->prox);
    }
    l = l->prox;
  }
  *mx = NULL;
  *Mx = NULL;
}

/* -------------- 9 ---------------- */
/* encontra - se incorreto */
LInt parteAmeio(LInt *l) {
  LInt *x = l, *y = l;
  LInt lista = *l;
  int i;
  for (i = 0; lista != NULL; lista = lista->prox, i++)
    ;
  int n = i / 2;

  for (i = 0; i < n; i++) {
    *x = (*x)->prox;
  }
  // l = x;

  if (n == 0) {
    l = y;
    return NULL;
  } else
    return *y;
}

/* -------------- MAIN --------------- */
int main(void) {
  printf("Helloooo\n");
  return 0;
}
