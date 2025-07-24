//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *start_routine(void *arg) {
  int *thread_no = (int *)arg;
  printf("Thread %d is starting\n", *thread_no);
  printf("Thread %d is running\n", *thread_no);
  printf("Thread %d is exiting\n", *thread_no);
  free(arg);
  pthread_exit(NULL);
}

int cryptic_thread_create(pthread_t *thread, const pthread_attr_t *attr,
                              void *(*start_routine)(void *), void *arg) {
  int *thread_no = (int *)malloc(sizeof(int));
  *thread_no = rand() % 100000;

  printf("Creating thread %d...\n", *thread_no);
  
  return pthread_create(thread, attr, start_routine, (void *) thread_no);
}

int main() {
  pthread_t thread;

  if (cryptic_thread_create(&thread, NULL, start_routine, NULL) != 0) {
            printf("Error: failed to create thread\n");
            return 1;
  }
  
  pthread_join(thread, NULL);

  return 0;
}