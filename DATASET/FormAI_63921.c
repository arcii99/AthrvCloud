//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define N_BAGS 50 // Total number of bags to be handled
#define N_CONVEYORS 5 // Number of conveyors
#define N_TRUCKS 3 // Number of trucks to load baggage
#define TRUCK_CAPACITY 10 // Maximum number of bags a truck can carry
#define MAX_DELAY 2 // Maximum delay for luggage arrival and truck loading (in seconds)

// Semaphores
sem_t conveyor_sems[N_CONVEYORS]; // One semaphore for each conveyor belt
sem_t truck_sem; // Only one truck can be loaded at a time, so a binary semaphore is enough

// Threads
pthread_t conveyor_threads[N_CONVEYORS]; // One thread for each conveyor belt
pthread_t truck_threads[N_TRUCKS]; // One thread for each truck

// Shared resources
int conveyor_belts[N_CONVEYORS][TRUCK_CAPACITY]; // Bags on each conveyor belt
int conveyor_count[N_CONVEYORS] = {0}; // Current number of bags on each conveyor belt
int truck_capacity[N_TRUCKS] = {0}; // Current number of bags on each truck

// Function prototypes
void* conveyor(void* arg);
void* truck(void* arg);
void add_baggage(int luggage_id);

int main() {
  srand(time(NULL)); // Seed for random number generator
  
  // Initialize semaphores
  sem_init(&truck_sem, 0, 1); // Only one truck can be loaded at a time
  
  for (int i = 0; i < N_CONVEYORS; i++) {
    sem_init(&conveyor_sems[i], 0, 1); // Each conveyor belt semaphore is initialized to one
  }
  
  // Start conveyor threads
  for (int i = 0; i < N_CONVEYORS; i++) {
    pthread_create(&conveyor_threads[i], NULL, conveyor, (void*)i);
  }
  
  // Start truck threads
  for (int i = 0; i < N_TRUCKS; i++) {
    pthread_create(&truck_threads[i], NULL, truck, (void*)i);
  }
  
  // Wait for all threads to finish
  for (int i = 0; i < N_CONVEYORS; i++) {
    pthread_join(conveyor_threads[i], NULL);
  }
  
  for (int i = 0; i < N_TRUCKS; i++) {
    pthread_join(truck_threads[i], NULL);
  }
  
  // Clean up semaphores
  sem_destroy(&truck_sem);
  for (int i = 0; i < N_CONVEYORS; i++) {
    sem_destroy(&conveyor_sems[i]);
  }
  
  printf("All baggage has been loaded onto trucks and transported successfully.\n");
  return 0;
}

void* conveyor(void* arg) {
  int conveyor_id = (int)arg;
  while (1) {
    // Generate a random delay for luggage arrival
    int delay = (rand() % MAX_DELAY) + 1;
    sleep(delay);
    
    // Generate a unique luggage ID and add it to a conveyor belt
    int luggage_id = (rand() % N_BAGS) + 1;
    int conveyor_full = 1;
    for (int i = 0; i < TRUCK_CAPACITY; i++) {
      sem_wait(&conveyor_sems[conveyor_id]);
      if (conveyor_count[conveyor_id] < TRUCK_CAPACITY && conveyor_belts[conveyor_id][i] == 0) {
        conveyor_belts[conveyor_id][i] = luggage_id;
        conveyor_count[conveyor_id]++;
        printf("Luggage with ID %d has been added to conveyor belt %d\n", luggage_id, conveyor_id);
        conveyor_full = 0;
      }
      sem_post(&conveyor_sems[conveyor_id]);
      if (!conveyor_full) break;
    }
    if (conveyor_full) {
      printf("Conveyor belt %d is full, luggage with ID %d has been removed and discarded\n", conveyor_id, luggage_id);
    }
  }
}

void* truck(void* arg) {
  int truck_id = (int)arg;
  while (1) {
    // Wait for truck semphore to become available
    sem_wait(&truck_sem);
    
    // Load luggage onto truck
    printf("Truck %d is now loading bags\n", truck_id);
    for (int i = 0; i < TRUCK_CAPACITY; i++) {
      sem_wait(&conveyor_sems[i]);
      if (truck_capacity[truck_id] < TRUCK_CAPACITY && conveyor_count[i] > 0) {
        int luggage_id = conveyor_belts[i][0];
        truck_capacity[truck_id]++;
        conveyor_count[i]--;
        for (int j = 0; j < TRUCK_CAPACITY-1; j++) {
          conveyor_belts[i][j] = conveyor_belts[i][j+1];
        }
        conveyor_belts[i][TRUCK_CAPACITY-1] = 0;
        printf("Luggage with ID %d has been loaded onto truck %d\n", luggage_id, truck_id);
      }
      sem_post(&conveyor_sems[i]);
    }
    
    // Release truck semphore
    sem_post(&truck_sem);
    
    // Generate a random delay for truck departure
    int delay = (rand() % MAX_DELAY) + 1;
    sleep(delay);
    
    // Check if truck is full
    int truck_full = 1;
    for (int i = 0; i < TRUCK_CAPACITY; i++) {
      if (truck_capacity[truck_id] < TRUCK_CAPACITY && conveyor_count[i] > 0) {
        truck_full = 0;
        break;
      }
    }
    if (truck_full) {
      printf("Truck %d is full and ready to depart\n", truck_id);
      break;
    }
  }
}