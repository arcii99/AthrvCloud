//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *thread_func(void *t_id) {
   int thread_id = *((int *)t_id);
   printf("Thread #%d is running\n", thread_id);
   pthread_exit(NULL);
}

int main() {
   pthread_t threads[NUM_THREADS];
   int thread_ids[NUM_THREADS];
   int i, rc;

   for(i=0; i < NUM_THREADS; i++) {
      printf("Creating thread #%d\n", i);
      thread_ids[i] = i;

      rc = pthread_create(&threads[i], NULL, thread_func, (void *)&thread_ids[i]);
      if(rc) {
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
   }

   for(i=0; i < NUM_THREADS; i++) {
      pthread_join(threads[i], NULL);
      printf("Thread #%d has completed\n", i);
   }

   pthread_exit(NULL);
   return 0;
}