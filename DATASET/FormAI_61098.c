//FormAI DATASET v1.0 Category: Sorting ; Style: cheerful
#include <stdio.h>

// This program sorts a list of numbers using bubble sort algorithm
// in a cheerful and colorful way!

int main() {
  int numbers[10] = {10, 9, 7, 8, 4, 6, 5, 1, 3, 2};
  int n = 10;

  printf("\033[1;36m");  // Change color to cyan
  printf("Welcome to my cheerful bubble sort program!\n");
  printf("\033[0m");  // Reset color

  printf("\nBefore sorting:\n");

  for (int i = 0; i < n; i++) {
    printf("%d ", numbers[i]);
  }
  printf("\n\n");

  // Bubble sort algorithm
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n-i-1; j++) {
      if (numbers[j] > numbers[j+1]) {
        int temp = numbers[j];
        numbers[j] = numbers[j+1];
        numbers[j+1] = temp;
      }
    }

    // Print the list after each iteration
    printf("\033[1;33m");  // Change color to yellow
    printf("Iteration %d:\n", i+1);
    printf("\033[0m");  // Reset color

    for (int k = 0; k < n; k++) {
      if (k == n-i-1) {
        printf("\033[1;35m");  // Change color to magenta
      }
      printf("%d ", numbers[k]);
      printf("\033[0m");  // Reset color
    }
    printf("\n\n");
  }

  printf("\033[1;32m");  // Change color to green
  printf("After sorting:\n");
  printf("\033[0m");  // Reset color

  for (int i = 0; i < n; i++) {
    printf("%d ", numbers[i]);
  }
  printf("\n");

  printf("\033[1;36m");  // Change color to cyan
  printf("\nThat's it for my cheerful bubble sort program! Have a great day!\n");
  printf("\033[0m");  // Reset color

  return 0;
}