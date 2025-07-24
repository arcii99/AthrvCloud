//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *thread_func(void *arg) {
  int thread_id = *(int*) arg;
  printf("Thread %d is running\n", thread_id);
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[NUM_THREADS];
  int thread_args[NUM_THREADS];
  
  int i;
  for (i = 0; i < NUM_THREADS; i++) {
    thread_args[i] = i;
    int rc = pthread_create(&threads[i], NULL, thread_func, &thread_args[i]);
    if (rc) {
      printf("ERROR: return code from pthread_create is %d", rc);
      exit(1);
    }
  }
  
  for (i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }
  
  printf("All threads have completed\n");
  pthread_exit(NULL);
}