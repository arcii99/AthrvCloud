//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

void *threadFunction(void *id) {
   int threadId = *(int*)id;
   printf("Thread %d started\n", threadId);
   printf("Thread %d finished\n", threadId);
   pthread_exit(NULL);
}

int main() {
   pthread_t threads[NUM_THREADS];
   int threadIds[NUM_THREADS];
   int rc, i;

   for(i = 0; i < NUM_THREADS; i++) {
      threadIds[i] = i;
      rc = pthread_create(&threads[i], NULL, threadFunction, &threadIds[i]);
      if (rc) {
         printf("Error creating thread %d\n", i);
         exit(-1);
      }
   }

   for(i = 0; i < NUM_THREADS; i++) {
      pthread_join(threads[i], NULL);
   }

   return 0;
}