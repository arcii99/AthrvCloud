//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

// Thread execution starts here
void *myThreadFun(void *vargp) {
   int *myid = (int *)vargp;
   printf("Thread ID: %d\n", *myid);
   return NULL;
}

int main() {
   pthread_t tid[NUM_THREADS];

   for (int i = 0; i < NUM_THREADS; i++) {
      int *threadid = (int *)malloc(sizeof(int));
      *threadid = i;
      printf("Creating thread %d\n", i);
      pthread_create(&tid[i], NULL, myThreadFun, (void *)threadid);
   }

   for (int i = 0; i < NUM_THREADS; i++) {
      pthread_join(tid[i], NULL);
   }

   return 0;
}