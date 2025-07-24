//FormAI DATASET v1.0 Category: Pattern printing ; Style: configurable
#include <stdio.h>

int main() {
  int rows;
  char symbol;

  // User inputs number of rows
  printf("Enter the number of rows: ");
  scanf("%d", &rows);

  // User inputs symbol
  printf("Enter a symbol to use: ");
  scanf(" %c", &symbol);

  // Configurable pattern printing
  for (int i = rows; i > 0; i--) {
    for (int j = 1; j <= rows - i; j++) {
      printf(" ");
    }
    for (int k = 1; k <= i * 2 - 1; k++) {
      printf("%c", symbol);
    }
    printf("\n");
  }

  return 0;
}