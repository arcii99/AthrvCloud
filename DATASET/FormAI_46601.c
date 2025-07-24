//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 3
#define CAPACITY 10

int floorQueue[NUM_FLOORS];  // number of people waiting on each floor
int elevatorStatus[NUM_ELEVATORS]; // 0 for idle, 1 for moving up, -1 for moving down
int elevatorFloor[NUM_ELEVATORS]; // current floor of each elevator
int elevatorCapacity[NUM_ELEVATORS]; // number of occupants in each elevator
int elevatorOccupants[NUM_ELEVATORS][CAPACITY]; // occupants of each elevator
pthread_mutex_t floorQueueLock, elevatorLock[NUM_ELEVATORS];

void *elevator(void *arg) {
  int id = *(int*)arg;
  int floor = 0; // starting floor
  int direction = 1; // starting direction
  while(1) {
    pthread_mutex_lock(&elevatorLock[id]);
    // check if we need to change direction
    if (elevatorFloor[id] == 0 || elevatorFloor[id] == NUM_FLOORS-1) direction = -direction;
    // check if we should stop at this floor
    if (elevatorStatus[id] == direction && floorQueue[elevatorFloor[id]] > 0) {
      // unload passengers
      for (int i=0; i<elevatorCapacity[id]; i++) {
        if (elevatorOccupants[id][i] == elevatorFloor[id]) {
          elevatorOccupants[id][i] = -1;
          printf("Elevator %d unloaded a passenger on floor %d\n", id, elevatorFloor[id]);
        }
      }
      // load passengers
      for (int i=0; i<CAPACITY-elevatorCapacity[id]; i++) {
        if (floorQueue[elevatorFloor[id]] == 0) break;
        elevatorOccupants[id][elevatorCapacity[id]+i] = elevatorFloor[id];
        elevatorCapacity[id]++;
        floorQueue[elevatorFloor[id]]--;
        printf("Elevator %d loaded a passenger on floor %d\n", id, elevatorFloor[id]);
      }
    }
    // move elevator
    elevatorFloor[id] += direction;
    elevatorStatus[id] = direction;
    pthread_mutex_unlock(&elevatorLock[id]);
    sleep(1); // simulate moving to next floor
  }
  return NULL;
}

void *person(void *arg) {
  int floor = *(int*)arg;
  while(1) {
    sleep(rand()%10); // simulate waiting between 0 and 9 seconds
    pthread_mutex_lock(&floorQueueLock);
    floorQueue[floor]++;
    printf("A person is waiting on floor %d\n", floor);
    pthread_mutex_unlock(&floorQueueLock);
  }
  return NULL;
}

int main() {
  pthread_t elevators[NUM_ELEVATORS], people[NUM_FLOORS];
  pthread_mutex_init(&floorQueueLock, NULL);
  for (int i=0; i<NUM_ELEVATORS; i++) pthread_mutex_init(&elevatorLock[i], NULL);
  int elevatorIds[NUM_ELEVATORS];
  for (int i=0; i<NUM_ELEVATORS; i++) {
    elevatorIds[i] = i;
    pthread_create(&elevators[i], NULL, elevator, &elevatorIds[i]);
  }
  int floorIds[NUM_FLOORS];
  for (int i=0; i<NUM_FLOORS; i++) {
    floorIds[i] = i;
    pthread_create(&people[i], NULL, person, &floorIds[i]);
  }
  for (int i=0; i<NUM_ELEVATORS; i++) pthread_join(elevators[i], NULL);
  for (int i=0; i<NUM_FLOORS; i++) pthread_join(people[i], NULL);
  return 0;
}