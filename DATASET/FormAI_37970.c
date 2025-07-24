//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* This is a simple program that demonstrates how to use 
   my awesome C threading library implementation! */

/* Here's a function that our threads will run */
void* thread_function(void* arg) {
  int thread_id = *(int*)arg;
  printf("Thread %d is running!\n", thread_id);
  pthread_exit(NULL);
}

int main() {
  int i;
  int num_threads = 5;
  pthread_t threads[num_threads];
  int ids[num_threads];

  /* Let's create some threads! */
  printf("Creating %d threads\n", num_threads);
  for (i = 0; i < num_threads; i++) {
    ids[i] = i;
    if (pthread_create(&threads[i], NULL, thread_function, &ids[i])) {
      printf("Error creating thread %d\n", i);
      return 1;
    }
  }

  /* Wait for threads to finish */
  for (i = 0; i < num_threads; i++) {
    if (pthread_join(threads[i], NULL)) {
      printf("Error joining thread %d\n", i);
      return 1;
    }
    printf("Thread %d has finished!\n", i);
  }

  printf("All threads have finished!\n");
  return 0;
}