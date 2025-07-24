//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

void *thread_function(void *arg) {
   int *thread_num = (int *)arg;
   printf("Thread %d created\n", *thread_num);
   pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
   pthread_t threads[NUM_THREADS];
   int thread_args[NUM_THREADS];
   int rc, i;

   for (i = 0; i < NUM_THREADS; i++) {
       thread_args[i] = i;
       printf("Creating thread %d\n", i);
       rc = pthread_create(&threads[i], NULL, thread_function, &thread_args[i]);
       if (rc) {
          printf("ERROR: return code from pthread_create() is %d\n", rc);
          exit(-1);
       }
   }

   for (i = 0; i < NUM_THREADS; i++) {
       pthread_join(threads[i], NULL);
   }

   printf("All threads have completed successfully\n");
   return 0;
}