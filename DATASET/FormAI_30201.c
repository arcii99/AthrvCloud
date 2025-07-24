//FormAI DATASET v1.0 Category: System administration ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_COUNT 4

void* thread_function(void* arg) {
  int thread_id = *(int*)arg;
  printf("Thread %d is running\n", thread_id);
  return NULL;
}

int main() {
  pthread_t thread_ids[THREAD_COUNT];
  int thread_args[THREAD_COUNT];

  // Create threads
  for(int i = 0; i < THREAD_COUNT; i++) {
    thread_args[i] = i;
    pthread_create(&thread_ids[i], NULL, thread_function, &thread_args[i]);
  }

  // Wait for threads to complete
  for(int i = 0; i < THREAD_COUNT; i++) {
    pthread_join(thread_ids[i], NULL);
  }

  printf("All threads completed\n");
  return 0;
}