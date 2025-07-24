//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS     5

void *PrintHello(void *threadid)
{
   long tid;
   tid = (long)threadid;
   sleep(1);
   printf("Hello World! It's me, thread #%ld!\n", tid);
   pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
   pthread_t threads[NUM_THREADS];
   int rc;
   long t;
   
   // Initialize the thread attribute
   pthread_attr_t attr;
   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
   
   for(t=0; t<NUM_THREADS; t++){
      printf("Creating thread %ld\n", t);
      rc = pthread_create(&threads[t], &attr, PrintHello, (void *)t);
      if (rc){
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
   }
   
   // Destroy the thread attribute
   pthread_attr_destroy(&attr);
   
   // Join all threads
   for(t=0; t<NUM_THREADS; t++){
      rc = pthread_join(threads[t], NULL);
      if (rc){
         printf("ERROR; return code from pthread_join() is %d\n", rc);
         exit(-1);
      }
   }
   
   printf("All threads have completed execution. Exiting...\n");
   pthread_exit(NULL);
}