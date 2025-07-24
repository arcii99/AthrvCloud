//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 4

typedef struct {
  int current_floor;
  int destination_floor;
  int capacity;
} elevator_t;

typedef struct {
  int id;
  pthread_mutex_t lock;
  pthread_cond_t cond;
  elevator_t elev;
} elevator_package_t;

elevator_package_t elevators[NUM_ELEVATORS];

void* elevator_thread(void* arg) {
  elevator_package_t* pack = (elevator_package_t*)arg;
  elevator_t* elev = &pack->elev;
  pthread_mutex_t* lock = &pack->lock;
  pthread_cond_t* cond = &pack->cond;

  while (1) {
    // Wait for a request from user
    pthread_mutex_lock(lock);
    pthread_cond_wait(cond, lock);

    // Move elevator to destination floor
    if (elev->current_floor < elev->destination_floor) {
      printf("Elevator %d going up from floor %d to floor %d\n",
        pack->id, elev->current_floor, elev->destination_floor);
      while (elev->current_floor < elev->destination_floor) {
        elev->current_floor++;
        printf("Elevator %d at floor %d\n", pack->id, elev->current_floor);
      }
    } else {
      printf("Elevator %d going down from floor %d to floor %d\n",
        pack->id, elev->current_floor, elev->destination_floor);
      while (elev->current_floor > elev->destination_floor) {
        elev->current_floor--;
        printf("Elevator %d at floor %d\n", pack->id, elev->current_floor);
      }
    }

    // Open doors and let passengers in/out
    printf("Elevator %d doors opening\n", pack->id);
    sleep(2);
    printf("Elevator %d doors closing\n", pack->id);

    // Reset destination and notify waiting users
    elev->destination_floor = -1;
    pthread_cond_broadcast(cond);
    pthread_mutex_unlock(lock);
  }
}

void request_elevator(int floor, int dest) {
  // Find the closest elevator
  int best_id = -1;
  int best_dist = 999;
  for(int i = 0; i < NUM_ELEVATORS; i++) {
    elevator_t* elev = &elevators[i].elev;
    if (elev->destination_floor < 0) {
      int dist = elev->current_floor > floor ? elev->current_floor - floor : floor - elev->current_floor;
      if (dist < best_dist) {
        best_dist = dist;
        best_id = i;
      }
    }
  }

  // Wait for that elevator to arrive
  elevator_package_t* pack = &elevators[best_id];
  elevator_t* elev = &pack->elev;
  pthread_mutex_t* lock = &pack->lock;
  pthread_cond_t* cond = &pack->cond;
  pthread_mutex_lock(lock);
  elev->destination_floor = floor;
  printf("User requested elevator to floor %d, waiting for elevator %d\n",
      floor, pack->id);
  while (elev->destination_floor >= 0) {
    pthread_cond_signal(cond);
    pthread_cond_wait(cond, lock);
  }
  elev->destination_floor = dest;
  printf("User entering elevator %d, destination floor %d\n",
      pack->id, dest);
  pthread_cond_signal(cond);
  pthread_cond_wait(cond, lock);
  printf("User exiting elevator %d at floor %d\n",
      pack->id, elev->current_floor);
  pthread_mutex_unlock(lock);
}

int main() {
  // Initialize elevators
  for(int i = 0; i < NUM_ELEVATORS; i++) {
    elevator_t* elev = &elevators[i].elev;
    pthread_mutex_init(&elevators[i].lock, NULL);
    pthread_cond_init(&elevators[i].cond, NULL);
    elev->current_floor = 0;
    elev->destination_floor = -1;
    elev->capacity = 10;
    elevators[i].id = i;
    pthread_t tid;
    pthread_create(&tid, NULL, elevator_thread, (void*)&elevators[i]);
  }

  // Test the elevators
  request_elevator(5, 2);
  request_elevator(9, 4);
  request_elevator(0, 8);

  return 0;
}