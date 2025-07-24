//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

typedef struct {
   int thread_id;
   char *message;
} thread_data;

void *print_hello(void *threadarg) {
   thread_data *my_data;
   my_data = (thread_data *) threadarg;
   printf("Thread ID: %d\n", my_data->thread_id);
   printf("Message: %s\n", my_data->message);
   pthread_exit(NULL);
}

int main () {
   pthread_t threads[NUM_THREADS];
   thread_data td[NUM_THREADS];
   int rc;
   int i;

   for(i=0; i < NUM_THREADS; i++) {
      printf("Creating thread %d\n", i);
      td[i].thread_id = i;
      td[i].message = "Hello, World!";
      rc = pthread_create(&threads[i], NULL, print_hello, (void *)&td[i]);
      
      if (rc) {
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
   }

   pthread_exit(NULL);
}