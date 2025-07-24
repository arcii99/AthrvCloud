//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_ELEVATORS 4
#define MAX_FLOORS 10
#define MAX_PASSENGERS 10

// Global Variables
sem_t semaphore[MAX_FLOORS]; // Floors semaphore
sem_t move_sem; // Semaphore to lock / release elevator movement
pthread_mutex_t lockQueue; // Mutex to lock queue of passengers inside elevators
pthread_mutex_t lockPrint; // Mutex to lock print statements when writing to terminal
int passengersCount = 0; // Count of passengers
int passengers_waiting_on_floor[MAX_FLOORS]; // Number of waiting passengers on each floor
int passengers_in_elevator[MAX_ELEVATORS]; // Number of passengers in each elevator
int current_floor[MAX_ELEVATORS]; // Current floor of each elevator
int queue[MAX_ELEVATORS][MAX_PASSENGERS]; // Queue of passengers inside each elevator

// Function to initialize the semaphores and locks
void init() {
  int i;
  
  for(i = 0; i < MAX_FLOORS; i++) {
    sem_init(&semaphore[i], 0, 0); // Init with 0
  }
  
  pthread_mutex_init(&lockQueue, NULL);
  pthread_mutex_init(&lockPrint, NULL);
  sem_init(&move_sem, 0, 1);
}

// Function to simulate passenger's journey
void *passenger(void *arg) {
  int passID = *(int *)arg;
  int cur_floor = rand() % MAX_FLOORS;
  int dest_floor = rand() % MAX_FLOORS;
  
  while(cur_floor == dest_floor) {
    dest_floor = rand() % MAX_FLOORS;
  }
  sleep(rand() % 10); // Wait for some time before arriving on floor
  
  pthread_mutex_lock(&lockPrint);
  passengers_waiting_on_floor[cur_floor]++;
  printf("[PASSENGER] Passenger %d has arrived on Floor %d and waiting for the Elevator.\n", passID, cur_floor);
  pthread_mutex_unlock(&lockPrint);
  
  sem_wait(&semaphore[cur_floor]); // Wait for elevator to arrive
  pthread_mutex_lock(&lockQueue);
  queue[current_floor[dest_floor]][passengersCount] = passID; // Add this passenger to the queue of the elevator
  passengersCount++;
  pthread_mutex_unlock(&lockQueue);
  pthread_mutex_lock(&lockPrint);
  printf("[PASSENGER] Passenger %d has entered Elevator %d going to Floor %d.\n", passID, current_floor[dest_floor], dest_floor);
  passengers_waiting_on_floor[cur_floor]--;
  pthread_mutex_unlock(&lockPrint);
  sem_post(&move_sem); // Unlock the move_sem so the elevator can move to the destination floor
  sem_wait(&semaphore[dest_floor]); // Wait for Elevator to arrive 
  pthread_mutex_lock(&lockQueue);
  int i;
  for(i=0; i<passengersCount; i++) {
    if(queue[dest_floor][i] == passID) { // Remove the passenger from the elevator queue
      queue[dest_floor][i] = -1; // Use -1 to mark empty space in array in the queue.
    }
  }
  passengersCount--;
  passengers_in_elevator[current_floor[dest_floor]]--;
  pthread_mutex_unlock(&lockQueue);
  pthread_mutex_lock(&lockPrint);
  printf("[PASSENGER] Passenger %d has arrived at Floor %d and exited from Elevator %d.\n", passID, dest_floor, current_floor[dest_floor]);
  pthread_mutex_unlock(&lockPrint);
  sem_post(&semaphore[dest_floor]); // Unlock the floor semaphore so other passengers can now board the elevator
  pthread_exit(NULL);
}

// Function to simulate the elevators journey
void *elevator(void *arg) {
  int id = *(int *)arg;
  int dest_floor = -1; // keep track of destination floor of elevator
  
  while(1) {
    sem_wait(&move_sem); // Wait to lock the move_sem to start elevator movement
    pthread_mutex_lock(&lockQueue);
    int i;
    
    // Loop through the passengers queue and add passengers to the elevator.
    for(i=0; i<MAX_PASSENGERS; i++) {
      if(queue[id][i] > -1) { // If there is a passenger
        if(passengers_in_elevator[id] < MAX_PASSENGERS && current_floor[id] == dest_floor) { // If there is space in the elevator and Elevator has arrived at floor where passenger is waiting
          passengers_in_elevator[id]++;
          dest_floor = queue[id][i] / 10; // Get Destination floor from the passenger ID
        } 
      }
    }
    
    // Algorithm to move the Elevator to Destination floor(now we're just adding delay)
    while(current_floor[id] != dest_floor) {
      sleep(1);
      pthread_mutex_lock(&lockPrint);
      if(current_floor[id] < dest_floor) {
        printf("[ELEVATOR %d] Moving up to Floor %d.\n", id, ++current_floor[id]);
      } else {
        printf("[ELEVATOR %d] Moving down to Floor %d.\n", id, --current_floor[id]);
      }
      pthread_mutex_unlock(&lockPrint);
    }
    pthread_mutex_unlock(&lockQueue);
    sem_post(&semaphore[dest_floor]); // Unlock the floor semaphore so passengers can board the elevator
  } 
}

int main() {
  init();
  pthread_t P[MAX_PASSENGERS], E[MAX_ELEVATORS];
  
  int i;
  for(i=0; i<MAX_ELEVATORS; i++) {
    current_floor[i] = 0;
    passengers_in_elevator[i] = 0;
    pthread_create(&E[i], NULL, elevator, &i);
  }
  
  int passengersID[MAX_PASSENGERS];
  for(i=0; i<MAX_PASSENGERS; i++) {
    sem_post(&semaphore[i%MAX_FLOORS]); // Generate passengers randomly for boarding at different floors
    passengersID[i] = rand() % 100 + (i*10); // Use a unique ID to understand the destination floor of the passenger
    pthread_create(&P[i], NULL, passenger, &passengersID[i]);    
  }
  
  for(i = 0; i < MAX_ELEVATORS; i++) {
    pthread_join(E[i], NULL);
  }
  for(i = 0; i < MAX_PASSENGERS; i++) {
    pthread_join(P[i], NULL);
  }
  
  return 0;
}