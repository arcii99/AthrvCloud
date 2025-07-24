//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: asynchronous
#include <stdio.h>
#include <pthread.h>

// Function to execute in the threads
void *threadFunc(void *threadID) {
  int id = *(int*)threadID; // Retrieve thread ID
  printf("Thread %d executing...\n", id);
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[5]; // Array to hold 5 threads
  int i, rc;
  
  for (i = 0; i < 5; i++) {
    int *threadID = malloc(sizeof(*threadID)); // Dynamically allocate memory for thread ID
    *threadID = i;
    rc = pthread_create(&threads[i], NULL, threadFunc, threadID); // Create thread
    if (rc) { // Check for errors in thread creation
      printf("Error: Could not create thread %d\n", i);
      pthread_exit(NULL);
    }
  }
  
  // Join all threads to wait for their completion
  for (i = 0; i < 5; i++) {
    rc = pthread_join(threads[i], NULL);
    if (rc) { // Check for errors in thread joining
      printf("Error: Could not join thread %d\n", i);
      pthread_exit(NULL);
    }
  }
  
  printf("All threads have completed execution.\n");

  return 0;
}