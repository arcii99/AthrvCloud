//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function for the thread to execute
void *print_hello(void *thread_id) {
  int id = *(int*)thread_id;
  printf("Hello from thread %d!\n", id);
  pthread_exit(NULL);
}

int main() {
  // Create an array of threads
  pthread_t threads[5];
  
  // Create an array of thread ids for passing to each thread
  int thread_ids[5];
  
  int i;
  
  // Loop through the threads
  for (i = 0; i < 5; i++) {
    // Set the thread id for this thread
    thread_ids[i] = i;
    
    // Create the thread and pass in the thread id
    pthread_create(&threads[i], NULL, print_hello, (void *)&thread_ids[i]);
  }
  
  // Wait for all threads to finish
  for (i = 0; i < 5; i++) {
    pthread_join(threads[i], NULL);
  }
  
  printf("All threads have finished!\n");
  
  return 0;
}