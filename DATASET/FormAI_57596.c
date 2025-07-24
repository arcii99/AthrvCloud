//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int count = 0; // Number of items in the buffer

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t can_produce = PTHREAD_COND_INITIALIZER;
pthread_cond_t can_consume = PTHREAD_COND_INITIALIZER;

void *producer(void *arg) {
  int i;

  for (i = 0; i < 20; i++) {
    pthread_mutex_lock(&mutex);

    // Wait until buffer has space to add a new item
    while (count == BUFFER_SIZE) {
      pthread_cond_wait(&can_produce, &mutex);
    }

    buffer[count] = i;
    count++;

    printf("Produced: %d\n", i);

    pthread_cond_signal(&can_consume);
    pthread_mutex_unlock(&mutex);
  }

  pthread_exit(NULL);
}

void *consumer(void *arg) {
  int i;

  for (i = 0; i < 20; i++) {
    pthread_mutex_lock(&mutex);

    // Wait until buffer has an item to consume
    while (count == 0) {
      pthread_cond_wait(&can_consume, &mutex);
    }

    int item = buffer[count-1];
    count--;
  
    printf("Consumed: %d\n", item);

    pthread_cond_signal(&can_produce);
    pthread_mutex_unlock(&mutex);
  }

  pthread_exit(NULL);
}

int main(void) {
  pthread_t producer_thread, consumer_thread;

  // Create threads
  if (pthread_create(&producer_thread, NULL, producer, NULL) != 0) {
    fprintf(stderr, "Error creating producer thread\n");
    exit(1);
  }

  if (pthread_create(&consumer_thread, NULL, consumer, NULL) != 0) {
    fprintf(stderr, "Error creating consumer thread\n");
    exit(1);
  }

  // Wait for threads to finish
  if (pthread_join(producer_thread, NULL) != 0) {
    fprintf(stderr, "Error joining producer thread\n");
    exit(1);
  }

  if (pthread_join(consumer_thread, NULL) != 0) {
    fprintf(stderr, "Error joining consumer thread\n");
    exit(1);
  }

  return 0;
}