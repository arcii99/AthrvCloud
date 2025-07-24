//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *printHello(void *threadId) {
   printf("Thread ID %d: Hello, World!\n", threadId);
   pthread_exit(NULL);
}

int main () {
   pthread_t threads[NUM_THREADS];
   int rc, i;
   
   // Create threads
   for(i=0; i<NUM_THREADS; i++) {
      rc = pthread_create(&threads[i], NULL, printHello, (void *)i);
      if (rc) {
         printf("Error: return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
   }
   
   // Wait for threads to complete
   for(i=0; i<NUM_THREADS; i++) {
      rc = pthread_join(threads[i], NULL);
      if (rc) {
         printf("Error: return code from pthread_join() is %d\n", rc);
         exit(-1);
      }
   }
   
   printf("Main: All threads completed!\n");

   pthread_exit(NULL);
}