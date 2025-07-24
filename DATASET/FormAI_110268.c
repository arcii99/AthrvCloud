//FormAI DATASET v1.0 Category: Pattern printing ; Style: Alan Touring
// Alan Turing Style C Pattern Printing Program
#include <stdio.h>

int main() {
  int i, j, n, k;
 
  printf("Please enter a number between 2 and 12: ");
  scanf("%d", &n);

  // Check if the user entered a number between 2 and 12
  if (n < 2 || n > 12) {
    printf("You entered an invalid number! Please enter a number between 2 and 12.");
    return 0;
  }

  printf("Printing Pattern:\n\n");

  // Printing Pattern
  for (i = 0; i < n; i++) {
    for (j = 0; j < n - i; j++) {
      printf("* ");
    }
    for (k = 0; k < 2 * i; k++) {
      printf(" ");
    }
    for (j = 0; j < n - i; j++) {
      printf("* ");
    }
    printf("\n");
  }
 
  for (i = n - 2; i >= 0; i--) {
    for (j = 0; j < n - i; j++) {
      printf("* ");
    }
    for (k = 0; k < 2 * i; k++) {
      printf(" ");
    }
    for (j = 0; j < n - i; j++) {
      printf("* ");
    }
    printf("\n");
  }

  return 0;
}