//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex_lock;
int count;

void *increment_count(void *arg) {
  int i;
  for(i = 0; i < 100000; i++) {
    pthread_mutex_lock(&mutex_lock);
    count++;
    pthread_mutex_unlock(&mutex_lock);
  }
  pthread_exit(NULL);
}

int main() {
  pthread_t thread1, thread2;

  pthread_mutex_init(&mutex_lock, NULL);

  if(pthread_create(&thread1, NULL, increment_count, NULL) != 0) {
    printf("Error while creating thread 1!\n");
    exit(1);
  }

  if(pthread_create(&thread2, NULL, increment_count, NULL) != 0) {
    printf("Error while creating thread 2!\n");
    exit(1);
  }

  if(pthread_join(thread1, NULL) != 0) {
    printf("Error while joining thread 1!\n");
    exit(1);
  }

  if(pthread_join(thread2, NULL) != 0) {
    printf("Error while joining thread 2!\n");
    exit(1);
  }

  pthread_mutex_destroy(&mutex_lock);

  printf("Final count value: %d\n", count);

  return 0;
}