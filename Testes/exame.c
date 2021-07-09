#include <stdio.h>
#include <stdlib.h> // malloc
#include <string.h>

/* ex1 */
int paresImpares(int v[], int N) {
  int i = 0, j = N - 1;
  while (i < j) {
    if (v[i] % 2 == 0) {
      i++;
    } else {
      int aux = v[j];
      v[j] = v[i];
      v[i] = aux;
      j--;
    }
  }

  if (i == 0 && v[i] % 2 != 0)
    return 0;
  return i + 1;
}

/* ex2 */

typedef struct lligada {
  int valor;
  struct lligada *prox;
} * LInt;

void merge(LInt *r, LInt a, LInt b) {
  while (a && b) {
    if (a->valor < b->valor) {
      *r = a;
      a = a->prox;
    } else {
      *r = b;
      b = b->prox;
    }
    r = &((*r)->prox);
  }

  if (!a) {
    *r = b;
    return;
  }

  if (!b) {
    *r = a;
    return;
  }
}

/* ex3 */
void latino(int N, int m[N][N]) {
  for (int i = 0; i < N; i++) {
    int count = i + 1;
    for (int j = 0; j < N; j++) {
      if (count == N + 1)
        count = 1;
      m[i][j] = count;
      count++;
    }
  }
}

/* ex4 */
// nao percebo
typedef struct nodo {
  int valor;
  struct nodo *pai, *esq, *dir;
} * ABin;

ABin next(ABin a) {
  if (!a)
    return NULL;

  if (!a->dir && !a->pai)
    return NULL;
  else if (!a->dir && a->pai->dir)
    return a->pai;
  else if (!a->dir && a->pai->esq)
    return a->pai->pai;

  return a->dir;
}

/* ex5 */
typedef struct palavras {
  char *palavra;
  int nOcorr;
  struct palavras *esq, *dir;
} * Palavras;

void rodaDireita(Palavras *a);
void rodaEsquerda(Palavras *a);

int acrescentaPal(Palavras *p, char *pal) {
  while (*p) {
    int i = strcmp((*p)->palavra, pal);
    if (i == 0) {
      (*p)->nOcorr++;
      if ((*p)->dir && (*p)->dir->nOcorr < (*p)->nOcorr)
        rodaDireita(p);
      return (*p)->nOcorr;
    } else if (i > 0)
      p = &((*p)->esq);
    else
      p = &((*p)->dir);
  }

  Palavras new = malloc(sizeof(struct palavras));
  new->dir = new->esq = NULL;
  new->palavra = pal;
  new->nOcorr = 1;
  *p = new;
  return 1;
}

int main(void) {
  printf("\nEx3\n");
  int N = 0;
  printf("Introduza a dimensão da matriz NxN:\n");
  scanf("%d", &N);
  putchar('\n');
  int m[N][N];
  latino(N, m);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", m[i][j]);
    }
    putchar('\n');
  }
}
