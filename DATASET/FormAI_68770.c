//FormAI DATASET v1.0 Category: Temperature monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 2

int temp = 0;

// Function to read temperature
void *readTemp(void *threadid) {
   long tid;
   tid = (long)threadid;
   
   while(1) {
        temp = 20 + (rand() % 15); // Randomly generate temperature between 20 and 35
        printf("Temperature is %d C\n", temp);
        sleep(2); // Wait 2 seconds before reading again
   }
   pthread_exit(NULL);
}

// Function to monitor temperature
void *checkTemp(void *threadid) {
   long tid;
   tid = (long)threadid;
   
   while(1) {
        if(temp > 30) {
            printf("WARNING: Temperature is %d C\n", temp);
        }
        else {
            printf("Temperature is %d C\n", temp);
        }
        sleep(1); // Check temperature every 1 second
   }
   
   pthread_exit(NULL);
}

int main (int argc, char *argv[]) {
   pthread_t threads[NUM_THREADS];
   int rc;
   long t;
   
   // Create readTemp thread
   rc = pthread_create(&threads[0], NULL, readTemp, (void *)t);
   if (rc) {
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(-1);
   }
   
   // Create checkTemp thread
   rc = pthread_create(&threads[1], NULL, checkTemp, (void *)t);
   if (rc) {
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(-1);
   }
   
   // Wait for threads to finish
   for(t=0; t<NUM_THREADS; t++) {
      pthread_join(threads[t], NULL);
   }
   
   pthread_exit(NULL);
}