//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *printHello(void *threadId) {
  long id = *(long*)threadId;
  printf("Hello from thread %ld!\n", id);
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[NUM_THREADS];
  int rc;
  long t;

  for (t = 0; t < NUM_THREADS; t++) {
    printf("Creating thread %ld...\n", t);

    // create thread
    rc = pthread_create(&threads[t], NULL, printHello, (void *)&t);

    if (rc) {
      printf("ERROR: Unable to create thread %ld %d\n", t, rc);
      exit(-1);
    }
  }

  // wait for all threads to finish
  for (t = 0; t < NUM_THREADS; t++) {
    rc = pthread_join(threads[t], NULL);

    if (rc) {
      printf("ERROR: Unable to join thread %ld %d\n", t, rc);
      exit(-1);
    }

    printf("Thread %ld has finished.\n", t);
  }

  printf("All threads completed successfully!\n");

  pthread_exit(NULL);
  return 0;
}