//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3

struct thread_data {
   int  thread_id;
   char *message;
};

void *PrintHello(void *threadarg) {
   struct thread_data *my_data;
   my_data = (struct thread_data *) threadarg;
   printf("Thread ID : %d, Message : %s\n", my_data->thread_id, my_data->message);
   pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
   pthread_t threads[NUM_THREADS];
   struct thread_data td[NUM_THREADS];
   int rc;
   int i;

   for(i=0; i<NUM_THREADS; i++) {
      printf("Creating thread %d\n", i);
      td[i].thread_id = i;
      td[i].message = "Hello Thread!";
      rc = pthread_create(&threads[i], NULL, PrintHello, (void *)&td[i] );
   
      if (rc) {
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
   }

   pthread_exit(NULL);
}