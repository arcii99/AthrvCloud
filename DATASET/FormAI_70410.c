//FormAI DATASET v1.0 Category: Fractal Generation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int i, j, n, x, y, z;
  printf("Welcome to the Fractal Generation App!\n\n");
  printf("Enter the number of fractals you want to generate: ");
  scanf("%d", &n);

  for (i = 1; i <= n; i++) {
    printf("\nGenerating Fractal #%d...\n", i);

    x = i * 2; // Randomizing variables

    y = x + i;

    z = y * 3;

    for (j = 1; j <= x; j++) { // Creating first level of fractal
      printf("*");
    }
    printf("\n");

    for (j = 1; j <= y; j++) { // Creating second level of fractal
      printf("%c", j % 2 == 0 ? '*' : '-');
    }

    printf("\n");

    for (j = 1; j <= z; j++) { // Creating third level of fractal
      printf("%c", j % 3 == 0 ? '*' : '#');
    }

    printf("\n");

    system("pause"); // Pausing for dramatic effect
  }

  printf("\nFractal generation complete. Have a nice day!\n");

  return 0;
}