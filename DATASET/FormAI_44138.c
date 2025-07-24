//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_func(void *arg) {
   int thread_num = *((int *) arg);
   printf("Thread %d is running!\n", thread_num);
   pthread_exit(NULL);
}

int main() {
   int num_threads;
   printf("Enter the number of threads: ");
   scanf("%d", &num_threads);
   
   pthread_t threads[num_threads];
   int thread_args[num_threads];

   for (int i = 0; i < num_threads; i++) {
      thread_args[i] = i;
      if (pthread_create(&threads[i], NULL, thread_func, &thread_args[i]) != 0) {
         printf("Error: Failed to create thread %d\n", i);
		 exit(EXIT_FAILURE);
	     }
   }

   for (int i = 0; i < num_threads; i++) {
      if (pthread_join(threads[i], NULL) != 0) {
         printf("Error: Failed to join thread %d\n", i);
		 exit(EXIT_FAILURE);
	    }
   }

   printf("All threads have completed!\n");
   return 0;
}