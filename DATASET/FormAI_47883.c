//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int total_bags = 0;
pthread_mutex_t baggage_lock;
pthread_cond_t conveyor_empty;

void* passenger(void* arg) {
  int num_bags = rand() % 6 + 1; // random number of bags between 1 and 6
  pthread_mutex_lock(&baggage_lock);
  total_bags += num_bags;
  printf("Passenger dropped off %d bags. Total bags: %d\n", num_bags, total_bags);
  pthread_cond_signal(&conveyor_empty);
  pthread_mutex_unlock(&baggage_lock);
  return NULL;
}

void* conveyor(void* arg) {
  while(1) {
    pthread_mutex_lock(&baggage_lock);
    while(total_bags == 0) {
      printf("Conveyor is empty\n");
      pthread_cond_wait(&conveyor_empty, &baggage_lock);
    }
    printf("Moving bag to airplane...\n");
    total_bags--;
    pthread_mutex_unlock(&baggage_lock);
    sleep(1); // simulate moving the bag
  }
  return NULL;
}

int main() {
  pthread_t pass_thread[10], conveyor_thread;
  pthread_mutex_init(&baggage_lock, NULL);
  pthread_cond_init(&conveyor_empty, NULL);

  // Creating conveyor thread
  pthread_create(&conveyor_thread, NULL, conveyor, NULL);
  for(int i = 0; i < 10; i++) {
    // Creating passenger threads
    pthread_create(&pass_thread[i], NULL, passenger, NULL);
  }

  for(int i = 0; i < 10; i++) {
    // Waiting for passenger threads to finish
    pthread_join(pass_thread[i], NULL);
  }

  pthread_cancel(conveyor_thread);
  pthread_mutex_destroy(&baggage_lock);
  pthread_cond_destroy(&conveyor_empty);
  return 0;
}