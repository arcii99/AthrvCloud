//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

// Define the shared variables
#define MAX_FLOORS 10
#define MAX_PASSENGERS 20

// Define the elevator struct
struct elevator {
  int current_floor;
  int direction; // 1 for up, -1 for down
  int num_passengers;
  int capacity;
  int passengers[MAX_PASSENGERS];
  sem_t passenger_count;
  pthread_mutex_t mutex;
} elevator;

// Define the floor struct
struct floor {
  int num_waiting;
  sem_t waiting_count;
  pthread_mutex_t mutex;
} floors[MAX_FLOORS];

// Define the passenger struct
struct passenger {
  int id;
  int src_floor;
  int dest_floor;
};

// Define the function for the passenger thread
void *passenger_thread(void *arg) {
  struct passenger *p = (struct passenger *) arg;

  // Wait for the elevator to arrive
  pthread_mutex_lock(&floors[p->src_floor].mutex);
  floors[p->src_floor].num_waiting++;
  pthread_mutex_unlock(&floors[p->src_floor].mutex);
  sem_wait(&floors[p->src_floor].waiting_count);

  // Enter the elevator
  sem_wait(&elevator.passenger_count);
  pthread_mutex_lock(&elevator.mutex);
  elevator.passengers[elevator.num_passengers++] = p->id;
  pthread_mutex_unlock(&elevator.mutex);

  // Await arrival at destination
  while (elevator.current_floor != p->dest_floor);

  // Leave the elevator
  sem_post(&elevator.passenger_count);
  pthread_mutex_lock(&elevator.mutex);
  for (int i = 0; i < elevator.num_passengers; i++) {
    if (elevator.passengers[i] == p->id) {
      elevator.passengers[i] = elevator.passengers[--elevator.num_passengers];
      break;
    }
  }
  pthread_mutex_unlock(&elevator.mutex);

  printf("Passenger %d has arrived on floor %d.\n", p->id, p->dest_floor);
  free(arg);
  return NULL;
}

// Define the function for the elevator thread
void *elevator_thread(void *arg) {
  while (1) {
    // Move the elevator
    if (elevator.direction == 1 && elevator.current_floor == MAX_FLOORS - 1) {
      elevator.direction = -1;
    } else if (elevator.direction == -1 && elevator.current_floor == 0) {
      elevator.direction = 1;
    } else {
      elevator.current_floor += elevator.direction;
    }

    // Check for passengers to pick up
    pthread_mutex_lock(&floors[elevator.current_floor].mutex);
    if (floors[elevator.current_floor].num_waiting > 0 && elevator.num_passengers < elevator.capacity) {
      sem_post(&floors[elevator.current_floor].waiting_count);
      floors[elevator.current_floor].num_waiting--;
    }
    pthread_mutex_unlock(&floors[elevator.current_floor].mutex);

    // Check for passengers to drop off
    pthread_mutex_lock(&elevator.mutex);
    for (int i = 0; i < elevator.num_passengers; i++) {
      if (elevator.passengers[i] == elevator.current_floor) {
        sem_post(&elevator.passenger_count);
        elevator.passengers[i] = elevator.passengers[--elevator.num_passengers];
        printf("Passenger has left the elevator on floor %d.\n", elevator.current_floor);
      }
    }
    pthread_mutex_unlock(&elevator.mutex);

    // Sleep for 1 second to simulate time passing
    sleep(1);
  }
}

int main() {
  // Initialize the elevator
  elevator.current_floor = 0;
  elevator.direction = 1;
  elevator.num_passengers = 0;
  elevator.capacity = 10;
  sem_init(&elevator.passenger_count, 0, elevator.capacity);
  pthread_mutex_init(&elevator.mutex, NULL);

  // Initialize the floors
  for (int i = 0; i < MAX_FLOORS; i++) {
    floors[i].num_waiting = 0;
    sem_init(&floors[i].waiting_count, 0, 0);
    pthread_mutex_init(&floors[i].mutex, NULL);
  }

  // Create the elevator thread
  pthread_t elevator_thread_id;
  pthread_create(&elevator_thread_id, NULL, elevator_thread, NULL);

  // Create the passenger threads
  for (int i = 0; i < 20; i++) {
    struct passenger *p = malloc(sizeof(struct passenger));
    p->id = i;
    p->src_floor = rand() % 10;
    p->dest_floor = rand() % 10;
    pthread_t passenger_thread_id;
    pthread_create(&passenger_thread_id, NULL, passenger_thread, p);
  }

  // Wait for the elevator thread to exit (never)
  pthread_join(elevator_thread_id, NULL);

  return 0;
}