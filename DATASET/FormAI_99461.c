//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

pthread_mutex_t lock;

void *thread_func(void *id) {
  int thread_id = *(int *)id;
  pthread_mutex_lock(&lock);
  printf("Thread %d has acquired the lock!\n", thread_id); 
  sleep(1);
  printf("Thread %d is releasing the lock!\n", thread_id); 
  pthread_mutex_unlock(&lock);
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[NUM_THREADS];
  int thread_id[NUM_THREADS];
  
  // Initialize mutex lock
  pthread_mutex_init(&lock, NULL);

  // Create threads
  for (int i = 0; i < NUM_THREADS; i++) {
    thread_id[i] = i;
    int rc = pthread_create(&threads[i], NULL, thread_func, &thread_id[i]);
    if (rc) {
      printf("Error creating thread %d\n", i);
      exit(-1);
    }
  }

  // Join threads
  for (int i = 0; i < NUM_THREADS; i++) {
    int rc = pthread_join(threads[i], NULL);
    if (rc) {
      printf("Error joining thread %d\n", i);
      exit(-1);
    }
  }

  // Destroy mutex lock
  pthread_mutex_destroy(&lock);

  return 0;
}