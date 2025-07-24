//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Linus Torvalds
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5

void *thread_output(void *thread_id) {
  long tid;
  tid = (long)thread_id;
  printf("Hello World! This is thread %ld\n", tid);
  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  pthread_t threads[NUM_THREADS];
  int rc;
  long t;
  for(t=0; t<NUM_THREADS; t++) {
    printf("Creating thread %ld\n", t);
    rc = pthread_create(&threads[t], NULL, thread_output, (void *)t);
    if (rc) {
      printf("Error creating thread %ld\n", t);
      exit(-1);
    }
  }
  pthread_exit(NULL);
}