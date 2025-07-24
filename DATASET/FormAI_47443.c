//FormAI DATASET v1.0 Category: Recursive ; Style: complete
#include <stdio.h>

// Function to calculate factorial recursively
int fact(int n) {
  if (n == 0) {
    return 1;
  }
  return n * fact(n - 1);
}

// Function to print the pascal triangle which uses the fact function
void pascal_triangle(int rows) {
  int i, j, k;

  for (i = 0; i < rows; i++) {
    // Print spaces on the left
    for (j = 0; j < rows - i - 1; j++) {
      printf(" ");
    }

    // Print numbers
    for (k = 0; k <= i; k++) {
      int num = fact(i) / (fact(k) * fact(i - k));
      printf("%d ", num);
    }

    // Move to next line
    printf("\n");
  }
}

// Main function to test the pascal_triangle function
int main() {
  int rows;

  printf("Enter the number of rows you want to generate in Pascal's triangle: ");
  scanf("%d", &rows);

  printf("\n");

  pascal_triangle(rows);

  return 0;
}