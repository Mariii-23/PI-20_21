#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Parte A */

/* --- 1--- */
int maiorPrefixo(char s1[], char s2[]) {
  int i = 0, resultado = 0;
  for (; s1[i] != '\0' && s2[i] != '\0'; i++) {
    if (s1[i] == s2[i])
      resultado++;
    else
      break;
  }
  return resultado;
}

/* --- 2 --- */
int remRep(char s[]) {
  char last = '\0';
  int j;
  for (int i = 0, j = 0; s[i] != '\0'; i++) {
    if (last != s[i]) {
      s[j] = s[i];
      j++;
    }
  }
  s[j] = '\0';
  return j;
}

typedef struct lligada {
  int valor;
  struct lligada *prox;
} * LInt;

/* --- 3 --- */
void spliQS(LInt l, int x, LInt *mx, LInt *Mx) {
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
  *Mx = NULL;
  *mx = NULL;
}

/* --- 4 --- */
int removeDups(LInt *l) {
  if (!*l)
    return 0;
  int last = (*l)->valor;
  l = &((*l)->prox);
  int count = 0;
  while (*l) {
    if (last == (*l)->valor) {
      count++;
      LInt aux = (*l);
      (*l) = (*l)->prox;
      free(aux);
    } else {
      l = &((*l)->prox);
    }
  }
  return count;
}

/* Parte B */

typedef struct dict {
  char *palavra;
  int ocorr;
  struct dict *esq, *dir;
} * Dict;

/* --- 1 --- */
// caso dict seja null
// caso d->esq seja NULL, quando fizermos d->esq->dir (r->dir) dara erro
Dict rodaDireita(Dict d) {
  if (!d)
    return d;

  if (!d->esq)
    return d;

  Dict r = d->esq;
  d->esq = r->dir;
  r->dir = d;
  return d;
}

/* --- 2 ---  */

Dict rodaEsquerda(Dict d) {
  if (!d)
    return d;

  if (!d->dir)
    return d;

  Dict r = d->dir;
  d->dir = r->esq;
  r->esq = d;
  return d;
}

/* --- 3 --- */
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
#define MIN(a, b) (((a) > (b)) ? (b) : (a))

Dict promoveMenor(Dict d) {
  Dict *e = &d;
  if (!d)
    return d;
  if (!d->esq && !d->dir)
    return d;

  d->esq = promoveMenor(d->esq);
  d->dir = promoveMenor(d->dir);

  int min = MIN(d->esq->ocorr, d->dir->ocorr);
  if (d->ocorr > min) {
    if (min == d->esq->ocorr) {
      d = rodaDireita(d);
    } else {
      d = rodaEsquerda(d);
    }
  }
  return d;
}

int acrescentaPal(Dict *p, char *pal) {
  while (*p) {
    int i = strcmp((*p)->palavra, pal);
    if (i == 0) {
      (*p)->ocorr++;
      while (((*p)->dir && (*p)->esq->ocorr > (*p)->ocorr) ||
             ((*p)->esq && (*p)->dir->ocorr > (*p)->ocorr))
        if ((*p)->esq->ocorr > (*p)->ocorr)
          *p = rodaDireita(*p);
        else
          *p = rodaEsquerda(*p);
      return (*p)->ocorr;
    } else if (i > 0)
      p = &((*p)->esq);
    else
      p = &((*p)->dir);
  }

  Dict new = malloc(sizeof(struct dict));
  new->dir = new->esq = NULL;
  new->palavra = pal;
  new->ocorr = 1;
  *p = new;
  return 1;
}
