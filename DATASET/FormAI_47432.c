//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *thread_func(void *threadid) {
   long tid;
   tid = (long)threadid;
   printf("Thread %ld is running\n", tid);
   pthread_exit(NULL);
}
 
int main () {
   pthread_t threads[NUM_THREADS];
   int rc;
   long t;

   for(t=0; t<NUM_THREADS; t++) {
      printf("Creating thread %ld\n", t);
      rc = pthread_create(&threads[t], NULL, thread_func, (void *)t);
      if (rc) {
         printf("ERROR: return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
   }
   
   for(t=0; t<NUM_THREADS; t++) {
      pthread_join(threads[t], NULL);
   }

   printf("All threads completed\n");
   pthread_exit(NULL);
}