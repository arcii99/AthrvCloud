//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *print_thread(void *thread_id) {
  long id = (long) thread_id;
  printf("Thread %ld is running.\n", id);
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[NUM_THREADS];
  int rc;
  long t;

  for (t = 0; t < NUM_THREADS; t++) {
    printf("Creating thread %ld.\n", t);
    rc = pthread_create(&threads[t], NULL, print_thread, (void *) t);
    if (rc) {
      printf("Error, return code from pthread_create() is %d.\n", rc);
      exit(-1);
    }
  }

  for (t = 0; t < NUM_THREADS; t++) {
    pthread_join(threads[t], NULL);
  }

  printf("All threads have completed.\n");

  pthread_exit(NULL);
}