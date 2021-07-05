#include "1_-_50_Questoes.h"
#include "menu.h"
#include <stdio.h>

/* -------------------MENU---------------------------- */
void show_menu_1_10() {
  printf("\n\n--------------------MENU-------------------------\n");
  printf("0.  Exit\n");
  printf("1.  Maior de número de uma sequencia de números\n");
  printf("2.  Média de uma sequencia de números\n");
  printf("3.  Segundo maior de número de uma sequencia de números\n");
  printf("4.  Calcula o número de bits iguais a 1 usados na representação "
         "bínaria de um dado número\n");
  printf(
      "5.  Calcula o número de bits a 0 no final da representação binária de "
      "um número\n");
  printf(
      "6.  Calcula o número de dígitos necessários para escrever i inteiro n "
      "em base decimal\n");
  printf("7.  Concatenar duas strings\n");
  printf("8.  Copiar uma dada string\n");
  printf("9.  Comparar duas strings\n");
  printf("10. Devolve a posição onde a string s2 ocorre em s1\n");
  printf("-------------------------------------------------\n");
}

void exec_questions_1_10(int option) {
  switch (option) {
  case 0:
    printf("Exit sucedd\n");
    break;
  case 1:
    ex1();
    break;
  case 2:
    ex2();
    break;
  case 3:
    ex3();
    break;
  case 4:
    ex4();
    break;
  case 5:
    ex5();
    break;
  case 6:
    ex6();
    break;
  case 7:
    ex7();
    break;
  case 8:
    ex8();
    break;
  case 9:
    ex9();
    break;
  case 10:
    ex10();
    break;
  default:
    printf("Opção inválida");
    break;
  }
}

void exec_menu_1_10() {
  int option = -1;

  while (option != sair) {
    show_menu_1_10();
    printf("Opcao: ");
    scanf("%d", &option);
    putchar('\n');
    exec_questions_1_10(option);
  }
}

void exec_questions(int option) {
  switch (option) {
  case 0:
    printf("Exit sucedd\n");
    break;
  case 1:
    exec_menu_1_10();
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  }
}

void exec_menu() {
  int option = -1;
  do {
    printf("\n\n--------------------MENU-------------------------\n");
    printf("0. Sair\n");
    printf("1. Questões 1-10\n");
    printf("2. Questões 11-20\n");
    printf("3. Questões 21-30\n");
    printf("4. Questões 31-40\n");
    printf("5. Questões 41-50\n");
    printf("-------------------------------------------------\n");
    printf("Opcao: ");
    scanf("%d", &option);
    putchar('\n');
    exec_questions(option);
  } while (option != sair);
}
