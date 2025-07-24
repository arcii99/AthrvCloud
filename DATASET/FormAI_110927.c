//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 25 // Max length of the road
#define MAX_CARS 10 // Max cars on the road
#define MAX_SPEED 5 // Max speed of the car (in cells/move)
#define MIN_SPEED 1 // Min speed of the car (in cells/move)
#define MAX_TIME 30 // Max time to run the simulation
#define INTERVAL 1 // Time interval between prints

void printRoad(char road[]) {
  printf("+"); // Print the starting point
  for (int i = 0; i < MAX_LENGTH; i++) {
    printf("-"); // Print the road
  }
  printf("+"); // Print the ending point
  printf("\n|"); // Print the starting border
  for (int i = 0; i < MAX_LENGTH; i++) {
    printf("%c", road[i]); // Print the cars on the road
  }
  printf("|"); // Print the ending border
  printf("\n+"); // End of the road
  for (int i = 0; i < MAX_LENGTH; i++) {
    printf("-"); // Print the bottom border
  }
  printf("+\n"); // End of border
}

int main() {
  srand(time(NULL)); // Seed for random number generator
  char road[MAX_LENGTH]; // Road with cars on
  int cars[MAX_CARS]; // Car positions
  int speed[MAX_CARS]; // Car speed
  
  for (int i = 0; i < MAX_LENGTH; i++) {
    road[i] = ' '; // Initialize road to empty
  }

  for (int i = 0; i < MAX_CARS; i++) {
    cars[i] = rand() % MAX_LENGTH; // Randomly place cars on the road
    speed[i] = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED; // Randomly assign each car a speed
    road[cars[i]] = 'X'; // Add the car to the road
  }

  int time = 0; // Start time at 0 seconds

  while (time < MAX_TIME) { // Run simulation for a certain time
    printRoad(road); // Print current road state
    for (int i = 0; i < MAX_CARS; i++) {
      int next = cars[i] + speed[i]; // Calculate the next position of the car
      if (next >= MAX_LENGTH) { // If car reaches end of the road
        road[cars[i]] = ' '; // Remove car from current position
        cars[i] = rand() % MAX_LENGTH; // Place car at a random position on the road
        speed[i] = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED; // Set the car's speed to a new random speed
        road[cars[i]] = 'X'; // Add the car to the road
      } else { // If car can move to next position
        road[cars[i]] = ' '; // Remove car from current position
        cars[i] = next; // Update car position
        road[cars[i]] = 'X'; // Add car to new position
      }
    }
    time += INTERVAL; // Add the interval to the total time elapsed
  }

  return 0;
}