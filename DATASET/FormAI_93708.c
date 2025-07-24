//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 10
#define MAX_LUGGAGE 100

int buffer[BUFFER_SIZE];
int buffer_index = 0;
pthread_mutex_t mutex;
sem_t full, empty;

// producer thread to generate luggages and fill them in the buffer
void* producer(void* arg) {
  int luggage, i;

  for (i = 0; i < MAX_LUGGAGE; i++) {
    luggage = rand();
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);

    if (buffer_index < BUFFER_SIZE) {
      buffer[buffer_index++] = luggage;
      printf("Produced luggage %d\n", luggage);
    } else {
      printf("Buffer is full\n");
    }

    pthread_mutex_unlock(&mutex);
    sem_post(&full);
    sleep(1);
  }

  pthread_exit(NULL);
}

// consumer thread to remove luggages from the buffer
void* consumer(void* arg) {
  int luggage, i;

  for (i = 0; i < MAX_LUGGAGE; i++) {
    sem_wait(&full);
    pthread_mutex_lock(&mutex);

    if (buffer_index > 0) {
      luggage = buffer[--buffer_index];
      printf("Consumed luggage %d\n", luggage);
    } else {
      printf("Buffer is empty\n");
    }

    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
    sleep(1);
  }

  pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
  pthread_t producer_thread, consumer_thread;

  // initialize mutex and semaphores
  pthread_mutex_init(&mutex, NULL);
  sem_init(&full, 0, 0);
  sem_init(&empty, 0, BUFFER_SIZE);

  // create threads
  pthread_create(&producer_thread, NULL, producer, NULL);
  pthread_create(&consumer_thread, NULL, consumer, NULL);

  // wait for threads to complete
  pthread_join(producer_thread, NULL);
  pthread_join(consumer_thread, NULL);

  // cleanup
  pthread_mutex_destroy(&mutex);
  sem_destroy(&full);
  sem_destroy(&empty);

  return 0;
}