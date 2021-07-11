#include <stdio.h>
#include <stdlib.h>

typedef struct slist {
  int valor;
  struct slist *prox;
} * LInt;

typedef struct nodo {
  int valor;
  struct nodo *esq, *dir;
} * ABin;

/* PARTE A */

/* --- 1 --- */
int retiraNeg(int v[], int N) {
  int j;
  for (int i = 0, j = 0; i < N; i++) {
    if (v[i] >= 0) {
      v[j] = v[i];
      j++;
    }
  }
  return j;
}

/* --- 2 --- */
int difConsecutivos(char s[]) {
  int max = 0, count = 0;
  char last = '\0';
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] != last) {
      count++;
      last = s[i];
    } else {
      if (max < count)
        max = count;
      count = 1;
    }
  }
  if (max < count)
    max = count;
  return max;
}

/* --- 3 --- */
int maximo(LInt l) {
  if (!l)
    return -1;
  int max = l->valor;
  l = l->prox;
  while (l) {
    if (l->valor > max)
      max = l->valor;
    l = l->prox;
  }
  return max;
}

/* --- 4 --- */
int removeALL(LInt *l, int x) {
  int count = 0;
  while (*l) {
    if ((*l)->valor == x) {
      LInt aux = *l;
      *l = (*l)->prox;
      free(aux);
      count++;
    } else
      l = &((*l)->prox);
  }

  return count;
}

/* --- 5 --- */
LInt arrayToList(int v[], int N) {
  LInt novo = NULL;
  for (int i = N - 1; i >= 0; i--) {
    LInt new = malloc(sizeof(struct slist));
    new->valor = v[i];
    new->prox = novo;

    novo = new;
  }
  return novo;
}

/* PARTE B */

/* --- 1 --- */
int minheapOK(ABin a) {
  int fail = 1;
  if (a) {
    if (a->dir && a->esq)
      fail = a->dir > a && a->esq > a && minheapOK(a->dir) && minheapOK(a->esq);
    else if (a->dir)
      fail = a->dir > a && minheapOK(a->dir);
    else
      fail = a->esq > a && minheapOK(a->esq);
  }
  return fail;
}

/* --- 2 --- */
int maxHeap(ABin a) {
  if (!a->esq && !a->dir)
    return a->valor;
  int e, d;

  if (!a->dir)
    return maxHeap(a->esq);

  if (!a->esq)
    return maxHeap(a->dir);

  e = maxHeap(a->esq);
  d = maxHeap(a->dir);
  return e > d ? e : d;
}

/* --- 3 --- */
void removeMin(ABin *a) {
  // um unico elemento
  if (!(*a)->dir && !(*a)->esq) {
    free(*a);
    *a = NULL;
  } else if (!(*a)->esq) { // nada do lado esquerdo
    ABin aux = *a;
    *a = (*a)->dir;
    free(*a);
  } else if (!(*a)->dir) { // nada do lado direito
    ABin aux = *a;
    *a = (*a)->esq;
    free(*a);
  } else { // teremos q ver qual é o menor
    ABin aux = *a;
    // corrigimos a raiz
    if ((*a)->dir > (*a)->esq) {
      (*a)->valor = (*a)->esq->valor;
      a = &((*a)->esq);
    } else {
      (*a)->valor = (*a)->dir->valor;
      a = &((*a)->dir);
    }
    free(aux);

    // corrigimos tudo para baixo
    while (*a) {
      if (!(*a)->dir && !(*a)->esq) {
        *a = NULL;
        return;
      }
      if (!(*a)->dir) {
        *a = (*a)->esq;
        return;
      }
      if (!(*a)->esq) {
        *a = (*a)->dir;
        return;
      }
      if ((*a)->esq < (*a)->dir) {
        (*a)->valor = (*a)->esq->valor;
        a = &((*a)->esq);
      } else {
        (*a)->valor = (*a)->dir->valor;
        a = &((*a)->dir);
      }
    }
  }
}

/* --- 4 --- */
void add(ABin *a, int x);

void heapSort(int v[], int N) {
  ABin *arvore;
  for (int i = 0; i < N; i++)
    add(arvore, v[i]);

  for (int i = 0; i < N && *arvore; i++) {
    v[i] = (*arvore)->valor;
    removeMin(arvore);
  }
}

/* --- 5 --- */
int kMaior(int v[], int N, int k) {
  ABin *arvore;
  for (int i = 0; i < N; i++) {
    if (i < k) {
      add(arvore, v[i]);
    } else {
      if ((*arvore)->valor < v[i]) {
        removeMin(arvore);
        add(arvore, v[i]);
      }
    }
  }
  return (*arvore)->valor;
}
