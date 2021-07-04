#include <stdio.h>
void horizontal(int n) {
  int m = n / 2;
  for (int j = m; j >= 0; j--) {
    for (int i = 0; i < j; i++) putchar(' ');
    for (int i = (m - j) * 2; i >= 0; i--) putchar('#');
    putchar('\n');
  }
}
