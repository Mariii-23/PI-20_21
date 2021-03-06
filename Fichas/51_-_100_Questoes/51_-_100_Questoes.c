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

/* -------------- 22 --------------- */
int listToArray(LInt l, int v[], int N) {
  int i = 0;
  while (l && i < N) {
    v[i++] = l->valor;
    l = l->prox;
  }
  return i;
}

/* -------------- 23 --------------- */
LInt arrayToList(int v[], int N) {
  LInt novo, *e = &novo;
  int i;
  for (i = 0; i < N; i++) {
    (*e) = malloc(sizeof(struct lligada));
    (*e)->valor = v[i];
    e = &((*e)->prox);
  }
  if (i != 0)
    *e = NULL;
  else
    novo = NULL;
  return novo;
}

/* -------------- 24 --------------- */
LInt somasAcL(LInt l) {
  LInt novo, *e = &novo;
  int soma = 0;
  while (l) {
    soma += l->valor;
    (*e) = malloc(sizeof(struct lligada));
    (*e)->valor = soma;
    e = &((*e)->prox);
    l = l->prox;
  }

  if (soma != 0)
    *e = NULL;
  else
    novo = NULL;
  return novo;
}

/* -------------- 25 --------------- */
void remreps(LInt l) {
  if (l) {
    while (l->prox) {
      if (l->prox->valor == l->valor) {
        LInt temp = l->prox;
        l->prox = l->prox->prox;
        free(temp);
      } else
        l = l->prox;
    }
  }
}

/* -------------- 26 --------------- */
LInt rotateL(LInt l) {
  if (!l || !(l->prox))
    return l;
  LInt temp = l;
  LInt list = l->prox;
  while (temp->prox)
    temp = temp->prox;
  temp->prox = l;
  l->prox = NULL;
  return list;
}

/* -------------- 27 --------------- */
LInt parte(LInt l) {
  if (!l || !l->prox)
    return NULL;
  LInt newL = l->prox;
  l->prox = l->prox->prox;
  newL->prox = parte(l->prox);
  return newL;
}

/* -------------- Arvores binarias --------------- */
typedef struct nodo {
  int valor;
  struct nodo *esq, *dir;
} * ABin;

/* -------------- 28 --------------- */
int altura(ABin a) {
  if (!a)
    return 0;
  int left = altura(a->esq);
  int rigth = altura(a->dir);
  return left > rigth ? ++left : ++rigth;
}

/* -------------- 29 --------------- */
ABin cloneAB(ABin a) {
  if (!a)
    return NULL;
  ABin clone = malloc(sizeof(struct nodo));
  clone->valor = a->valor;
  clone->esq = cloneAB(a->esq);
  clone->dir = cloneAB(a->dir);
  return clone;
}

/* -------------- 30 -------------- */
void mirror(ABin *a) {
  if (!(*a))
    return;
  ABin temporario = (*a)->dir;
  (*a)->dir = (*a)->esq;
  (*a)->esq = temporario;
  mirror(&((*a)->esq));
  mirror(&((*a)->dir));
}

/* -------------- 31 -------------- */
void inorder_aux(ABin a, LInt *l) {
  if (!a)
    return;
  inorder_aux(a->dir, l);

  LInt novo = malloc(sizeof(struct lligada));
  novo->valor = a->valor;
  novo->prox = *l;
  *l = novo;

  inorder_aux(a->esq, l);
}

void inorder(ABin a, LInt *l) {
  *l = NULL;
  inorder_aux(a, l);
}

/* -------------- 32 -------------- */
void preorder_aux(ABin a, LInt *l) {
  if (!a)
    return;

  preorder_aux(a->dir, l);
  preorder_aux(a->esq, l);

  LInt novo = malloc(sizeof(struct lligada));
  novo->valor = a->valor;
  novo->prox = *l;
  *l = novo;
}

void preorder(ABin a, LInt *l) {
  *l = NULL;
  preorder_aux(a, l);
}

/* -------------- 33 -------------- */
void posorder_aux(ABin a, LInt *l) {
  if (!a)
    return;

  LInt novo = malloc(sizeof(struct lligada));
  novo->valor = a->valor;
  novo->prox = *l;
  *l = novo;

  posorder_aux(a->dir, l);
  posorder_aux(a->esq, l);
}

void posorder(ABin a, LInt *l) {
  *l = NULL;
  posorder_aux(a, l);
}

/* -------------- 34 -------------- */
int depth(ABin a, int x) {
  if (!a)
    return -1;
  if (a->valor == x)
    return 1;

  int left = depth(a->esq, x), right = depth(a->dir, x);

  if (left == -1 && right == -1)
    return -1;
  if (left == -1)
    return right + 1;
  if (right == -1)
    return left + 1;
  return left > right ? right + 1 : left + 1;
}

/* -------------- 35 -------------- */
int freeAB(ABin a) {
  int count = 0;
  if (!a)
    return count;
  if (a->dir)
    count += freeAB(a->dir);
  if (a->esq)
    count += freeAB(a->esq);
  free(a);

  return count + 1;
}

