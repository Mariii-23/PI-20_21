#include <stdbool.h> // boolean
#include <stdio.h>
#include <stdlib.h> // malloc
#include <string.h>

#include "menu.h"
#define SIZE 1024

unsigned int read_unsigned_int() {
  printf("Introduza o número a ser analisado: ");
  unsigned int input = 0;
  scanf("%u", &input);
  return input;
}

int *read_array(int *n) {
  printf("Número do comprimento\n");
  *n = read_unsigned_int();
  int *arr = (int *)malloc(SIZE * sizeof(int));
  printf("Introduza os elementos\n");
  for (int i = 0; i < *n; i++) {
    arr[i] = read_unsigned_int();
  }
  return arr;
}

void show_arr(int *arr, int n) {
  for (int i = 0; i < n; i++)
    printf(" %d ", arr[i]);
  putchar('\n');
}

/* -------------- 1 ---------------- */
int ex1() {
  int max = 0;
  printf("Introduza um conjunto de número.\nA leitura terminará quando receber "
         "um 0.\n");

  int input = -1;
  while (input != 0) {
    printf("\nIntroduza o número: ");
    scanf("%d", &input);
    if (input > max)
      max = input;
  }

  printf("O maior número da sequência introduzida é %d\n", max);

  return max;
}

/* -------------- 2 ---------------- */
double ex2() {
  double mean = 0, number = 0;
  printf("Introduza um conjunto de número.\nA leitura terminará quando receber "
         "um 0.\n");

  double input = -1;
  do {
    printf("\nIntroduza o número: ");
    scanf("%le", &input);
    mean = (mean * number + input) / (number + 1);
    number++;
  } while (input != 0);

  printf("A média da sequência introduzida é %f\n", mean);

  return mean;
}

/* -------------- 3 ---------------- */
int ex3() {
  int max[2] = {0}, input = -1;
  printf("Introduza um conjunto de número.\nA leitura terminará quando receber "
         "um 0.\n");
  while (input != 0) {
    printf("\nIntroduza o número: ");
    scanf("%d", &input);
    if (input > max[0]) {
      max[1] = max[0];
      max[0] = input;
    } else if (input > max[1]) {
      max[1] = input;
    }
  }
  printf("O segundo maior número da sequência introduzida é %d\n", max[1]);
  return max[1];
}

/* -------------- 4 ---------------- */
int bitsUm(unsigned int n) {
  int res = 0;
  while (n != 0) {
    if (n % 2 != 0)
      ++res;
    n /= 2;
  }
  return res;
}

void ex4() { printf("Existem %d números 1\n", bitsUm(read_unsigned_int())); }

/* -------------- 5 ---------------- */
// passa nos testes mas ver melhor
int trailingZ(unsigned int n) {
  if (n == 0)
    return 32;
  int res = 0;
  int fail = 0;
  while (!fail && n != 0) {
    if (n % 2 == 0)
      ++res;
    else
      fail = 1;
    n /= 2;
  }
  return res;
}

void ex5() { printf("Existem %d números 0\n", trailingZ(read_unsigned_int())); }

/* -------------- 6 ---------------- */
int qDig(unsigned int n) {
  int res = 0;
  while (n != 0) {
    n /= 10;
    res++;
  }
  return res;
}

void ex6() {
  unsigned int input = read_unsigned_int();
  printf("São necessários %d digitos para escrever o número inteiro %d em casa "
         "decimal\n",
         qDig(input), input);
}

/* -------------- 7 ---------------- */
char *mystrcat(char s1[], char s2[]) {
  int size = 1, used = 0, j;
  char *result = (char *)malloc(size * sizeof(char));

  for (j = 0; s1[j] != '\0'; j++) {
    if (used == size) {
      size *= 2;
      result = (char *)realloc(result, size * sizeof(char));
    }
    result[used++] = s1[j];
  }

  for (j = 0; s2[j] != '\0'; j++) {
    if (used == size) {
      size *= 2;
      result = (char *)realloc(result, size * sizeof(char));
    }
    result[used++] = s2[j];
  }

  if (used == size) {
    result = (char *)realloc(result, (size + 1) * sizeof(char));
  }
  result[used] = '\0';

  return result;
}

