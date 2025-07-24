//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

#define NUM_THREADS 5
#define MAX_BAGS 10
#define BELT_CAPACITY 5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t bags_on_belt = PTHREAD_COND_INITIALIZER;
pthread_cond_t bags_on_plane = PTHREAD_COND_INITIALIZER;

int belt[BELT_CAPACITY];
int bags_ready = 0;
int bags_loaded = 0;
int bags_out = 0;

bool take_bag(int id) {
  pthread_mutex_lock(&mutex);

  while (bags_ready == 0)
    pthread_cond_wait(&bags_on_belt, &mutex);

  int bag = belt[bags_ready - 1];
  bags_ready--;

  printf("Belt Handler %d took bag %d from belt\n", id, bag);

  pthread_mutex_unlock(&mutex);

  return true;
}

bool load_bag(int id) {
  pthread_mutex_lock(&mutex);

  while (bags_loaded == MAX_BAGS)
    pthread_cond_wait(&bags_on_plane, &mutex);

  belt[bags_ready] = id;
  bags_ready++;

  printf("Loader %d loaded a bag on the belt\n", id);

  pthread_cond_signal(&bags_on_belt);
  pthread_mutex_unlock(&mutex);

  return true;
}

bool unload_bags(int id) {
  pthread_mutex_lock(&mutex);

  while (bags_ready != 0)
    pthread_cond_wait(&bags_on_plane, &mutex);

  printf("Unloader %d unloaded all bags from plane\n", id);
  bags_out = 0;

  pthread_cond_signal(&bags_on_belt);
  pthread_mutex_unlock(&mutex);

  return true;
}

bool load_plane(int id) {
  pthread_mutex_lock(&mutex);

  while (bags_ready != 0)
    pthread_cond_wait(&bags_on_belt, &mutex);

  int i;
  printf("Loader %d is loading bags on the plane\n", id);
  for (i = 0; i < BELT_CAPACITY; i++) {
    bags_loaded++;
    bags_out++;
  }

  pthread_cond_signal(&bags_on_plane);
  pthread_mutex_unlock(&mutex);

  return true;
}

void *belt_handler(void *thread_id) {
  int id = (int)(long)thread_id;

  while (true) {
    take_bag(id);
    usleep(100000);
  }
}

void *loader(void *thread_id) {
  int id = (int)(long)thread_id;

  while (true) {
    load_bag(id);
    usleep(250000);
  }
}

void *unloader(void *thread_id) {
  int id = (int)(long)thread_id;

  while (true) {
    unload_bags(id);
    usleep(250000);
  }
}

void *plane_loader(void *thread_id) {
  int id = (int)(long)thread_id;

  while (true) {
    load_plane(id);
    usleep(500000);
  }
}

int main() {
  int i;
  pthread_t threads[NUM_THREADS];

  // Belt handlers
  for (i = 0; i < 2; i++)
    pthread_create(&threads[i], NULL, belt_handler, (void *)(long)i);

  // Loaders
  for (i = 2; i < 4; i++)
    pthread_create(&threads[i], NULL, loader, (void *)(long)i);

  // Unloaders
  for (i = 4; i < 5; i++)
    pthread_create(&threads[i], NULL, unloader, (void *)(long)i);

  // Plane loader
  pthread_create(&threads[5], NULL, plane_loader, (void *)(long)i);

  // Join threads
  for (i = 0; i < NUM_THREADS; i++)
    pthread_join(threads[i], NULL);

  printf("Simulation finished\n");

  return 0;
}