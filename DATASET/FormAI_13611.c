//FormAI DATASET v1.0 Category: Funny ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *printHello(void *threadid) {
  long tid;
  tid = (long)threadid;
  printf("Thread %ld says hello!\n", tid);
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[5];
  int rc;
  long t;
  
  for(t=0; t<5; t++){
    printf("Creating thread %ld\n", t);
    rc = pthread_create(&threads[t], NULL, printHello, (void *)t);
    if (rc) {
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
  }
  pthread_exit(NULL);
  return 0;
}