void ex7() {
  char first[64], second[64];
  printf("First word: ");
  scanf("%s", first);
  printf("Second word: ");
  scanf("%s", second);
  char *resul = mystrcat(first, second);
  printf("%s", resul);
  free(resul);
}

/* -------------- 8 ---------------- */
char *my_strcpy(char *dest, char source[]) {
  int size = 1, used = 0, j;
  dest = (char *)malloc(size * sizeof(char));

  for (j = 0; source[j] != '\0'; j++) {
    if (used == size) {
      size *= 2;
      dest = (char *)realloc(dest, size * sizeof(char));
    }
    dest[used++] = source[j];
  }

  if (used == size) {
    dest = (char *)realloc(dest, (size + 1) * sizeof(char));
  }
  dest[used] = '\0';

  return dest;
}

void ex8() {
  char word[64];
  printf("Word to copy: ");
  scanf("%s", word);
  char *resul = NULL;
  resul = my_strcpy(resul, word);
  printf("%s\n", resul);
  free(resul);
}

/* -------------- 9 ---------------- */
int mystrcmp(char s1[], char s2[]) {
  int i;
  for (i = 0; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; i++)
    ;

  if (s1[i] != '\0' && s2[i] != '\0')
    return s1[i] - s2[i];
  else if (s1[i] == '\0')
    return -s2[i];
  else
    return s1[i];
}

void ex9() {
  char first[64], second[64];
  printf("First word: ");
  scanf("%s", first);
  printf("Second word: ");
  scanf("%s", second);
  int res = mystrcmp(first, second);
  char sinal;
  if (res == 0)
    sinal = '=';
  else if (res > 0)
    sinal = '>';
  else
    sinal = '<';

  printf("%s %c %s\n", first, sinal, second);
}

/* -------------- 10 ---------------- */
// .
char *my_strstr(char s1[], char s2[]) {
  if (s1[0] == '\0' || s2[0] == '\0')
    return s1;
  while (s1 != NULL && s1[0] != '\0') {
    if (s1[0] == s2[0]) {
      int j;
      for (j = 0; s1[j] != '\0' && s2[j] != '\0' && s1[j] == s2[j]; j++)
        ;
      if (s2[j] == '\0')
        return s1;
    }
    s1++;
  }
  return NULL;
}
// so da com palavras
// falta por a receber strings
void ex10() {
  char first[SIZE], second[SIZE];
  printf("String s1:\n");
  scanf("%s", first);
  printf("\nString s2\n");
  scanf("%s", second);
  char *res = my_strstr(first, second);
  printf("%s\n", res);
}

/* -------------- 11 ---------------- */
void strrev(char s[]) {
  int len = strlen(s) - 1, mean = len / 2;
  char aux;
  int i;
  for (i = 0; i <= mean; i++) {
    aux = s[i];
    s[i] = s[len - i];
    s[len - i] = aux;
  }
}

void ex11() {
  char input[SIZE];
  printf("Word:\n");
  scanf("%s", input);
  strrev(input);
  printf("%s", input);
}

/* -------------- 12 ---------------- */
void strnov(char s[]) {
  if (!s)
    return;
  int j = 0;
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] != 'a' && s[i] != 'A' && s[i] != 'e' && s[i] != 'E' &&
        s[i] != 'i' && s[i] != 'I' && s[i] != 'o' && s[i] != 'O' &&
        s[i] != 'u' && s[i] != 'U') {
      s[j++] = s[i];
    }
  }
  s[j] = '\0';
}

void ex12() {
  char input[SIZE];
  printf("Word:\n");
  scanf("%s", input);
  // fgets(input, sizeof(input), stdin);
  strnov(input);
  printf("%s\n", input);
}

