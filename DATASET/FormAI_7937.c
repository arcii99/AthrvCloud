//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

#define MAX_THREADS 10

pthread_t threads[MAX_THREADS];
int thread_args[MAX_THREADS];
int thread_results[MAX_THREADS];

void *thread_function(void *arg) {
   int tid = *((int *) arg);
   printf("Thread %d starting\n", tid);

   // Do some work
   sleep(1);

   printf("Thread %d exiting\n", tid);
   thread_results[tid] = 0;
   pthread_exit(&thread_results[tid]);
}

int main() {
   int i, j;

   // Launch threads
   for(i=0; i<MAX_THREADS; i++) {
      thread_args[i] = i;
      if(pthread_create(&threads[i], NULL, thread_function, &thread_args[i])) {
         printf("Error creating thread %d\n", i);
         exit(1);
      }
   }

   // Wait for threads to finish
   for(j=0; j<MAX_THREADS; j++) {
      if(pthread_join(threads[j], (void **) &thread_results[j])) {
         printf("Error joining thread %d\n", j);
         exit(1);
      }
      printf("Thread %d returned %d\n", j, thread_results[j]);
   }

   printf("All threads completed.\n");
   exit(0);
}