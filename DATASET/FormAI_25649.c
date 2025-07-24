//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h> 

#define NUM_THREADS 5 

struct thread_data {
  int thread_id;
  char *message;
};

void *PrintHello(void *threadarg) {
  struct thread_data *data;
  data = (struct thread_data *) threadarg;

  printf("Thread ID: %d\n", data->thread_id);
  printf("Message: %s\n", data->message);
  pthread_exit(NULL);
}

int main () {
  pthread_t threads[NUM_THREADS];
  struct thread_data td[NUM_THREADS];
  int rc;
  int i;

  for (i = 0; i < NUM_THREADS; i++) {
    printf("Main: creating thread %d\n", i);
    td[i].thread_id = i;
    td[i].message = "Hello from thread!";
    rc = pthread_create(&threads[i], NULL, PrintHello, (void *)&td[i]);
    if (rc) {
      printf("Error: return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
  }

  pthread_exit(NULL);
}