/* -------------- 13---------------- */
void truncW(char t[], int n) {
  if (!t)
    return;
  int i = 0, j = 0, count = 0;

  while (t[i] != '\0') {
    if (t[i] == ' ') {
      count = 0;
      i++;
      t[j++] = ' ';
    } else {
      if (count < n) {
        t[j++] = t[i++];
        count++;
      } else {
        i++;
      }
    }
  }

  t[j] = '\0';
}

void ex13() {
  printf("Example\n");
  char s1[SIZE] = "a   bb ccccccccccccc d";
  printf("s1: %s\n", s1);
  truncW(s1, 1);
  printf("s1: %s||\n", s1);

  char input[SIZE];
  printf("Word:\n");
  scanf("%s", input);
  unsigned int number = 0;
  printf("Number:\n");
  scanf("%u", &number);
  truncW(input, number);
  printf("%s\n", input);
}

/* -------------- 14 ---------------- */
char charMaisfreq(char s[]) {
  char max = '\0';
  unsigned int max_count = 0;
  int i, j;
  for (i = 0; s[i] != '\0'; i++) {
    unsigned int count = 0;
    for (j = i; s[j] != '\0'; j++) {
      if (s[j] == s[i])
        count++;
    }
    if (max_count < count) {
      max_count = count;
      max = s[i];
    }
  }
  return max;
}

void ex14() {
  printf("Example\n");
  char s1[SIZE] = "a   bb ccccccccccccc d";
  printf("s1: %s\n", s1);
  printf("%c\n", charMaisfreq(s1));

  char input[SIZE];
  printf("Word:\n");
  scanf("%s", input);
  printf("%c\n", charMaisfreq(input));
}

/* -------------- 15 ---------------- */
int iguaisConsecutivos(char s[]) {
  if (!s || s[0] == '\0')
    return 0;

  int max = 0, count = 1;
  char last = s[0];
  int i;
  for (i = 1; s[i] != '\0'; i++) {
    if (s[i] == last) {
      count++;
    } else {
      if (max < count)
        max = count;
      last = s[i];
      count = 1;
    }
  }
  if (max < count)
    max = count;
  return max;
}

void ex15() {
  char input[SIZE];
  printf("Word:\n");
  scanf("%s", input);
  printf("Iguais consecutivos: %d\n", iguaisConsecutivos(input));
}

/* -------------- 16 ---------------- */
//.
bool existe_array(char s[], int n, char elem) {
  bool fail = false;
  for (int i = 0; !fail && i < n; i++) {
    if (elem == s[i])
      fail = true;
  }
  return fail;
}

int diffConsecutivos(char s[]) {
  if (!s || s[0] == '\0')
    return 0;

  int max = 0, count = 0;
  int len = strlen(s) - 1;
  char last = '\0';
  char *arr = malloc(len * (sizeof(char *)));

  int i;
  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] == ' ')
      continue;
    if (s[i] != last) {
      if (!existe_array(s, count, s[i])) {
        arr[count] = s[i];
        count++;
      }
      last = s[i];
    } else {
      if (max < count)
        max = count;
      arr[0] = s[i];
      count = 1;
    }
  }
  if (max < count)
    max = count;
  free(arr);
  return max;
}

void ex16() {
  char input[SIZE];
  printf("Word:\n");
  scanf("%s", input);
  printf("\nDiferentes consecutivos: %d\n", diffConsecutivos(input));
}

/* -------------- 17 ---------------- */
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

void ex17() {
  char first[SIZE], second[SIZE];
  printf("String s1:\n");
  scanf("%s", first);
  printf("\nString s2\n");
  scanf("%s", second);
  printf("\nO comprimento do maior prefixo é %d\n",
         maiorPrefixo(first, second));
}

/* -------------- 18 ---------------- */
int maiorSufixo(char s1[], char s2[]) {
  int i, x, resultado = 0;

  for (i = 0; s1[i] != '\0' && s1[i + 1] != '\0'; i++)
    ;
  for (x = 0; s2[x] != '\0' && s2[x + 1] != '\0'; x++)
    ;

  while (i >= 0 && x >= 0 && s1[i] == s2[x]) {
    i--;
    x--;
    resultado++;
  }
  return resultado;
}

