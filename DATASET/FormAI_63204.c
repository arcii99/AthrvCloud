//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_THREADS 10

void *uptime_monitor(void *arg);

int main(int argc, char **argv) {
   pthread_t threads[MAX_THREADS];
   int num_threads;

   // Parse command line argument: number of threads to create
   if (argc < 2) {
       printf("Usage: ./uptime_monitor <num_threads>\n");
       exit(1);
   }
   num_threads = atoi(argv[1]);
   if (num_threads > MAX_THREADS) {
       printf("Maximum number of threads exceeded.\n");
       exit(1);
   }

   // Create threads
   int i;
   for (i=0; i<num_threads; i++) {
       pthread_create(&threads[i], NULL, uptime_monitor, NULL);
   }

   // Wait for threads to finish
   for (i=0; i<num_threads; i++) {
       pthread_join(threads[i], NULL);
   }

   return 0;
}

void *uptime_monitor(void *arg) {
   while (1) {
       system("uptime");
       sleep(10);
   }
   return NULL;
}