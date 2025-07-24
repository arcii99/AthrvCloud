//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: expert-level
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5

void *thread_func(void *thread_id) {
  int tid = (int)thread_id;
  printf("Thread %d is now running.\n", tid);
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[NUM_THREADS];
  int rc, t;

  for(t = 0; t < NUM_THREADS; t++) {
    printf("Creating thread %d.\n", t);
    rc = pthread_create(&threads[t], NULL, thread_func, (void *)t);
    if (rc) {
      printf("Error: return code from pthread_create() is %d.\n", rc);
      exit(-1);
    }
  }

  for(t = 0; t < NUM_THREADS; t++) {
    pthread_join(threads[t], NULL);
    printf("Thread %d has completed.\n", t);
  }

  pthread_exit(NULL);
  return 0;
}