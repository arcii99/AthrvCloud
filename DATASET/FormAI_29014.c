//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg) {
   int thread_arg;
   thread_arg = *(int *) arg;
   printf("Hello from thread %d\n", thread_arg);
   return NULL;
}

int main() {
   int i;
   pthread_t mythread[3];

   for (i = 0; i < 3; i++) {
      pthread_create(&mythread[i], NULL, thread_function, (void *) &i);
      printf("Thread %d created!\n", i);
   }

   for (i = 0; i < 3; i++) {
      pthread_join(mythread[i], NULL);
      printf("Thread %d joined!\n", i);
   }

   return 0;
}