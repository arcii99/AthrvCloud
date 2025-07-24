//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *print_hello(void *thread_id) {
  long tid = (long)thread_id;
  printf("Thread %ld: Hello there!\n", tid);
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[NUM_THREADS];
  int rc;
  long t;

  for (t = 0; t < NUM_THREADS; t++) {
    printf("Creating thread %ld\n", t);
    rc = pthread_create(&threads[t], NULL, print_hello, (void *)t);
    if (rc) {
      printf("Error creating thread! Return code: %d\n", rc);
      exit(-1);
    }
  }

  pthread_exit(NULL);
}