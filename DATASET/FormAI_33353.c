//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: relaxed
#include <stdio.h>

// Function to calculate and print the Fibonacci sequence up to n terms
void fibonacci(int n) {

  int prev_num = 0;
  int curr_num = 1;
  int next_num;

  printf("Fibonacci sequence up to %d terms: \n", n);
  printf("%d ", prev_num);
  printf("%d ", curr_num);

  // Iterate through the remaining terms to calculate and print the sequence
  for (int i = 2; i < n; i++) {
    next_num = prev_num + curr_num;
    printf("%d ", next_num);
    prev_num = curr_num;
    curr_num = next_num;
  }

  printf("\n");
}

// Function to print the Fibonacci sequence with a visualizer
void fibonacci_visualizer(int n) {

  int prev_num = 0;
  int curr_num = 1;
  int next_num;

  printf("Fibonacci sequence with a visualizer up to %d terms: \n", n);

  // Iterate through the terms to calculate and print the sequence with visualizer
  for (int i = 0; i < n; i++) {
    printf("%d ", curr_num);
    next_num = prev_num + curr_num;
    prev_num = curr_num;
    curr_num = next_num;

    // Print visualizer representing the current Fibonacci number
    printf("|");
    for (int j = 0; j < curr_num; j++) {
      printf("-");
    }
    printf("\n");
  }
}

// Main function
int main() {

  int n = 10;

  // Call the Fibonacci function to print the sequence up to n terms
  fibonacci(n);

  // Call the Fibonacci visualizer function to print the sequence with visualizer up to n terms
  fibonacci_visualizer(n);

  return 0;
}