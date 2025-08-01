//FormAI DATASET v1.0 Category: Game ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 5

void *printHello(void *threadID) {
  long tid;
  tid = (long)threadID;
  printf("Thread %ld: Hello World!\n", tid);
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[NUM_THREADS];
  int rc;
  long t;
  for(t=0; t<NUM_THREADS; t++){
    printf("Creating thread %ld\n", t);
    rc = pthread_create(&threads[t], NULL, printHello, (void *)t);
    if (rc){
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
  }
  pthread_exit(NULL); 
}