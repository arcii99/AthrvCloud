//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: mind-bending
//This is an example program that simulates a baggage handling system at a busy airport.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

#define NUMBER_OF_THREADS 10

void *baggageHandler(void *threadid) {
   long tid;
   tid = (long)threadid;
   printf("Baggage handler seized Bag ID: %ld\n", tid);
   pthread_exit(NULL);
}

int main () {
   pthread_t threads[NUMBER_OF_THREADS];
   int rc;
   long t;
   for(t=0; t<NUMBER_OF_THREADS; t++){
      printf("Creating thread %ld\n", t);
      rc = pthread_create(&threads[t], NULL, baggageHandler, (void *)t);
      if (rc){
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
      usleep(rand()%10000); //delay the creation of a new thread by a random amount of microseconds, this simulates the varying arrival of new luggage
   }
   pthread_exit(NULL);
}