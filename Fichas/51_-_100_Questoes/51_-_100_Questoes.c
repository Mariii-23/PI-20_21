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
LInt parteAmeio(LInt *l) {
  LInt lista = *l;
  int i;
  for (i = 0; lista != NULL; lista = lista->prox, i++)
    ;

  int n = i / 2;
  if (n == 0)
    return NULL;

  LInt y = (*l);
  LInt prev = NULL;

  while (n > 0) {
    prev = (*l);
    (*l) = (*l)->prox;
    n--;
  }
  prev->prox = NULL;
  return y;
}

/* -------------- 10 ---------------- */
int removeAll(LInt *l, int elem) {
  int count = 0;

  while (*l) {
    if ((*l)->valor == elem) {
      count++;
      {
        // libertar espaco
        (*l) = (*l)->prox;
      }
    } else
      l = &((*l)->prox);
  }
  return count;
}

/* -------------- 11 ---------------- */
int removeDups(LInt *l) {
  int count = 0;
  while (*l) {
    count += removeAll(&((*l)->prox), (*l)->valor);
  }
  return count;
}

/* -------------- 12 ---------------- */
int removeMaiorL(LInt *l) {
  int max;
  LInt *maiorL;

  if (*l) {
    max = (*l)->valor;
    maiorL = l;
    l = &((*l)->prox);
  }

  while (*l) {
    if ((*l)->valor > max) {
      max = (*l)->valor;
      maiorL = l;
    }
    l = &((*l)->prox);
  }
  {
    LInt aux = *maiorL;
    *maiorL = (*maiorL)->prox;
    free(aux);
  }
  return max;
}

/* -------------- 13 ---------------- */
void init(LInt *l) {
  while ((*l) && (*l)->prox) {
    l = &((*l)->prox);
  }

  {
    LInt aux;
    if ((*l)->prox) {
      aux = (*l)->prox;
      (*l)->prox = NULL;
    } else {
      aux = (*l);
      *l = NULL;
    }
    free(aux);
  }
}

/* -------------- 14 ---------------- */
void appendL(LInt *l, int value) {
  LInt novo = malloc(sizeof(struct lligada));
  novo->prox = NULL;
  novo->valor = value;

  while ((*l) && (*l)->prox) {
    l = &((*l)->prox);
  }

  if (!(*l))
    *l = novo;
  else
    (*l)->prox = novo;
}

/* -------------- 15 ---------------- */
void concatL(LInt *a, LInt b) {
  while ((*a) && (*a)->prox) {
    a = &((*a)->prox);
  }

  if (!(*a))
    *a = b;
  else
    (*a)->prox = b;
}

/* -------------- 16 ---------------- */
LInt cloneL(LInt l) {
  LInt clone, *e = &clone;

  while (l) {
    (*e) = malloc(sizeof(struct lligada));
    (*e)->valor = l->valor;
    e = &((*e)->prox);
    l = l->prox;
  }
  *e = NULL;
  return clone;
}

/* -------------- 17 ---------------- */
LInt cloneRev(LInt l) {
  LInt clone = NULL;
  while (l) {
    {
      LInt e = malloc(sizeof(struct lligada));
      e->valor = l->valor;
      e->prox = clone;
      clone = e;
    }
    l = l->prox;
  }
  return clone;
}

/* -------------- 18 ---------------- */
int maximo(LInt l) {
  if (!l)
    return -1;
  int max = l->valor;
  l = l->prox;
  while (l) {
    if (max < l->valor)
      max = l->valor;
    l = l->prox;
  }
  return max;
}

/* -------------- 19 ---------------- */
int take(int n, LInt *l) {
  int i = 0;
  while (n > 0 && (*l)) {
    i++;
    n--;
    l = &((*l)->prox);
  }

  while (*l) {
    {
      LInt aux = *l;
      *l = (*l)->prox;
      aux->prox = NULL;
      free(aux);
    }
  }
  return i;
}

/* -------------- 20 --------------- */
int drop(int n, LInt *l) {
  int i = 0;
  while (n > 0 && (*l)) {
    i++;
    n--;
    {
      LInt aux = *l;
      *l = (*l)->prox;
      aux->prox = NULL;
      free(aux);
    }
  }
  return i;
}

/* -------------- 21 --------------- */
LInt Nforward(LInt l, int N) {
  while (N-- > 0)
    l = l->prox;
  return l;
}

/* -------------- MAIN --------------- */
int main(void) {
  printf("Helloooo\n");
  return 0;
}
