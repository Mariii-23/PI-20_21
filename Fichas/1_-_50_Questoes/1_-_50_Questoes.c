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
  strnov(input);
  printf("%s", input);
}
/* -------------- main ---------------- */
int main(void) {
  exec_menu();
  return 0;
}