/* -------------- 36 -------------- */
int pruneAB(ABin *a, int l) {
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

/* -------------- 37 -------------- */
int iguaisAB(ABin a, ABin b) {
  if (!a && !b)
    return 1;
  if ((!a && b) || (a && !b))
    return 0;
  return (a->valor == b->valor) && iguaisAB(a->esq, b->esq) &&
         iguaisAB(a->dir, b->dir);
}

/* -------------- 38 -------------- */
LInt concat(LInt a, LInt b) {
  if (!a)
    return b;
  LInt e = a;
  while (e->prox)
    e = e->prox;
  e->prox = b;
  return a;
}

LInt nivelL(ABin a, int n) {
  if (!a || n < 1)
    return NULL;

  if (n == 1) {
    LInt new = malloc(sizeof(struct lligada));
    new->valor = a->valor;
    new->prox = NULL;
    return new;
  } else
    return concat(nivelL(a->esq, n - 1), nivelL(a->dir, n - 1));
}

/* -------------- 39 -------------- */
int nivelV(ABin a, int n, int v[]) {
  if (!a || n < 1)
    return 0;

  if (n == 1) {
    v[0] = a->valor;
    return 1;
  } else {
    int l = nivelV(a->esq, n - 1, v);
    l += nivelV(a->dir, n - 1, v + l);
    return l;
  }
}

/* -------------- 40 -------------- */
int dumpAbin(ABin a, int v[], int N) {
  if (!a || N < 1)
    return 0;
  int i = dumpAbin(a->esq, v, N);
  N = N - i;
  if (N > 0) {
    v[i] = a->valor;
    N--;
    i++;
  }
  i += dumpAbin(a->dir, v + i, N);
  return i;
}

/* -------------- 41 -------------- */
ABin somasAcA(ABin a) {
  if (!a)
    return NULL;
  ABin novo = malloc(sizeof(struct nodo));
  novo->esq = somasAcA(a->esq);
  novo->dir = somasAcA(a->dir);
  novo->valor = a->valor + (novo->esq ? novo->esq->valor : 0) +
                (novo->dir ? novo->dir->valor : 0);
  return novo;
}

/* -------------- 42 -------------- */
int contaFolhas(ABin a) {
  if (!a)
    return 0;
  if (!a->dir && !a->esq)
    return 1;
  return contaFolhas(a->esq) + contaFolhas(a->dir);
}

/* -------------- 43 -------------- */
ABin cloneMirror(ABin a) {
  if (!a)
    return NULL;
  ABin new = malloc(sizeof(struct nodo));
  new->valor = a->valor;
  new->esq = cloneMirror(a->dir);
  new->dir = cloneMirror(a->esq);
  return new;
}

/* -------------- 44 -------------- */
int addOrd(ABin *a, int x) {
  while (*a) {
    if ((*a)->valor == x)
      return 1;
    a = (*a)->valor > x ? &((*a)->esq) : &((*a)->dir);
  }
  ABin new = malloc(sizeof(struct nodo));
  new->valor = x;
  new->esq = new->dir = NULL;
  (*a) = new;
  return 0;
}

/* -------------- 45 -------------- */
int lookupAB(ABin a, int x) {
  while (a) {
    if (a->valor == x)
      return 1;
    a = a->valor > x ? a->esq : a->dir;
  }
  return 0;
}

/* -------------- 46 -------------- */
int depthOrd(ABin a, int x) {
  int i = 1;
  while (a) {
    if (a->valor == x)
      return i;
    a = a->valor > x ? a->esq : a->dir;
    i++;
  }
  return -1;
}

/* -------------- 47 -------------- */
int maiorAB(ABin a) {
  if (!a)
    return -1;
  while (a->dir) {
    a = a->dir;
  }
  return a->valor;
}

/* -------------- 48 -------------- */
void removeMaiorA(ABin *a) {
  if (!*a)
    return;
  while ((*a)->dir) {
    a = &(*a)->dir;
  }
  ABin l = *a;
  free(*a);
  *a = l->esq;
}

/* -------------- 49 -------------- */
int quantosMaiores(ABin a, int x) {
  if (!a)
    return 0;
  if (a->valor <= x)
    return quantosMaiores(a->dir, x);
  else
    return 1 + quantosMaiores(a->esq, x) + quantosMaiores(a->dir, x);
}

/* -------------- 50 -------------- */
void listToBTree(LInt l, ABin *a) {
  if (!l)
    return;
  ABin new = malloc(sizeof(struct nodo));
  int meio = length(l) / 2;
  LInt temp = l, prev = NULL;
  int i;
  for (i = 0; i < meio; i++) {
    prev = temp;
    temp = temp->prox;
  }
  new->valor = temp->valor;
  new->esq = new->dir = NULL;
  if (prev)
    prev->prox = NULL;

  if (l != temp)
    listToBTree(l, &(new->esq));
  if (temp->prox)
    listToBTree(temp->prox, &(new->dir));
  (*a) = new;
}

/* -------------- 51 -------------- */
// nao foi feita por mim
// pregui??a
int deProcuraAux(ABin a, int x, int maior) {
  if (!a)
    return 1;
  if ((maior && a->valor < x) || (!maior && a->valor > x))
    return 0;
  return deProcuraAux(a->esq, x, maior) && deProcuraAux(a->dir, x, maior);
}

int deProcura(ABin a) {
  if (!a)
    return 1;
  int b = deProcuraAux(a->esq, a->valor, 0) && deProcura(a->esq);
  int c = deProcuraAux(a->dir, a->valor, 1) && deProcura(a->dir);
  return b && c;
}

/* -------------- MAIN --------------- */
int main(void) {
  printf("Helloooo\n");
  return 0;
}