void ex18() {
  char first[SIZE], second[SIZE];
  printf("String s1:\n");
  scanf("%s", first);
  printf("\nString s2\n");
  scanf("%s", second);
  printf("\nO comprimento do maior sufixo é %d\n", maiorSufixo(first, second));
}

/* -------------- 19 ---------------- */
int sufPref(char s1[], char s2[]) {
  int max = 0, count;
  int i = 0, j = 0;

  while (s1[i] != '\0') {
    count = 0;
    j = 0;

    for (; s1[i] != '\0' && s1[i] != s2[j]; i++)
      ;

    while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j]) {

      count++;

      i++;
      j++;
    }
    if (count > max && s1[i] == '\0')
      max = count;
  }

  return max;
}

void ex19() {
  char first[SIZE], second[SIZE];
  printf("String s1:\n");
  scanf("%s", first);
  printf("\nString s2\n");
  scanf("%s", second);
  printf("\nO comprimento do maior sufixo de s1 que é prefixo de s2 é %d\n",
         sufPref(first, second));
}

/* -------------- 20 ---------------- */
int contaPal(char s[]) {
  int i = 0, palavras = 0;
  char last = '\0';
  for (; s[i] != '\0'; i++) {
    if (s[i] != ' ' && (last == '\0' || last == ' '))
      palavras++;
    last = s[i];
  }
  return palavras;
}

void ex20() {
  char *example = "Isto é um exempplo a a bbb";
  printf("Exemplo:\n%s\n", example);
  printf("Existem %d palavras\n\n", contaPal(example));
  char first[SIZE];
  printf("String s1:\n");
  scanf("%s", first);
  printf("\nExistem %d palavras\n", contaPal(first));
}

/* -------------- 21---------------- */
bool isVogal(char s) {
  return s == 'a' || s == 'A' || s == 'e' || s == 'E' || s == 'i' || s == 'I' ||
         s == 'o' || s == 'O' || s == 'u' || s == 'U';
}

int contaVogais(char s[]) {
  int count = 0;
  for (int i = 0; s[i] != '\0'; i++)
    if (isVogal(s[i]))
      count++;
  return count;
}

void ex21() {
  char *example = "Isto é um exempplo a a bbb";
  printf("Exemplo:\n%s\n", example);
  printf("Existem %d vogais\n\n", contaVogais(example));
  char first[SIZE];
  printf("String s1:\n");
  scanf("%s", first);
  printf("\nExistem %d vogais\n", contaVogais(first));
}

/* -------------- 22---------------- */
int contida(char a[], char b[]) {
  int i = 0, j = 0, espacos1 = 0, espacos2 = 0;
  int find = 0;
  while (a[j] != '\0' && b[i] != '\0') {
    find = 0;
    for (; b[i] != '\0' && a[j] != '\0'; i++) {
      if (b[i] == ' ')
        espacos2 = 1;
      if (a[j] == b[i]) {
        j++;
        find = 1;
      }
    }
    while (a[j] != '\0' && a[j] == ' ') {
      j++;
      espacos1 = 1;
    }
    if (b[i] == '\0' && a[j] != '\0' && find)
      i = 0;
  }
  return a[j] == '\0' &&
         (espacos2 == espacos1 || (espacos1 == 0 && espacos2 == 1));
}

void ex22() {
  char *example = "\"Braga\" \"Bracara augusta\"";
  printf("Exemplo:\n%s\n", example);
  printf("A primeira string encontra se contida na segunda: %d\n\n",
         contida("Braga", "Bracara augusta"));

  char first[SIZE], second[SIZE];
  printf("String s1:\n");
  scanf("%s", first);
  printf("\nString s2\n");
  scanf("%s", second);
  printf("A primeira string encontra se contida na segunda: %d\n\n",
         contida(first, second));
}

