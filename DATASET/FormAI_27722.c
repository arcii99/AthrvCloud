//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: peaceful
#include <stdio.h>
#include <pthread.h>

#define MAX_THREADS 10

// Struct to store the thread information
struct thread_info {
  int thread_id;
  int sum;
};

// Mutex object to lock and unlock shared resources
pthread_mutex_t mutex_lock = PTHREAD_MUTEX_INITIALIZER;

// Function to be executed by threads
void *thread_function(void *arg) {
  struct thread_info *t_info;
  int j, sum = 0;

  t_info = (struct thread_info *) arg;

  // Calculate the sum
  for (j = 1; j <= t_info->thread_id; j++)
    sum += j;

  // Acquire the lock
  pthread_mutex_lock(&mutex_lock);

  // Update the global sum
  t_info->sum = sum;

  // Release the lock
  pthread_mutex_unlock(&mutex_lock);

  // Exit thread and return sum
  pthread_exit((void *) t_info);
}

int main(int argc, char *argv[]) {
  pthread_t threads[MAX_THREADS];
  struct thread_info t_info[MAX_THREADS];
  int i, sum = 0;

  // Create threads
  for (i = 0; i < MAX_THREADS; i++) {
    t_info[i].thread_id = i + 1;
    pthread_create(&threads[i], NULL, thread_function, (void *) &t_info[i]);
  }

  // Wait for threads to finish and collect the results
  for (i = 0; i < MAX_THREADS; i++) {
    void *thread_result;
    pthread_join(threads[i], &thread_result);

    struct thread_info *t_info = (struct thread_info *) thread_result;
    sum += t_info->sum;

    printf("Thread %2d: sum = %d\n", t_info->thread_id, t_info->sum);
  }

  printf("Total sum = %d\n", sum);

  return 0;
}