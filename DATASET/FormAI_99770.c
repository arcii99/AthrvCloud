//FormAI DATASET v1.0 Category: Syntax parsing ; Style: curious
#include <stdio.h>

int main() {
  int x = 5;
  int y = 3;

  // Check if x is greater than y
  if (x > y) {
    printf("x is greater than y!\n");
  }
  else {
    printf("x is not greater than y!\n");
  }

  // Loop through the values of x from 0 to 4
  for (int i = 0; i < x; i++) {
    printf("%d ", i);
  }
  printf("\n");

  // Call myFunc with x and y as arguments
  int result = myFunc(x, y);
  printf("The result is: %d\n", result);

  return 0;
}

// Define myFunc as a function that adds two numbers
int myFunc(int a, int b) {
  return a + b;
}