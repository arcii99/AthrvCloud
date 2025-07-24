//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: sophisticated
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 5

struct thread_data {
   int  thread_id;
   int  sleep_time;
   char *message;
};

void *PrintHello(void *threadarg) {
   struct thread_data *my_data;
   my_data = (struct thread_data *) threadarg;

   printf("Thread %d: %s\n", my_data->thread_id, my_data->message);
   sleep(my_data->sleep_time);
   printf("Thread %d: Done!\n", my_data->thread_id);
   pthread_exit(NULL);
}

int main () {
   pthread_t threads[NUM_THREADS];
   struct thread_data thread_data_array[NUM_THREADS];
   int rc, t;

   for(t=0; t<NUM_THREADS; t++) {
      printf("Creating thread %d\n", t);
      thread_data_array[t].thread_id = t;
      thread_data_array[t].sleep_time = rand() % 5;
      thread_data_array[t].message = "Hello World!";
      rc = pthread_create(&threads[t], NULL, PrintHello, (void *)&thread_data_array[t]);
      
      if (rc) {
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
   }

   // Wait for all threads to complete
   for(t=0;t<NUM_THREADS;t++) {
      pthread_join(threads[t], NULL);
   }

   printf("Main thread exiting.\n");
   pthread_exit(NULL);
}