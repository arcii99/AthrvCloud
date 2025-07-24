//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS 5

// Define the structure for the thread
typedef struct {
   int thread_id;
   int cpu_utilization;
   int memory_allocation;
} thread_data;

// Define the function that the thread will execute
void *thread_function(void *arg) {
   thread_data *data = (thread_data *) arg;
   printf("Thread %d: CPU utilization is %d%% and memory allocation is %dMB\n", data->thread_id, data->cpu_utilization, data->memory_allocation);
   pthread_exit(NULL);
}

int main() {
   // Initialize the threads
   pthread_t threads[NUM_THREADS];
   int i, status;

   // Create the data structures for the threads
   thread_data thread_data_array[NUM_THREADS];
   for (i = 0; i < NUM_THREADS; i++) {
      thread_data_array[i].thread_id = i;
      thread_data_array[i].cpu_utilization = rand() % 101;
      thread_data_array[i].memory_allocation = rand() % 501;
   }

   // Create the threads
   for (i = 0; i < NUM_THREADS; i++) {
      status = pthread_create(&threads[i], NULL, thread_function, (void *) &(thread_data_array[i]));
      if (status != 0) {
         printf("Error creating thread %d\n", i);
         exit(1);
      }
   }

   // Join the threads
   for (i = 0; i < NUM_THREADS; i++) {
      status = pthread_join(threads[i], NULL);
      if (status != 0) {
         printf("Error joining thread %d\n", i);
         exit(1);
      }
   }

   return 0;
}