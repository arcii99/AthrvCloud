//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// This is just a simple program to showcase a unique implementation of the C Threading Library

#define NUM_THREADS 5

void* thread_function(void* thread_id) {
  int id = *((int*) thread_id);
  printf("Thread %d is executing\n", id);
  pthread_exit(NULL);
}

int main(void) {
  pthread_t threads[NUM_THREADS];
  int thread_ids[NUM_THREADS];
  int i, rc;

  printf("Creating %d threads\n", NUM_THREADS);

  for (i = 0; i < NUM_THREADS; i++) {
    thread_ids[i] = i;
    rc = pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);

    if (rc) {
      printf("ERROR: Return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
  }

  printf("All threads created successfully!\n");

  for (i = 0; i < NUM_THREADS; i++) {
    rc = pthread_join(threads[i], NULL);
    if (rc) {
      printf("ERROR: Return code from pthread_join() is %d\n", rc);
      exit(-1);
    }
  }

  printf("All threads joined successfully!\n");

  pthread_exit(NULL);

}