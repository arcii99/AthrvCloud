//FormAI DATASET v1.0 Category: System administration ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define NUM_TASKS 10

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
static int num_tasks_left = 0;

void *task_func(void *arg) {
  char *task = (char *)arg;
  printf("Starting task: %s\n", task);
  sleep(2);
  printf("Finished task: %s\n", task);

  pthread_mutex_lock(&mutex);
  num_tasks_left--;
  pthread_mutex_unlock(&mutex);
  pthread_cond_signal(&cond);

  return NULL;
}

int main() {
  pthread_t threads[NUM_TASKS];
  char *tasks[NUM_TASKS] = {"task1", "task2", "task3", "task4", "task5", "task6", "task7", "task8", "task9", "task10"};
  int i;

  printf("Starting %d tasks...\n", NUM_TASKS);

  pthread_mutex_lock(&mutex);
  for (i = 0; i < NUM_TASKS; i++) {
    num_tasks_left++;
    if (pthread_create(&threads[i], NULL, task_func, (void *)tasks[i]) != 0) {
      fprintf(stderr, "Error creating thread: %s\n", strerror(errno));
      exit(EXIT_FAILURE);
    }
  }

  while (num_tasks_left > 0) {
    pthread_cond_wait(&cond, &mutex);
  }

  pthread_mutex_unlock(&mutex);
  pthread_cond_destroy(&cond);
  pthread_mutex_destroy(&mutex);

  printf("All tasks completed.\n");
  return 0;
}