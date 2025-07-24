//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: funny
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *thread_fun(void *arg) {
  int *val = (int *)arg;
  printf("Thread number %d says: Hi there! I'm alive!\n", *val);
  sleep(2);
  printf("Thread number %d says: I'm feeling sleepy... Goodnight!\n", *val);
  return NULL;
}

int main() {
  pthread_t threads[5];

  printf("Creating 5 threads\n");
  for (int i = 0; i < 5; i++) {
    int *val = malloc(sizeof(int));
    *val = i;
    pthread_create(&threads[i], NULL, thread_fun, (void *)val);
  }

  printf("Waiting for threads to finish\n");
  for (int i = 0; i < 5; i++) {
    pthread_join(threads[i], NULL);
    printf("Thread number %d has finished\n", i);
  }

  printf("All threads have finished executing\n");
  return 0;
}