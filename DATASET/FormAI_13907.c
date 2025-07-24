//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: rigorous
#include <stdio.h>

// Function to print the Fibonacci sequence up to n terms
void fibonacci(int n) {

  // Initialize the first two numbers of the sequence
  int num1 = 0, num2 = 1;

  // Print the first two numbers of the sequence
  printf("%d %d ", num1, num2);

  // Calculate and print the next numbers of the sequence
  for(int i=2; i<n; i++) {
    int num3 = num1 + num2;
    printf("%d ", num3);

    // Update the values of num1 and num2
    num1 = num2;
    num2 = num3;
  }
}

int main() {
  // Get the number of terms to print from the user
  int num_terms;
  printf("Enter the number of terms to print in the Fibonacci sequence: ");
  scanf("%d", &num_terms);

  // Call the function to print the sequence
  fibonacci(num_terms);

  return 0;
}