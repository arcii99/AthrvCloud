//FormAI DATASET v1.0 Category: Interprocess communication ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define TOTAL_THREADS 2
#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int counter = 0;
int in = 0, out = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t buffer_full_cv = PTHREAD_COND_INITIALIZER;
pthread_cond_t buffer_empty_cv = PTHREAD_COND_INITIALIZER;

void put(int value) {
  pthread_mutex_lock(&mutex);
  
  while (counter == BUFFER_SIZE) {
    printf("Buffer is full!\n");
    pthread_cond_wait(&buffer_full_cv, &mutex);
  }
  
  buffer[in] = value;
  in = (in + 1) % BUFFER_SIZE;
  counter++;
  
  pthread_cond_signal(&buffer_empty_cv);
  pthread_mutex_unlock(&mutex);
}

int get() {
  int value;
  
  pthread_mutex_lock(&mutex);
  
  while (counter == 0) {
    printf("Buffer is empty!\n");
    pthread_cond_wait(&buffer_empty_cv, &mutex);
  }
  
  value = buffer[out];
  out = (out + 1) % BUFFER_SIZE;
  counter--;
  
  pthread_cond_signal(&buffer_full_cv);
  pthread_mutex_unlock(&mutex);
  
  return value;
}

void *producer(void *arg) {
  int i;
  
  for (i = 0; i < 20; i++) {
    put(i);
    printf("Produced: %d\n", i);
    sleep(1);
  }
  
  pthread_exit(NULL);
}

void *consumer(void *arg) {
  int i, value;
  
  for (i = 0; i < 20; i++) {
    value = get();
    printf("Consumed: %d\n", value);
    sleep(1);
  }
  
  pthread_exit(NULL);
}

int main(int argc, char **argv) {
  pthread_t thread[TOTAL_THREADS];
  
  pthread_create(&thread[0], NULL, producer, NULL);
  pthread_create(&thread[1], NULL, consumer, NULL);
  
  int i;
  for (i = 0; i < TOTAL_THREADS; i++) {
    pthread_join(thread[i], NULL);
  }
  
  return 0;
}