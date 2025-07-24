//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *print_message(void *thread_id) {
  long tid;
  tid = (long)thread_id;
  printf("Thread %ld says: Oh my, I'm running now!\n", tid);
  pthread_exit(NULL);
}

int main () {
  pthread_t threads[NUM_THREADS];
  int rc;
  long t;
  
  printf("Main here! Let's create some threads, shall we?\n");
  
  for(t=0; t<NUM_THREADS; t++){
    printf("Creating thread %ld...\n", t);
    rc = pthread_create(&threads[t], NULL, print_message, (void *)t);
    
    if (rc){
      printf("Uh oh, pthread_create returned error code %d\n", rc);
      exit(-1);
    }
  }

  // Wait for the threads to finish before exiting
  for(t=0; t<NUM_THREADS; t++){
    pthread_join(threads[t], NULL);
    printf("Thread %ld has finished!\n", t);
  }

  printf("All threads are done! Goodbye!\n");
  pthread_exit(NULL);
}