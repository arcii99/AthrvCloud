//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: relaxed
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 3  // Define the number of threads to be created

void *PrintHello(void *threadID) {
  int tid = *((int*)threadID);  // Cast the threadID to an integer pointer and dereference it to get the thread's ID
  printf("Thread %d: Hello, World!\n", tid);
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[NUM_THREADS];  // Define an array to store the thread objects
  int threadIDs[NUM_THREADS];  // Define an array to store the thread IDs
  
  int rc;
  for (int t = 0; t < NUM_THREADS; t++) {
    printf("Creating thread %d\n", t);
    threadIDs[t] = t;  // Store the thread's ID in the array
    rc = pthread_create(&threads[t], NULL, PrintHello, (void*)&threadIDs[t]);  // Create the thread
    if (rc) {
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      return -1;
    }
  }
  
  pthread_exit(NULL);
}