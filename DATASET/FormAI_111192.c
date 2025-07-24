//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: complex
#include <pthread.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

#define NUM_THREADS 10

struct thread_data {
   int thread_id;
   char message[100];
};

void *PrintThreadHello(void *threadarg) {
   struct thread_data *my_data;
   my_data = (struct thread_data *) threadarg;
   
   int task_id;
   double result = 0.0;
   printf("Thread ID: %d Message : %s\n", my_data->thread_id, my_data->message);

   for (task_id = 0; task_id < 10; task_id++) {
      result = result + sin(task_id);
      printf("Thread ID: %d completed task %d\n", my_data->thread_id, task_id);
   }
   printf("Thread ID: %d Result : %e\n", my_data->thread_id, result);

   pthread_exit(NULL);
}

int main (int argc, char *argv[]) {
   pthread_t threads[NUM_THREADS];
   struct thread_data td[NUM_THREADS];
   int rc, i;

   for(i=0; i < NUM_THREADS; i++) {
      td[i].thread_id = i;
      sprintf(td[i].message, "Hello from thread %d", i);
      rc = pthread_create(&threads[i], NULL, PrintThreadHello, (void *)&td[i]);
      
      if (rc) {
         printf("ERROR: return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
   }

   pthread_exit(NULL);
}