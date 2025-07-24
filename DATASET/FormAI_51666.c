//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *print_hello(void *thread_id) {
  long tid;
  tid = (long)thread_id;
  printf("Hello from thread %ld\n", tid);
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[NUM_THREADS];
  int i;
  for (i = 0; i < NUM_THREADS; i++) {
    printf("Creating thread %d\n", i);
    int rc = pthread_create(&threads[i], NULL, print_hello, (void *)i);
    if (rc) {
      printf("ERROR: return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
  }
  pthread_exit(NULL);
}