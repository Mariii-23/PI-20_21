#include <stdio.h>

void horizontal(int n);
void vertical(int n);

/* Estado e atribuições */
// 1.
// a) 12 16

void ex1_a() {
  int x, y;
  x = 3;
  y = x + 1;
  x = x * y;
  y = x + y;
  printf("%d %d\n", x, y);
}

// b 0 (nao conseguimos prever)
void ex1_b() {
  int x, y;
  x = 0;
  printf("%d %d\n", x, y);
}

// c)
// A 65
// B 66 2 50
// b 98
void ex1_c() {
  char a, b, c;
  a = 'A';
  b = ' ';
  c = '0';
  printf("%c %d\n", a, a);
  a = a + 1;
  c = c + 2;
  printf("%c %d %c %d\n", a, a, c, c);
  c = a + b;
  printf("%c %d\n", c, c);
}

// d)
// 300 200
void ex1_d() {
  int x, y;
  x = 200;
  y = 100;
  x = x + y;
  y = x - y;
  x = x - y;
  printf("%d %d\n", x, y);
}

void ex1() {
  printf("a:\n");
  ex1_a();
  printf("\nb:\n");
  ex1_b();
  printf("\nc:\n");
  ex1_c();
  printf("\nd:\n");
  ex1_d();
}

/* Estruturas de controlo */
// Exercise 1
//
// a)
// x=11
// y = somatorio de y_ 1 ate 11
// y = 66

void ex2_a() {
  int x, y;
  x = y = 0;
  while (x != 11) {
    x = x + 1;
    y += x;
  }
  printf("%d %d \n ", x, y);
}

// b)
// x=11
// visto que o x é sempre par, este ciclo nunca irá parar
void ex2_b() {
  int x, y;
  x = y = 0;
  while (x != 11) {
    x = x + 2;
    y += x;
  }
  printf("%d %d \n", x, y);
}

// c)
// _#_#_#_#_#_#_#_#_#_#
void ex2_c() {
  int i;
  for (i = 0; (i < 20); i++)
    if (i % 2 == 0)
      putchar('_');
    else
      putchar('#');
  putchar('\n');
}

// d)
/* abcdefg */
/* bcdefg */
/* cdefg */
/* defg */
/* efg */
/* fg */
/* g */
void ex2_d() {
  char i, j;
  for (i = 'a'; (i != 'h'); i++) {
    for (j = i; (j != 'h'); j++) putchar(j);
    putchar('\n');
  }
}

// e)
// converte um inteiro para binario
void ex2_e(int n) {
  while (n > 0) {
    if (n % 2 == 0)
      putchar('0');
    else
      putchar('1');
    n = n / 2;
  }
  putchar('\n');
}

void ex2() {
  printf("a:\n");
  ex2_a();
  printf("\nb:\n");
  printf("Ciclo infinito\n");
  // ex2_b();
  printf("\nc:\n");
  ex2_c();
  printf("\nd:\n");
  ex2_d();
  printf("\ne:\n");
  for (int i = 0; (i < 16); i++) ex2_e(i);
}

// Exercise 2
void ex3() {
  for (int i = 0; i <= 5; i++) {
    for (int j = 0; j <= 5; j++) putchar('#');
    putchar('\n');
  }
}

// Exercise 3
void ex4() {
  for (int i = 0; i <= 5; i++) {
    for (int j = 0; j <= 5; j++)
      if (i % 2 == 0) {
        if (j % 2 == 0)
          putchar('#');
        else
          putchar('_');
      }
      else {
        if (j % 2 == 0)
          putchar('_');
        else
          putchar('#');
      }
    putchar('\n');
  }
}

// Exercise 4
//
// a)
void ex5_1() {
  for (int i = 1; i <= 5; i++) {
    for (int j = 0; j < i; j++) {
      putchar('#');
    }
    putchar('\n');
  }
  for (int i = 5; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      putchar('#');
    }
    putchar('\n');
  }
}

// b)
void ex5_2() {
  for (int j = 4; j >= 0; j--) {
    for (int i = 0; i < j; i++) putchar(' ');
    for (int i = (4 - j) * 2; i >= 0; i--) putchar('#');
    /* for (int i = 0; i <= j; i++) */
    /*   putchar(' '); */
    putchar('\n');
  }
}

void ex5() {
  ex5_1();
  putchar('\n');
  ex5_2();
}

int main(void) {
  printf("-----------------------\n");
  printf("\nEstado e atribuições\n");
  printf("\nExercise 1\n");
  ex1();
  printf("-----------------------\n");
  printf("\nEstrutras de controlo\n");
  printf("\nExercise 1\n");
  ex2();
  printf("\nExercise 2\n");
  ex3();
  printf("\nExercise 3\n");
  ex4();
  printf("\nExercise 4\n");
  ex5();
  printf("\nExercise 4 from other file\n");
  for (int i = 1; i < 10; i += 2) {
    horizontal(i);
    putchar('\n');
  }

  for (int i = 2; i < 10; i++) {
    vertical(i);
    putchar('\n');
  }

  return 0;
}
