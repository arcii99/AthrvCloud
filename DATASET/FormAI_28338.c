//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: lively
#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 
#include <time.h> 

#define NUM_THREADS 3  // Number of threads
#define NUM_LOOPS 5    // Number of times each thread should print

void *thread_func(void *thread_id) {
   int id = *((int *)thread_id);

   for (int i = 0; i < NUM_LOOPS; i++) {
      printf("Thread %d: iteration %d\n", id, i);
      sleep(1); // wait for 1 second
   }

   pthread_exit(NULL);
}

int main() {
   pthread_t threads[NUM_THREADS];
   int ids[NUM_THREADS];

   srand(time(0));  // seed random number generator

   for (int i = 0; i < NUM_THREADS; i++) {
      ids[i] = i;    // create an id for each thread
      int r = rand() % 3; // random sleep time between 0 and 2 seconds
      sleep(r);  // wait for a random time before creating the thread
      int res = pthread_create(&threads[i], NULL, thread_func, &ids[i]);
      if (res) {
         printf("Error creating thread %d\n", i);
         exit(-1);
      }
   }

   for (int i = 0; i < NUM_THREADS; i++) {
      int res = pthread_join(threads[i], NULL);
      if (res) {
         printf("Error joining thread %d\n", i);
         exit(-1);
      }
      printf("Thread %d completed\n", i);
   }

   pthread_exit(NULL);
}