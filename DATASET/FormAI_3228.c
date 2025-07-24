//FormAI DATASET v1.0 Category: Scientific ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREADS 4

//global variables to be shared across threads
int count = 0;
int sum = 0;
int average = 0;

void *countFunction(void *threadID) {
  count++;
  pthread_exit(NULL);
}

void *sumFunction(void *threadID) {
  int *numbers = (int *) threadID;
  sum += *numbers;
  pthread_exit(NULL);
}

void *averageFunction(void *threadID) {
  average = sum / NUM_THREADS;
  pthread_exit(NULL);
}

void *printFunction(void *threadID) {
  printf("Total count: %d\n", count);
  printf("Total sum: %d\n", sum);
  printf("Average: %d\n", average);
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[NUM_THREADS];
  int numbers[NUM_THREADS];
  
  //initialize numbers array with 1 to NUM_THREADS
  for (int i = 0; i < NUM_THREADS; i++) {
    numbers[i] = i + 1;
  }

  //create and join count threads
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_create(&threads[i], NULL, countFunction, NULL);
  }
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  //create and join sum threads
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_create(&threads[i], NULL, sumFunction, (void *)&numbers[i]);
  }
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  //create and join average thread
  pthread_create(&threads[0], NULL, averageFunction, NULL);
  pthread_join(threads[0], NULL);

  //create and join print thread
  pthread_create(&threads[0], NULL, printFunction, NULL);
  pthread_join(threads[0], NULL);

  return 0;
}