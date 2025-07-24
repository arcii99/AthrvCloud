//FormAI DATASET v1.0 Category: Recursive ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

// Recursive Factorial Function
int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n-1);
  }
}

// Thread Function
void* print_factorial(void* arg) {
  int n = *((int*) arg);
  int result = factorial(n);
  printf("%d! = %d\n", n, result);
  pthread_exit(0);
}

int main() {
  pthread_t threads[5];

  // Create and Run Threads
  for (int i=0; i<5; i++) {
    int* n = (int*) malloc(sizeof(int));
    *n = i+1;
    pthread_create(&threads[i], NULL, print_factorial, n);
  }

  // Join Threads
  for (int i=0; i<5; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}