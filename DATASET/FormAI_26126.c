//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: imaginative
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 5

void *thread_func(void *thread_id) {
  int tid;
  tid = *(int*)thread_id;
  printf("[Thread %d] Starting...\n", tid);
  sleep(2);
  printf("[Thread %d] Ending...\n", tid);
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[NUM_THREADS];
  int thread_args[NUM_THREADS];
  int i, status;

  for (i=0; i<NUM_THREADS; i++) {
    printf("[Main] Creating thread %d\n", i);
    thread_args[i] = i;

    status = pthread_create(&threads[i], NULL, thread_func, &thread_args[i]);

    if (status != 0) {
      printf("[Main] Error creating thread %d. Exiting.\n", i);
      exit(1);
    }
  }

  for (i=0; i<NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
    printf("[Main] Joined with thread %d\n", i);
  }
  
  printf("[Main] All threads joined. Exiting.\n");
  pthread_exit(NULL);
  return 0;
}