#include "menu.h"

#include <stdio.h>

#include "1_-_50_Questoes.h"

/* -------------------MENU---------------------------- */
void show_menu_1_10() {
  printf("\n\n--------------------MENU-------------------------\n");
  printf("0.  Go back\n");
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

void show_menu_11_20() {
  printf("\n\n--------------------MENU-------------------------\n");
  printf("0.  Go back\n");
  printf("11. Inverte um string\n");
  printf("12. Retira todas as vogais de uma string\n");
  printf("13. Dado um texto t com várias palavras (as palavras estão separadas "
         "em t por um ou mais espaços) e um inteiro n, trunca todas as "
         "palavras de forma a terem no máximo n caracteres.\n");
  printf("14. Determinar o caracter mais frequente numa dada string\n");
  printf("15. Determinar o máximo de caracter iguais consecutivos numa dada "
         "string\n");
  printf(
      "16. Determinar o máximo de caracter diferentes consecutivos numa dada "
      "string\n");
  printf("17. Calcula o maior sufixo comum entre duas strings\n");
  printf("18. Calcula o maior prefixo comum entre duas strings\n");
  printf("19. Calcula o maior prefixo de s1 que é sufixo de s2 entre duas "
         "strings\n");
  printf("20. Calcula quantas palavras existem numa certa string\n");
  printf("-------------------------------------------------\n");
}

void show_menu_21_30() {
  printf("\n\n--------------------MENU-------------------------\n");
  printf("0.  Go back\n");
  printf("21. Calcula quantas vogais existem numa certa string\n");
  printf("22. Verifica se a primeira string encontra-se contida na segunda "
         "string\n");
  printf("23. Testa se uma dada palavra é palíndrome\n");
  printf("24. Elimina de uma dada string todos os caracteres sucessivos.\n");
  printf("25. Elimina de uma dada string todos os espaços sucessivos.\n");
  printf("26. Insere um elemento num vetor ordenado\n");
  printf("27. \n");
  printf(
      "28. Verifica se um dado array é crescente entre duas posições dadas\n");
  printf("29. Retira todos os elementos negativos de um dado array\n");
  printf("30. Calcula o elementos menos frequente num dado array\n");
  printf("-------------------------------------------------\n");
}

void show_menu_31_40() {
  printf("\n\n--------------------MENU-------------------------\n");
  printf("0.  Go back\n");
  printf("31. Calcula o elementos mais frequente num dado array\n");
  printf("32. Calcula o comprimento da maior sequência crescente de um dado "
         "array\n");
  printf("33. Dado um determinado array, elimina elementos repetidos\n");
  printf(
      "34. Dado um determinado array ordenado, elimina elementos repetidos\n");
  printf("35. \n");
  printf("36. \n");
  printf("37. \n");
  printf("38. \n");
  printf("39. \n");
  printf("40. \n");
  printf("-------------------------------------------------\n");
}

void show_menu_41_50() {
  printf("\n\n--------------------MENU-------------------------\n");
  printf("0.  Go back\n");
  printf("41. \n");
  printf("42. \n");
  printf("43. \n");
  printf("44. \n");
  printf("45. \n");
  printf("46. \n");
  printf("47. \n");
  printf("48. \n");
  printf("49. \n");
  printf("50. \n");
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

void exec_questions_11_20(int option) {
  switch (option) {
  case 0:
    printf("Exit sucedd\n");
    break;
  case 11:
    ex11();
    break;
  case 12:
    ex12();
    break;
  case 13:
    ex13();
    break;
  case 14:
    ex14();
    break;
  case 15:
    ex15();
    break;
  case 16:
    ex16();
    break;
  case 17:
    ex17();
    break;
  case 18:
    ex18();
    break;
  case 19:
    ex19();
    break;
  case 20:
    ex20();
    break;
  default:
    printf("Opcao invalida\n");
  }
}

void exec_questions_21_30(int option) {
  switch (option) {
  case 0:
    printf("Exit sucedd\n");
    break;
  case 21:
    ex21();
    break;
  case 22:
    ex22();
    break;
  case 23:
    ex23();
    break;
  case 24:
    ex24();
    break;
  case 25:
    ex25();
    break;
  case 26:
    ex26();
    break;
  case 27:
    break;
  case 28:
    ex28();
    break;
  case 29:
    ex29();
    break;
  case 30:
    ex30();
    break;
  default:
    printf("Opcao invalida\n");
  }
}

void exec_questions_31_40(int option) {
  switch (option) {
  case 0:
    printf("Exit sucedd\n");
    break;
  case 31:
    ex31();
    break;
  case 32:
    ex32();
    break;
  case 33:
    ex33();
    break;
  case 34:
    ex34();
    break;
  case 35:
    break;
  case 36:
    break;
  case 37:
    break;
  case 38:
    break;
  case 39:
    break;
  case 40:
    break;
  default:
    printf("Opcao invalida\n");
  }
}

void exec_questions_41_50(int option) {
  switch (option) {
  case 0:
    printf("Exit sucedd\n");
    break;
  case 41:
    break;
  case 42:
    break;
  case 43:
    break;
  case 44:
    break;
  case 45:
    break;
  case 46:
    break;
  case 47:
    break;
  case 48:
    break;
  case 49:
    break;
  case 50:
    break;
  default:
    printf("Opcao invalida\n");
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

void exec_menu_11_20() {
  int option = -1;
  while (option != sair) {
    show_menu_11_20();
    printf("Opcao: ");
    scanf("%d", &option);
    putchar('\n');
    exec_questions_11_20(option);
  }
}

void exec_menu_21_30() {
  int option = -1;
  while (option != sair) {
    show_menu_21_30();
    printf("Opcao: ");
    scanf("%d", &option);
    putchar('\n');
    exec_questions_21_30(option);
  }
}

void exec_menu_31_40() {
  int option = -1;
  while (option != sair) {
    show_menu_31_40();
    printf("Opcao: ");
    scanf("%d", &option);
    putchar('\n');
    exec_questions_31_40(option);
  }
}

void exec_menu_41_50() {
  int option = -1;
  while (option != sair) {
    show_menu_41_50();
    printf("Opcao: ");
    scanf("%d", &option);
    putchar('\n');
    exec_questions_41_50(option);
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
    exec_menu_11_20();
    break;
  case 3:
    exec_menu_21_30();
    break;
  case 4:
    exec_menu_31_40();
    break;
  case 5:
    exec_menu_41_50();
    break;
  default:
    printf("Opcao invalida\n");
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
