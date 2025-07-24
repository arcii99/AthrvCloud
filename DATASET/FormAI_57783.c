//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 2

void *thread_function(void *arg) {
  int *thread_id = (int *)arg;
  printf("Thread %d starting...\n", *thread_id);
  // Simulate some work
  sleep(5);
  printf("Thread %d finished.\n", *thread_id);
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[NUM_THREADS];
  int thread_args[NUM_THREADS];
  int result_code, i;

  // Create threads
  printf("Creating threads...\n");
  for(i=0; i<NUM_THREADS; i++) {
    thread_args[i] = i;
    result_code = pthread_create(&threads[i], NULL, thread_function, &thread_args[i]);
    if (result_code != 0) {
      fprintf(stderr, "Error creating thread %d, return code %d\n", i, result_code);
      exit(EXIT_FAILURE);
    }
  }

  // Wait for threads to finish
  for(i=0; i<NUM_THREADS; i++) {
    result_code = pthread_join(threads[i], NULL);
    printf("Thread %d joined.\n", i);
    if (result_code != 0) {
      fprintf(stderr, "Error joining thread %d, return code %d\n", i, result_code);
      exit(EXIT_FAILURE);
    }
  }

  printf("All threads finished execution.\n");

  return 0;
}