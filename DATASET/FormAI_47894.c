//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_MACHINES 10 // Number of baggage handling machines
#define MAX_BAGS 20 // Maximum number of bags per flight
#define MAX_WAIT_TIME 10 // Maximum wait time for baggage pickup in minutes
#define MAX_ARRIVALS_PER_MINUTE 5 // Maximum number of flights arriving per minute
#define SIMULATION_TIME 60 // Total simulation time in minutes

// Enum to represent the status of a bag
enum BagStatus {
  NOT_ARRIVED,
  ARRIVED,
  PICKED_UP
};

// Struct to represent a bag in the baggage handling system
typedef struct Bag {
  int flight_id;
  int bag_id;
  int arrival_time;
  int pickup_time;
  enum BagStatus status;
} Bag;

// Function to get a random integer between min and max
int getRandomInt(int min, int max) {
  return rand() % (max - min + 1) + min;
}

// Function to create a new bag with given flight id and bag id
Bag createNewBag(int flight_id, int bag_id) {
  Bag bag;
  bag.flight_id = flight_id;
  bag.bag_id = bag_id;
  bag.arrival_time = 0;
  bag.pickup_time = 0;
  bag.status = NOT_ARRIVED;
  return bag;
}

int main() {
  srand(time(0)); // Initialize random number generator
  
  Bag bags[MAX_BAGS]; // Array to store bags in the system
  int num_bags = 0; // Number of bags currently in the system
  
  int num_arrivals = 0; // Total number of flights arrived
  int num_pickups = 0; // Total number of bags picked up
  
  bool machine_available[NUM_MACHINES]; // Array to store availability of machines
  
  int time = 0; // Current time in minutes
  
  // Initialize all machines to be available
  for (int i = 0; i < NUM_MACHINES; i++) {
    machine_available[i] = true;
  }
  
  // Main simulation loop
  while (time < SIMULATION_TIME) {
    // Generate new arrivals for this minute
    int num_new_arrivals = getRandomInt(0, MAX_ARRIVALS_PER_MINUTE);
    for (int i = 0; i < num_new_arrivals; i++) {
      // Generate bags for the new flight
      int num_new_bags = getRandomInt(1, MAX_BAGS);
      for (int j = 0; j < num_new_bags; j++) {
        // Create a new bag and add it to the system
        Bag bag = createNewBag(num_arrivals, num_bags);
        bags[num_bags] = bag;
        num_bags++;
        printf("New bag added for Flight %d: Bag ID = %d\n", num_arrivals, num_bags);
      }
      num_arrivals++;
      printf("New flight arrived: Flight ID = %d\n", num_arrivals);
    }
    
    // Check all bags to see if they are ready for pickup
    for (int i = 0; i < num_bags; i++) {
      if (bags[i].status == ARRIVED && (time - bags[i].pickup_time) > MAX_WAIT_TIME) {
        bags[i].status = PICKED_UP;
        num_pickups++;
        printf("Bag %d for Flight %d picked up after wait time exceeded\n", bags[i].bag_id, bags[i].flight_id);
      }
    }
    
    // Check if any machines are now available
    for (int i = 0; i < NUM_MACHINES; i++) {
      if (!machine_available[i]) {
        // If machine is not available, check if it has finished processing bag
        for (int j = 0; j < num_bags; j++) {
          if (bags[j].status == ARRIVED && bags[j].pickup_time == 0) {
            // Assign the bag to this machine and update availability
            bags[j].pickup_time = time;
            machine_available[i] = true;
            printf("Bag %d for Flight %d picked up by Machine %d\n", bags[j].bag_id, bags[j].flight_id, i+1);
            break;
          }
        }
      }
    }
    
    // Check for free machines and assign them to available bags
    for (int i = 0; i < NUM_MACHINES; i++) {
      if (machine_available[i]) {
        // Check if there are any bags waiting to be processed
        for (int j = 0; j < num_bags; j++) {
          if (bags[j].status == NOT_ARRIVED) {
            // Assign the bag to this machine and update availability and status
            bags[j].arrival_time = time;
            bags[j].status = ARRIVED;
            machine_available[i] = false;
            printf("Bag %d for Flight %d assigned to Machine %d\n", bags[j].bag_id, bags[j].flight_id, i+1);
            break;
          }
        }
      }
    }
    
    // Increment time by 1 minute
    time++;
  }
  
  // End of simulation
  printf("\n\n====================\n");
  printf("Simulation complete!\n");
  printf("Number of flights: %d\n", num_arrivals);
  printf("Number of bags: %d\n", num_bags);
  printf("Number of bags picked up: %d\n", num_pickups);
  
  return 0;
}