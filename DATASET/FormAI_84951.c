//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10 // Maximum number of floors in the building
#define MAX_ELEVATORS 3 // Maximum number of elevators in the building
#define MAX_USERS 50 // Maximum number of users in the building at any given moment

int floors[MAX_FLOORS];
/* Initialize array to hold current position and direction of each elevator.
   -1 represents stationary, 0 represents going down, and 1 represents going up. */
int elevators[MAX_ELEVATORS][2];

/* Function to randomly generate user requests to call the elevator */
void generate_requests() {
  int num_requests = rand() % (MAX_USERS + 1); // Generate a random number of requests
  for (int i = 0; i < num_requests; i++) {
    int floor = rand() % MAX_FLOORS; // Generate a random floor number
    int direction = (rand() % 2) ? 1 : -1; // Generate a random direction to go (1 for up, -1 for down)
    printf("User on floor %d requests elevator to go %s.\n", floor, (direction == 1) ? "up" : "down");
    // TODO: Add user request to queue
  }
}

/* Function to move the elevators based on user requests */
void move_elevators() {
  for (int i = 0; i < MAX_ELEVATORS; i++) {
    int current_floor = elevators[i][0];
    int direction = elevators[i][1];
    int next_floor = current_floor + direction;
    // If next floor is out of bounds or there are no users waiting on that floor, change direction
    if (next_floor < 0 || next_floor >= MAX_FLOORS || floors[next_floor] == 0) {
      direction *= -1;
      elevators[i][1] = direction; // Update direction in elevators array
      next_floor = current_floor + direction;
    }
    elevators[i][0] = next_floor; // Update current floor in elevators array
    printf("Elevator %d at floor %d going %s.\n", i+1, next_floor, (direction == 1) ? "up" : "down");
    // TODO: Remove users from floors and add them to elevator if they are going in the same direction
  }
}

int main() {
  srand(time(NULL)); // Seed random number generator with current time
  // Initialize floors array to hold number of users waiting on each floor
  for (int i = 0; i < MAX_FLOORS; i++) {
    floors[i] = rand() % (MAX_USERS + 1); // Generate a random number of users waiting on each floor
  }
  // Initialize elevators array to hold current position and direction of each elevator
  for (int i = 0; i < MAX_ELEVATORS; i++) {
    elevators[i][0] = 0; // Start each elevator at ground floor
    elevators[i][1] = -1 + 2 * (i % 2); // Alternate direction of elevators
  }
  int time = 0; // Initialize time counter
  while (1) { // Simulation loop
    printf("Time: %d\n", time);
    generate_requests();
    move_elevators();
    time++;
    // TODO: Check if there are no more users waiting and all elevators are empty, end simulation
  }
  return 0;
}