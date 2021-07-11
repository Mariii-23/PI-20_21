#include <stdio.h>
#include <stdlib.h>

int sqrInt(int n) {
  if (n <= 0)
    return n;

  int r = 1;
  int last = 0;
  while ((r = last * last) <= n) {
    last++;
  }
  return last - 1;
}

int inverte(int v[], int n) {
  int meio = n / 2;

  for (int i = 0; i <= meio; i++) {
    int aux = v[i];
    v[i] = v[n - 1 - i];
    v[n - 1 - i] = aux;
  }
  return n;
}

typedef struct llint {
  int valor;
  struct llint *prox;
} NodoL, *LLint;

LLint cloneR(LLint l) {
  LLint novo = NULL;
  while (l) {
    LLint aux = l;
    aux->prox = novo;
    novo = aux;
    l = l->prox;
  }
  return novo;
}

typedef struct abint {
  int valor;
  struct abint *esq, *dir;
} NodoAB, *ABint;

int freeAB(ABint a) {
  if (!a)
    return 0;
  int count = freeAB(a->dir);
  count += freeAB(a->esq);
  free(a);
  count++;
  return count;
}

int pruneAB(ABint *a, int l) {
  int count = 0;
  if (!*a)
    return 0;
  if (l == 0) {
    count += freeAB(*a);
    *a = NULL;
  } else {
    count += pruneAB(&((*a)->dir), l - 1);
    count += pruneAB(&((*a)->esq), l - 1);
  }
  return count;
}

char *fgets(char *s, int n, FILE *f) {
  if (f == NULL)
    return NULL;
  int i = 0, c;
  while (i < n) {
    if ((c = fgetc(f)) != EOF) {
      s[i] = c;
      i++;
    }
  }
  s[i] = '\0';
  return s;
}

typedef struct bloco {
  int quantos; // elementos ocupados
  int valores[5];
  struct bloco *prox;
} Bloco, *LBloco;

int quantos(LBloco l) {
  int count = 0;
  while (l) {
    count += l->quantos;
    l = l->prox;
  }
  return count;
}

// esta mal
int compacta(LBloco *l) {
  if (*l)
    return 0;

  int quantos = (*l)->quantos;
  if (quantos < 5 && (*l)->prox) {
    int change;
    for (change = 0; quantos < 5; quantos++, change++) {
      if (change > (*l)->prox->quantos) {
        free((*l)->prox);
        return change;
      }
      (*l)->valores[quantos] = (*l)->prox->valores[change];
    }
    for (int i = 0; i <= change; i++) {
      (*l)->prox->valores[i] = (*l)->prox->valores[change + 1 + i];
    }
  }
  quantos += compacta(&((*l)->prox));
  return quantos;
}

int main(void) {
  printf("1. 49 -> %d\n", sqrInt(49));
  printf("1. 63 -> %d\n", sqrInt(63));
}
