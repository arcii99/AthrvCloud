//FormAI DATASET v1.0 Category: Scientific ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *print_hello(void *thread_id) {
  long tid = (long)thread_id;
  printf("Hello from thread %ld!\n", tid);
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[NUM_THREADS];
  int rc;
  long t;

  for(t = 0; t < NUM_THREADS; t++) {
    printf("Creating thread %ld\n", t);
    rc = pthread_create(&threads[t], NULL, print_hello, (void *)t);
    if (rc) {
      printf("ERROR: Return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
  }

  for(t = 0; t < NUM_THREADS; t++) {
    rc = pthread_join(threads[t], NULL);
    if (rc) {
      printf("ERROR: Return code from pthread_join() is %d\n", rc);
      exit(-1);
    }
    printf("Thread %ld has completed!\n", t);
  }

  pthread_exit(NULL);
}