//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 4

// This function is executed by each thread
void* thread_func(void* arg) {
  int thread_id = *(int*) arg;
  printf("Thread %d is starting.\n", thread_id);
  sleep(1);  // Sleep for 1 second
  printf("Thread %d is done.\n", thread_id);
  pthread_exit(NULL);  // Exit thread
}

int main() {
  pthread_t threads[NUM_THREADS];
  int thread_ids[NUM_THREADS];

  int i;
  for (i = 0; i < NUM_THREADS; i++) {
    thread_ids[i] = i;
    int rc = pthread_create(&threads[i], NULL, thread_func, &thread_ids[i]);
    if (rc) {
      fprintf(stderr, "Failed to create thread %d. Error code: %d\n", i, rc);
      exit(EXIT_FAILURE);
    }
  }

  printf("Main thread is waiting for all threads to finish.\n");

  for (i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  printf("All threads are done. Exiting...\n");

  pthread_exit(NULL);
  return 0;
}