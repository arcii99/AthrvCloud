//FormAI DATASET v1.0 Category: Pattern printing ; Style: bold
#include <stdio.h>

int main() {
  int rows = 10;

  for(int i = 1; i <= rows; i++) {

    // Print the left side of the pattern
    for(int j = 1; j <= i; j++) {
      printf("* ");
    }

    // Print the spaces between the left and right sides
    for(int k = 1; k <= (rows - i) * 2; k++) {
      printf("  ");
    }

    // Print the right side of the pattern
    for(int j = 1; j <= i; j++) {
      printf("* ");
    }

    // Move to the next line
    printf("\n");
  }

  for(int i = rows - 1; i > 0; i--) {

    // Print the left side of the pattern
    for(int j = 1; j <= i; j++) {
      printf("* ");
    }

    // Print the spaces between the left and right sides
    for(int k = 1; k <= (rows - i) * 2; k++) {
      printf("  ");
    }

    // Print the right side of the pattern
    for(int j = 1; j <= i; j++) {
      printf("* ");
    }

    // Move to the next line
    printf("\n");
  }

  return 0;
}