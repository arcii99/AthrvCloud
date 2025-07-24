//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

int array[1000000]; // an array of size 1 million to store the numbers

// a function to be run by each thread
void *addNumbers(void *threadID) {
   int i;
   long id = (long) threadID;
   int start = id * 250000; // each thread starts at different position of the array
   int end = start + 250000; // each thread handles 250,000 elements of the array
   for (i = start; i < end; i++) {
      array[i] = array[i] + 1; // increment each element of the array by 1
   }
   pthread_exit(NULL);
}

int main() {
   pthread_t threads[NUM_THREADS];
   int rc, i;

   // initialize the array with random numbers between 1 and 100
   for (i = 0; i < 1000000; i++) {
      array[i] = rand() % 100 + 1;
   }

   // create each thread and assign it a unique ID
   for (i = 0; i < NUM_THREADS; i++) {
      rc = pthread_create(&threads[i], NULL, addNumbers, (void *) i);
      if (rc) {
         printf("Error: return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
   }

   // wait for all threads to finish
   for (i = 0; i < NUM_THREADS; i++) {
      pthread_join(threads[i], NULL);
   }

   // print the final result
   int sum = 0;
   for (i = 0; i < 1000000; i++) {
      sum += array[i];
   }
   printf("Sum of all elements in the array is: %d\n", sum);

   pthread_exit(NULL);
}