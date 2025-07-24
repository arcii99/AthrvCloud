//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: authentic
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#define NUM_THREADS 5

struct thread_data {
   int thread_id;
   int sum;
   char *message;
};

void *PrintHello(void *threadarg) {
   struct thread_data *my_data;
   my_data = (struct thread_data *) threadarg;

   printf("Thread ID: %d, %s\n", my_data->thread_id, my_data->message);
   my_data->sum = my_data->thread_id * 10;

   pthread_exit(NULL);
}

int main () {
   pthread_t threads[NUM_THREADS];
   struct thread_data td[NUM_THREADS];
   int rc;
   int i;

   for(i=0;i<NUM_THREADS;i++) {
      printf("Creating thread %d\n", i);
      td[i].thread_id = i;
      td[i].sum = 0;
      td[i].message = "Hello World!";
      rc = pthread_create(&threads[i], NULL, PrintHello, (void *)&td[i]);

      if (rc){
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
   }

   for(i=0;i<NUM_THREADS;i++) {
      pthread_join(threads[i], NULL);
      printf("Thread %d returned with sum = %d\n", i, td[i].sum);
   }

   printf("Main thread exiting.\n");
   pthread_exit(NULL);
}