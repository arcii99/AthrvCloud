//FormAI DATASET v1.0 Category: Funny ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

#define NUM_THREADS 5
#define MAX_MSG_LENGTH 20

struct thread_data {
   int thread_id;
   char message[MAX_MSG_LENGTH];
};

pthread_mutex_t mutex_lock;

void* print_message(void *threadarg) {
   struct thread_data *my_data;
   my_data = (struct thread_data *) threadarg;

   // Generate random sleep time between 0-2 seconds
   int sleep_time = rand() % 3;
   sleep(sleep_time);

   // Print message and thread number
   pthread_mutex_lock(&mutex_lock);
   printf("Thread %d: %s\n", my_data->thread_id, my_data->message);
   pthread_mutex_unlock(&mutex_lock);

   pthread_exit(NULL);
}

int main () {
   pthread_t threads[NUM_THREADS];
   struct thread_data td[NUM_THREADS];
   int rc;

   // Seed random number generator
   srand(time(NULL));

   // Initialize mutex lock
   pthread_mutex_init(&mutex_lock, NULL);

   // Pass message and thread number to each thread
   for (int i = 0; i < NUM_THREADS; i++) {
      td[i].thread_id = i;
      snprintf(td[i].message, MAX_MSG_LENGTH, "Hello from thread %d", i);
      rc = pthread_create(&threads[i], NULL, print_message, (void *)&td[i]);
      if (rc) {
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
   }

   // Wait for all threads to finish
   for (int i = 0; i < NUM_THREADS; i++) {
      pthread_join(threads[i], NULL);
   }

   // Destroy mutex lock
   pthread_mutex_destroy(&mutex_lock);

   // Exit program
   pthread_exit(NULL);
}