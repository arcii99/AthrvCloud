//FormAI DATASET v1.0 Category: Recursive ; Style: innovative
#include <stdio.h>

int recursiveFunction(int n) {
  if (n <= 1) {
    return 1; // base case
  }
  else {
    return n * recursiveFunction(n-1); // recursive call
  }
}

int main() {
  int input;
  printf("Enter a positive integer: ");
  scanf("%d", &input);

  if (input < 0) {
    printf("Error: Please enter a positive integer.\n");
    main(); // restart program if input is negative
  }
  else {
    int result = recursiveFunction(input);
    printf("%d! = %d\n", input, result);
  }

  return 0;
}