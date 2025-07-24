//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

struct thread_data {
  int thread_id;
  int sum;
};

void* runner(void* arg) {
  struct thread_data* td = (struct thread_data*) arg;
  int start = td->thread_id * td->sum;
  int end = start + td->sum - 1;
  int i, sum = 0;
  
  for (i = start; i <= end; i++) {
    sum += i;
  }

  td->sum = sum;

  pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
  int i, sum = 0;
  pthread_t threads[NUM_THREADS];
  struct thread_data td[NUM_THREADS];

  // Initialize thread data
  for (i = 0; i < NUM_THREADS; i++) {
    td[i].thread_id = i;
    td[i].sum = 100;
  }

  // Create threads
  for (i = 0; i < NUM_THREADS; i++) {
    pthread_create(&threads[i], NULL, runner, (void*) &td[i]);
  }

  // Wait for threads to finish and accumulate partial sums
  for (i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
    sum += td[i].sum;
  }

  printf("The sum of the numbers from 1 to 400 is %d\n", sum);

  pthread_exit(NULL);
}