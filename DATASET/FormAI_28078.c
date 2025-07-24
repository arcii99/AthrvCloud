//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *print_message(void *thread_id) {
  long tid;
  tid = (long) thread_id;
  printf("Thread ID %ld is working\n", tid);
  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  pthread_t threads[NUM_THREADS];
  int rc;
  long t;
  for(t=0;t<NUM_THREADS;t++) {
    printf("Creating thread %ld\n", t);
    rc = pthread_create(&threads[t], NULL, print_message, (void *) t);
    if (rc) {
      printf("ERROR: return code from pthread_create() is %d\n", rc);
      exit(EXIT_FAILURE);
    }
  }
  pthread_exit(NULL);
  return 0;
}