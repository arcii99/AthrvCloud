//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

// Function to be executed by each thread
void *print_hello(void *thread_id) {
  long id = (long) thread_id; // Cast thread_id back to long for safety
  printf("Hello from thread #%ld!\n", id);
  pthread_exit(NULL); // Exit thread
}

int main() {
  pthread_t threads[NUM_THREADS];
  int rc;
  long t;
  
  // Create multiple threads
  for (t = 0; t < NUM_THREADS; t++) {
    printf("Creating thread #%ld...\n", t);
    rc = pthread_create(&threads[t], NULL, print_hello, (void *)t);
    if (rc) {
      printf("ERROR: Could not create thread #%ld. Exit.\n", t);
      exit(-1);
    }
  }
  
  // Wait until all threads have finished
  for (t = 0; t < NUM_THREADS; t++) {
    rc = pthread_join(threads[t], NULL);
    if (rc) {
      printf("ERROR: Could not join thread #%ld. Exit.\n", t);
      exit(-1);
    }
  }

  printf("All threads have finished execution. Bye!\n");

  return 0;
}