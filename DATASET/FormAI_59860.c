//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_NUM 5

void *thread_function(void *id)
{
  int thread_id = *(int *)id;
  
  printf("Thread %d is running\n", thread_id);
  
  pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
  pthread_t threads[THREAD_NUM];
  int thread_ids[THREAD_NUM];
  int i;

  for (i = 0; i < THREAD_NUM; i++) {
    thread_ids[i] = i;
    pthread_create(&threads[i], NULL, thread_function, (void *)&thread_ids[i]);
  }

  for (i = 0; i < THREAD_NUM; i++) {
    pthread_join(threads[i], NULL);
  }
  
  printf("All threads have completed\n");

  return 0;
}