#include <stdio.h>
#include <stdlib.h> // malloc

/* ---------- EX 1 ----------- */
int sumhtpo(int n) {
  int r = 0;
  while (n != 1) {
    r += n;
    if (n % 2 == 0)
      n = n / 2;
    else
      n = 1 + (3 * n);
  }
  return r;
}

void insere_array(int v[], int n, int elem) {
  for (int i = 0; i < n; i++) {
    if (v[i] < elem)
      v[i] = elem;
  }
}

int max_array(int v[], int n) {
  if (n < 1)
    return -1;
  int max = v[0];
  for (int i = 1; i < n; i++) {
    if (v[i] > max)
      max = v[i];
  }
  return max;
}

int sumhtpo1(int n) {
  int r = 0, i = 0, last[100] = {0};
  while (n != 1) {
    r += n;
    if (n % 2 == 0) {
      n = n / 2;
    } else
      n = 1 + (3 * n);

    if (i < 100) {
      last[i] = n;
      i++;
      i++;
    } else {
      insere_array(last, 100, n);
    }
  }
  if (i >= 100)
    // returnar o menor elemento do array
    return max_array(last, i);
  else
    return -1;
}

/* ---------- EX 2 ----------- */
int moda(int v[], int N, int *m) {
  if (N < 1)
    return 0;
  int i = 1, max = 1;
  *m = v[0];

  for (int j = 1; j < N; j++) {
    int count = 0;
    for (int l = j; l < N; j++) {
      if (v[j] == v[l])
        count++;
    }

    if (count > max) {
      *m = v[j];
      i = 1;
      max = count;
    } else if (count == max) {
      i++;
    }
  }
  return i > 1 ? 0 : max;
}

/* ---------- EX 3 ----------- */

typedef struct lligada {
  int valor;
  struct lligada *prox;
} * LInt;

int procura(LInt *l, int x) {
  LInt *e = l;

  while (*e && (*e)->valor != x) {
    e = &((*e)->prox);
  }

  if (!*e)
    return 0;

  LInt procura = *e;
  *e = (*e)->prox;
  procura->prox = *l;
  (*l) = procura;

  return 1;
}

/* ---------- EX 4 ----------- */
typedef struct nodo {
  int valor;
  struct nodo *pai, *esq, *dir;
} * ABin;

int freeAB(ABin a) {
  if (!a)
    return 0;
  int count = freeAB(a->esq);
  count += freeAB(a->dir);
  free(a);
  count++;
  return count;
}

/* ---------- EX 5 ----------- */
void caminho(ABin a) {
  if (!a)
    return;
  int last = a->valor;
  while (a->pai) {
    a = a->pai;
    if (a->esq && a->esq->valor == last) {
      printf("esq\n");
    } else {
      printf("dir\n");
    }
    last = a->valor;
  }
}
