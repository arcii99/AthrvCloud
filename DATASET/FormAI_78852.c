//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10

void *thread_function(void *arg);

int main() {
  pthread_t threads[NUM_THREADS];
  int thread_args[NUM_THREADS];
  int i;

  // create threads
  for (i = 0; i < NUM_THREADS; i++) {
    thread_args[i] = i;
    printf("Creating Thread %d\n", i);
    if (pthread_create(&threads[i], NULL, thread_function, &thread_args[i])) {
      fprintf(stderr, "Error creating thread %d.\n", i);
      exit(EXIT_FAILURE);
    }
  }

  // wait for threads to complete
  for (i = 0; i < NUM_THREADS; i++) {
    if (pthread_join(threads[i], NULL)) {
      fprintf(stderr, "Error joining thread %d.\n", i);
      exit(EXIT_FAILURE);
    }
    printf("Thread %d exited.\n", i);
  }

  printf("All threads completed.\n");
  return 0;
}

void *thread_function(void *arg) {
  int thread_arg = *(int *)arg;
  printf("Hello from thread %d.\n", thread_arg);
  pthread_exit(NULL);
}