/* -------------- 23 ---------------- */
int palindroma(char s[]) {
  int len = strlen(s) - 1, mean = len / 2;
  int fail = 1;
  int i;
  for (i = 0; i <= mean && fail; i++) {
    fail = s[i] == s[len - i];
  }
  return fail;
}

void ex23() {
  char *example = "saias";
  printf("Exemplo:\n%s\n", example);
  printf("A palavra é palindroma: %d\n\n", palindroma(example));
  char first[SIZE];
  printf("String s1:\n");
  scanf("%s", first);
  printf("A palavra é palindroma: %d\n\n", palindroma(first));
}

/* -------------- 24 ---------------- */
int remRep(char x[]) {
  int i, j = 0;
  char last = '\0';
  for (i = 0; x[i] != '\0'; i++) {
    if (last != x[i]) {
      x[j] = x[i];
      j++;
      last = x[i];
    }
  }
  if (i != j)
    x[j] = '\0';
  return j;
}

void ex24() {
  char example[SIZE] = "aaaa bbb bcjafd aaaaa";
  printf("Exemplo:\n%s\n", example);
  remRep(example);
  printf("String sem sucessivas repetições: %s\n\n", example);
  char first[SIZE];
  printf("String s1:\n");
  scanf("%s", first);
  remRep(first);
  printf("String sem sucessivas repetições: %s\n\n", first);
}

/* -------------- 25 ---------------- */
int limpaEspacos(char x[]) {
  int i, j = 0;
  char last = '\0';
  for (i = 0; x[i] != '\0'; i++) {
    if (x[i] != ' ') {
      x[j] = x[i];
      j++;
    } else if (last != ' ') {
      x[j] = x[i];
      j++;
    }
    last = x[i];
  }
  if (j != i)
    x[j] = '\0';
  return j;
}

void ex25() {
  char example[SIZE] = "  aaaa  bbb bcjafd    aaaaa";
  printf("Exemplo:\n%s\n", example);
  limpaEspacos(example);
  printf("String sem sucessivas repetições: %s\n\n", example);
  char first[SIZE];
  printf("String s1:\n");
  scanf("%s", first);
  limpaEspacos(first);
  printf("String sem sucessivos espacos: %s\n\n", first);
}

/* -------------- 26 ---------------- */
void insere(int v[], int N, int x) {
  int i;
  for (i = N - 1; v[i] >= x && i >= 0; i--)
    v[i + 1] = v[i];
  v[i + 1] = x;
}

void ex26() {
  int example[20] = {1, 2, 4, 4, 6, 7, 8, 14, 20};
  int n = 9;
  printf("\nExemplos\n");

  printf("\nInserir 23\n");
  show_arr(example, n);
  insere(example, n, 23);
  n++;
  show_arr(example, n);

  printf("\nInserir 4\n");
  show_arr(example, n);
  insere(example, n, 4);
  n++;
  show_arr(example, n);

  printf("\nInserir 0\n");
  show_arr(example, n);
  insere(example, n, 0);
  n++;
  show_arr(example, n);
}

/* -------------- 27 ---------------- */
// humm humm +-
void merge(int r[], int a[], int b[], int na, int nb) {
  int ia = 0, ib = 0, ir = 0;

  while (ia < na && ib < nb) {
    if (a[ia] > b[ib]) {
      r[ir] = b[ib++];
    } else {
      r[ir] = a[ia++];
    }
    ir++;
  }
  if (ia == na) {
    for (; ib < nb; ib++, ir++)
      r[ir] = b[ib];
  } else {
    for (; ib < na; ia++, ir++)
      r[ir] = a[ia];
  }
}

/* -------------- 28 ---------------- */
int crescente(int a[], int i, int j) {
  int fail = 1;
  for (; i < j && fail; i++) {
    fail = a[i] <= a[i + 1];
  }
  return fail;
}

void ex28() {
  int n;
  int *arr = read_array(&n);
  printf("Posicao inicial: \n");
  int i = read_unsigned_int();
  printf("Posicao final: \n");
  int j = read_unsigned_int();
  if (i > j || i < 0 || j < 0 || j > n) {
    printf("Posicoes invalidas\n");
    return;
  }
  show_arr(arr, n);
  printf("Entre %d %d é crescente %d\n", i, j, crescente(arr, i, j));
  free(arr);
}

