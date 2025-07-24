//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: cheerful
#include<stdio.h>

// Our amazing cheerful geometric algorithm that will make you smile 
int main() {
  int n, i, j;
  printf("Let's draw a smiley face with geometric shapes! \n");

  // Draw the head using a circle
  printf("  ________  \n");
  printf(" /        \\  \n");
  printf("|          |\n");
  printf("|          |\n");
  printf("|          |\n");
  printf("|          |\n");
  printf("|          |\n");
  printf("|           |\n");
  printf("|   ____   |\n");
  printf("|  /    \\  |\n");
  printf("| | @  @ | |\n");
  printf("|  \\____/  |\n");
  printf("\\_________/ \n");

  // Draw the eyes using triangles
  for (i = 1; i <= 8; i++) {
    for (j = 1; j <= i; j++) {
      printf("* ");
    }
    printf("\n");
  }

  printf("\n");

  for (i = 8; i >= 1; i--) {
    for (j = 1; j <= i; j++) {
      printf("* ");
    }
    printf("\n");
  }

  // Draw the mouth using a diamond shape
  printf("\n     *     \n");
  printf("   *   *   \n");
  printf(" *       * \n");
  printf("   *   *   \n");
  printf("     *     \n");

  printf("\n Our smiley face is complete! \n");
  return 0;
}