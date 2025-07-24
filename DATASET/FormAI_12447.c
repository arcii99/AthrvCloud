//FormAI DATASET v1.0 Category: Pattern printing ; Style: recursive
#include <stdio.h>

void printPattern(int n) {
  if (n < 1) {
    return;
  }
  
  for (int i = 0; i < n; i++) {
    printf("* ");
  }
  printf("\n");

  for (int i = 0; i < n-2; i++) {
    printf("* ");

    for (int j = 0; j < n - 2; j++) {
      printf("  ");
    }

    printf("* \n");
  }

  for (int i = 0; i < n; i++) {
    printf("* ");
  }
  printf("\n");

  printPattern(n-2);
}

int main() {
  int rows;
  printf("Enter the number of rows: ");
  scanf("%d", &rows);

  printPattern(rows);

  return 0;
}