/* -------------- 29 ---------------- */
int retiraNeg(int v[], int n) {
  int i, j = 0;
  for (i = 0; i < n; i++) {
    if (v[i] >= 0) {
      v[j++] = v[i];
    }
  }
  return j;
}

void ex29() {
  int example[9] = {-1, 2, -4, 4, 6, -7, -8, 14, -20};
  int n = 9;
  printf("\nExemplos\n");
  show_arr(example, n);
  n = retiraNeg(example, n);
  show_arr(example, n);
}

/* -------------- 30 --------------- */
int menosFreq(int v[], int n) {
  if (n <= 0)
    return 0;
  int menosFreq = v[0], count;
  int min = 0, i, aux;
  for (i = 0; i < n && v[i] == menosFreq; i++, min++)
    ;
  while (i < n) {
    count = 0;
    aux = v[i];
    for (; i < n && v[i] == aux; i++, count++)
      ;
    if (count < min) {
      min = count;
      menosFreq = aux;
    }
  }
  return menosFreq;
}

void ex30() {
  int n;
  int *arr = read_array(&n);
  show_arr(arr, n);
  printf("Menos frequente : %d\n", menosFreq(arr, n));
  free(arr);
}

/* -------------- 31 --------------- */
int maisFreq(int v[], int n) {
  if (n <= 0)
    return 0;
  int maisFreq = v[0], count;
  int max = 0, i, aux;
  for (i = 0; i < n && v[i] == maisFreq; i++, max++)
    ;
  while (i < n) {
    count = 0;
    aux = v[i];
    for (; i < n && v[i] == aux; i++, count++)
      ;
    if (count > max) {
      max = count;
      maisFreq = aux;
    }
  }
  return maisFreq;
}

void ex31() {
  int n;
  int *arr = read_array(&n);
  show_arr(arr, n);
  printf("Mais frequente : %d\n", maisFreq(arr, n));
  free(arr);
}

/* -------------- 32 --------------- */
int maxCresc(int v[], int n) {
  if (n <= 0)
    return 0;
  int max = 0, i = 0, count;
  while (i < n) {
    count = 1;
    for (; i < n && v[i] > v[i + 1]; i++)
      ;

    for (; i < n && v[i] <= v[i + 1]; i++, count++)
      ;
    if (count > max) {
      max = count;
    }
  }
  return max;
}
void ex32() {
  int n;
  int *arr = read_array(&n);
  show_arr(arr, n);
  printf("Máximo frequente : %d\n", maxCresc(arr, n));
  free(arr);
}

/* -------------- 33 --------------- */
int elimElem(int v[], int n, int x, int i) {
  if (n <= 0)
    return 0;
  int j = i;

  while (i < n) {
    if (x != v[i]) {
      v[j] = v[i];
      j++;
    }
    i++;
  }
  return j;
}

int elimRep(int v[], int n) {
  if (n <= 0)
    return 0;
  int i = 0;
  for (; i < n; i++) {
    n = elimElem(v, n, v[i], i + 1);
  }
  return n;
}

void ex33() {
  int n;
  int *arr = read_array(&n);
  show_arr(arr, n);
  n = elimRep(arr, n);
  show_arr(arr, n);
  free(arr);
}

/* -------------- 34 --------------- */
int elimRepOrd(int v[], int n) {
  if (n <= 0)
    return 0;
  int i = 1, j = 1;
  int last = v[0];
  for (; i < n; i++) {
    if (last != v[i]) {
      last = v[i];
      v[j] = v[i];
      j++;
    }
  }
  return j;
}

void ex34() {
  int n;
  int *arr = read_array(&n);
  show_arr(arr, n);
  n = elimRepOrd(arr, n);
  show_arr(arr, n);
  free(arr);
}

/* -------------- main ---------------- */
int main(void) {
  exec_menu();
  return 0;
}
