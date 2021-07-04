#include <stdio.h>

void vertical(int n) {
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      putchar('#');
    }
    putchar('\n');
  }

  for (int i = n; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      putchar('#');
    }
    putchar('\n');
  }
}
