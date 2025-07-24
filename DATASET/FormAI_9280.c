//FormAI DATASET v1.0 Category: Educational ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_COUNT 4
#define ARRAY_SIZE 20

int sum = 0;
int numbers[ARRAY_SIZE];

void *compute_sum(void *arg) {
  int start = (int)arg;
  int end = start + (ARRAY_SIZE / THREAD_COUNT);
  int thread_sum = 0;
  for (int i = start; i < end; i++) {
    thread_sum += numbers[i];
  }
  sum += thread_sum;
  return NULL;
}

int main() {
  // Initialize array with random numbers
  for (int i = 0; i < ARRAY_SIZE; i++) {
    numbers[i] = rand() % 10;
  }

  // Print the array
  printf("Numbers: ");
  for (int i = 0; i < ARRAY_SIZE; i++) {
    printf("%d ", numbers[i]);
  }
  printf("\n");

  // Create threads and compute sum
  pthread_t threads[THREAD_COUNT];
  for (int i = 0; i < THREAD_COUNT; i++) {
    pthread_create(&threads[i], NULL, compute_sum, (void*)(i * (ARRAY_SIZE / THREAD_COUNT)));
  }

  // Wait for threads to finish
  for (int i = 0; i < THREAD_COUNT; i++) {
    pthread_join(threads[i], NULL);
  }

  // Print the sum
  printf("Sum: %d\n", sum);

  return 0;
}