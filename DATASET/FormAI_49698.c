//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define BUFFER_SIZE 10
#define NUM_THREADS 2

// Shared variables
int buffer[BUFFER_SIZE];
int count = 0;

// Mutexes
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;

// Condition variables
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond2 = PTHREAD_COND_INITIALIZER;

// Checksum variable
int checksum = 0;

// Checksum Calculator function
void *checksum_calculator(void *arg) {
  int thread_id = *(int *) arg;
  
  while (1) {
    // Acquire mutex1 and wait for items in buffer
    pthread_mutex_lock(&mutex1);
    while (count == 0) {
      pthread_cond_wait(&cond1, &mutex1);
    }

    // Calculate checksum of data in buffer
    int temp_checksum = 0;
    for (int i = 0; i < count; i++) {
      temp_checksum += buffer[i];
    }
    printf("Thread %d calculating checksum: %d\n", thread_id, temp_checksum);

    // Acquire mutex2 and update checksum
    pthread_mutex_lock(&mutex2);
    checksum += temp_checksum;
    pthread_mutex_unlock(&mutex2);

    // Reset buffer count and signal producer
    count = 0;
    pthread_cond_signal(&cond2);

    // Release mutexes
    pthread_mutex_unlock(&mutex1);
    pthread_mutex_unlock(&mutex2);
  }

  pthread_exit(NULL);
}

// Producer function
void *producer(void *arg) {
  int input_data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  for (int i = 0; i < 10; i++) {
    // Acquire mutex1 and wait for space in buffer
    pthread_mutex_lock(&mutex1);
    while (count == BUFFER_SIZE) {
      pthread_cond_wait(&cond2, &mutex1);
    }

    // Add data to buffer and increase count
    buffer[count] = input_data[i];
    count++;

    // Signal checksum calculator
    pthread_cond_signal(&cond1);

    // Release mutex
    pthread_mutex_unlock(&mutex1);
  }

  pthread_exit(NULL);
}

int main() {
  pthread_t threads[NUM_THREADS];
  int thread_ids[NUM_THREADS] = {1, 2};
  
  // Create threads
  pthread_create(&threads[0], NULL, checksum_calculator, (void *) &thread_ids[0]);
  pthread_create(&threads[1], NULL, producer, NULL);

  // Join threads
  pthread_join(threads[0], NULL);
  pthread_join(threads[1], NULL);

  // Print checksum result
  printf("Checksum: %d\n", checksum);

  return 0;
}