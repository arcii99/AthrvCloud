//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

/*
This program demonstrates a simple implementation of C Threading Library with mutual exclusion.
The program will create threads to print out 10 consecutive numbers.

*/

// The maximum number of threads that can be created.
#define MAX_THREADS 10

// The total number of iterations each thread runs to print consecutive numbers.
#define ITERATIONS 10

// Shared resource for the threads.
int shared_counter = 0;

// The mutex lock to ensure mutual exclusion.
pthread_mutex_t lock;

// Thread function to print consecutive numbers.
void* print_numbers(void* arg) {
  int thread_num = *(int*)arg;
  int local_counter;

  for (int i = 0; i < ITERATIONS; i++) {
    pthread_mutex_lock(&lock); // Lock before modifying shared resource.
    local_counter = shared_counter;
    shared_counter++;
    pthread_mutex_unlock(&lock); // Unlock after modifying shared resource.

    printf("Thread %d prints number %d \n", thread_num, local_counter);
  }

  return NULL;
}

int main() {
  // Initialize mutex lock.
  if (pthread_mutex_init(&lock, NULL) != 0) {
    printf("Mutex lock initialization failed!\n");
    exit(EXIT_FAILURE);
  }

  pthread_t threads[MAX_THREADS]; // Array to store threads.
  int thread_nums[MAX_THREADS]; // Array to store thread numbers.

  // Create threads.
  for (int i = 0; i < MAX_THREADS; i++) {
    thread_nums[i] = i;
    if (pthread_create(&threads[i], NULL, print_numbers, &thread_nums[i]) != 0) {
      printf("Thread creation failed!\n");
      exit(EXIT_FAILURE);
    }
  }

  // Wait for threads to finish.
  for (int i = 0; i < MAX_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  // Destroy mutex lock.
  pthread_mutex_destroy(&lock);

  return 0;
}