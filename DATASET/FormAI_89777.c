//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: accurate
#include <stdio.h>
#include <pthread.h>

/* Define a global variable */
int global_variable = 0;

/* Define a mutex variable */
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

/* Define a thread function */
void *thread_function(void *arg)
{
  /* Acquire the mutex lock */
  pthread_mutex_lock(&mutex);

  /* Modify the global variable */
  global_variable++;

  /* Release the mutex lock */
  pthread_mutex_unlock(&mutex);

  return NULL;
}

int main()
{
  /* Declare some variables */
  int i;
  pthread_t thread[10];

  /* Create 10 threads */
  for (i = 0; i < 10; i++) {
    pthread_create(&thread[i], NULL, thread_function, NULL);
  }

  /* Wait for all threads to finish */
  for (i = 0; i < 10; i++) {
    pthread_join(thread[i], NULL);
  }

  /* Print the final value of the global variable */
  printf("The final value of the global variable is %d\n", global_variable);

  return 0;
}