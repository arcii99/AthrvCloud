//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: mathematical
// A mathematical-themed C Threading Library implementation

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function to compute the factorial of a given number
int factorial(int n) {
  int result = 1;
  for (int i = 1; i <= n; i++) {
    result *= i;
  }
  return result;
}

// Thread function to compute the sum of factorials of a given range of numbers
void *sum_of_factorials(void *arg) {
  int start = *(int*) arg;
  int end = start + 9; // Compute sum of factorials for the next 10 numbers
  int sum = 0;

  for (int i = start; i <= end; i++) {
    sum += factorial(i);
  }

  return (void *) sum;
}

int main() {
  int result = 0;
  pthread_t threads[10]; // Array of 10 threads to compute sum of factorials

  for (int i = 0; i < 10; i++) {
    int *arg = malloc(sizeof(*arg)); // Allocate memory for the argument to be passed to thread function
    *arg = i * 10; // Compute the starting point for each thread
    pthread_create(&threads[i], NULL, sum_of_factorials, arg);
  }

  for (int i = 0; i < 10; i++) {
    int *thread_result;
    pthread_join(threads[i], (void **) &thread_result); // Join each thread and retrieve its result
    result += *thread_result; // Accumulate the sum of factorials computed by all threads
    free(thread_result); // Free memory allocated for the thread result
  }

  printf("The sum of factorials of the first 100 numbers is %d.\n", result);

  return 0;
}