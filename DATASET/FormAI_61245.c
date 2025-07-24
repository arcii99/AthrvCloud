//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t count_mutex;
pthread_cond_t condition_var;

void *functionCount1();
void *functionCount2();
int count = 0;
#define COUNT_DONE 10
#define COUNT_THREAD1 1
#define COUNT_THREAD2 2

int main()
{
  pthread_t thread1, thread2;

  pthread_mutex_init(&count_mutex, NULL);
  pthread_cond_init(&condition_var, NULL);

  pthread_create(&thread1, NULL, &functionCount1, NULL);
  pthread_create(&thread2, NULL, &functionCount2, NULL);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  printf("Final count: %d\n", count);

  pthread_mutex_destroy(&count_mutex);
  pthread_cond_destroy(&condition_var);

  exit(EXIT_SUCCESS);
}

void *functionCount1()
{
  for (;;)
  {
    pthread_mutex_lock(&count_mutex);

    while (count % 2 == 1)
      pthread_cond_wait(&condition_var, &count_mutex);

    count++;
    printf("Counter value functionCount1: %d\n", count);

    pthread_mutex_unlock(&count_mutex);

    if (count >= COUNT_DONE)
      return (NULL);
  }
}

void *functionCount2()
{
  for (;;)
  {
    pthread_mutex_lock(&count_mutex);

    while (count % 2 == 0)
      pthread_cond_wait(&condition_var, &count_mutex);

    count++;
    printf("Counter value functionCount2: %d\n", count);

    pthread_mutex_unlock(&count_mutex);

    if (count >= COUNT_DONE)
      return (NULL);
  }
}