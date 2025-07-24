//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: peaceful
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 

#define NUM_THREADS 10 

void *thread_function(void *arg) { 
  printf("Thread function is running. Argument: %d\n", *(int *) arg); 
  sleep(1); 
  printf("Thread %d finished.\n", *(int *) arg); 
  return NULL; 
} 

int main() { 
  pthread_t threads[NUM_THREADS]; 
  int thread_args[NUM_THREADS]; 
  int i, rc; 

  // Creating threads 
  for(i=0; i < NUM_THREADS; i++) {
    printf("Creating thread %d.\n", i); 
    thread_args[i] = i; 
    rc = pthread_create(&threads[i], NULL, thread_function, (void *) &thread_args[i]); 
    if (rc) {
      printf("Error: return code from pthread_create is %d\n", rc); 
      return EXIT_FAILURE; 
    } 
  } 

  // Waiting for threads to finish 
  for(i=0; i < NUM_THREADS; i++) {
    rc = pthread_join(threads[i], NULL); 
    if (rc) {
      printf("Error: return code from pthread_join is %d\n", rc); 
      return EXIT_FAILURE; 
    } 
    printf("Thread %d joined.\n", i); 
  }

  printf("All threads finished.\n"); 
  return EXIT_SUCCESS; 
}