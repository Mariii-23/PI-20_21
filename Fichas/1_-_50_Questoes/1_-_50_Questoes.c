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
    for (j = 0; s[j] != '\0'; j++) {
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

/* -------------- main ---------------- */
int main(void) {
  exec_menu();
  return 0;
}
