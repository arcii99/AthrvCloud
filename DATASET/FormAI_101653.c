//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: safe
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

typedef struct {
   int thread_id;
   char *message;
} thread_info;

void *PrintHello(void *threadarg) {
   thread_info *info;
   info = (thread_info *) threadarg;
   printf("Thread ID: %d\n", info->thread_id);
   printf("Message: %s\n", info->message);
   pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
   pthread_t threads[NUM_THREADS];
   int rc;
   long t;
   thread_info thread_data[NUM_THREADS];

   for (t = 0; t < NUM_THREADS; t++) {
      printf("In main: creating thread %ld\n", t);
      thread_data[t].thread_id = t;
      thread_data[t].message = "Hello there!";
      rc = pthread_create(&threads[t], NULL, PrintHello, (void *) &thread_data[t]);
      if (rc) {
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         return -1;
      }
   }

   pthread_exit(NULL);
}