//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t lock;

void *thread_function() {
  pthread_mutex_lock(&lock);
  printf("Inside thread function\n");
  for(int i = 1; i <= 10; i++) {
    printf("%d\t", i);
  }
  pthread_mutex_unlock(&lock);
  return NULL;
}

int main() {
  printf("Main Thread started...\n");

  pthread_t thread1, thread2;

  pthread_mutex_init(&lock, NULL); 

  if(pthread_create(&thread1, NULL, thread_function, NULL)) {
    fprintf(stderr, "Error creating thread 1");
    return 1;
  }

  if(pthread_create(&thread2, NULL, thread_function, NULL)) {
    fprintf(stderr, "Error creating thread 2");
    return 1;
  }

  if(pthread_join(thread1, NULL)) {
    fprintf(stderr, "Error joining thread 1");
    return 1;
  }

  if(pthread_join(thread2, NULL)) {
    fprintf(stderr, "Error joining thread 2");
    return 1;
  }

  pthread_mutex_destroy(&lock);
  printf("\nMain Thread exited successfully\n");

  return 0;
}