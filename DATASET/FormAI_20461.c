//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: future-proof
#include <stdio.h>

int main() {
  int n, first = 0, second = 1, next, c;
  printf("Enter the limit of the Fibonacci sequence: ");
  scanf("%d", &n);
  printf("\n\nFibonacci sequence:\n");

  for (c = 0; c < n; c++) {
    if (c <= 1)
      next = c;
    else {
      next = first + second;
      first = second;
      second = next;
    }
    printf("%d ", next);
  }

  printf("\n\nVisual representation:\n\n");

  // Visualization code
  int pixels[n][n];
  int x = 0, y = 0; // Starting position
  for (c = 0; c < n; c++) {
    if (c <= 1) {
      pixels[x][y] = 1;
    } else {
      pixels[x][y] = 1;
      next = first + second;
      first = second;
      second = next;
      if (c % 4 == 0) {
        y += next;
      } else if (c % 4 == 1) {
        x += next;
      } else if (c % 4 == 2) {
        y -= next;
      } else if (c % 4 == 3) {
        x -= next;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (pixels[i][j]) {
        printf("* ");
      } else {
        printf(". ");
      }
    }
    printf("\n");
  }

  return 0;
}