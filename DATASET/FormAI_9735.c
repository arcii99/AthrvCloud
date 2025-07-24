//FormAI DATASET v1.0 Category: Pattern printing ; Style: real-life
#include <stdio.h>

int main() {
  // Introducing the program to the user
  printf("Welcome to C Pattern Printer!\n");

  // Asking the user for the size of the pattern
  int size;
  printf("Please enter the size of the pattern (must be an even number): ");
  scanf("%d", &size);

  // Validating the size input
  if (size % 2 != 0) {
    printf("Sorry, the size must be an even number. ");
    return 1;
  }

  // Printing the pattern
  printf("\nHere is your C pattern:\n");
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (i == 0 || i == size-1 || j == 0) {
        printf("* ");
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }

  // Farewell message
  printf("\nThank you for using C Pattern Printer!\n");

  return 0;
}