//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *thread_function(void *arg) {
   int thread_id = *(int *)arg;
   printf("Thread %d is starting\n", thread_id);
   sleep(3);
   printf("Thread %d is ending\n", thread_id);
   pthread_exit(NULL);
}

int main() {
   pthread_t thread[NUM_THREADS];
   int thread_args[NUM_THREADS];
   int i;

   for (i = 0; i < NUM_THREADS; i++) {
      thread_args[i] = i;
      printf("Creating thread %d\n", i);
      pthread_create(&thread[i], NULL, thread_function, (void *)&thread_args[i]);
   }

   for (i = 0; i < NUM_THREADS; i++) {
      pthread_join(thread[i], NULL);
   }

   printf("All threads have finished\n");
   return 0;
}