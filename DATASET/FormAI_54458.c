//FormAI DATASET v1.0 Category: Arithmetic ; Style: thoughtful
#include <stdio.h>

// Function to calculate the sum of first n numbers
int sum(int n) {
  int s = 0;
  for (int i = 1; i <= n; ++i) {
    s += i;
  }
  return s;
}

int main() {
  int n;
  printf("Enter n: ");
  scanf("%d", &n);

  // Error handling: the value of n must be at least 1
  if (n < 1) {
    printf("Invalid input. The value of n must be at least 1.\n");
    return -1; // Exit error
  }

  // Calculate the sum of first n numbers
  int s = sum(n);

  // Display the result
  printf("The sum of first %d numbers is: %d\n", n, s);

  // If the value of n is even, calculate the product of first n/2 even numbers
  if (n % 2 == 0) {
    int p = 1;
    for (int i = 2; i <= n; i += 2) {
      p *= i;
    }
    printf("The product of first %d/2 even numbers is: %d\n", n, p);
  }

  return 0; // Exit success
}