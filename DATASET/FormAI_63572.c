//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define traffic flow constants
#define MAX_CARS 20
#define MAX_SPEED 60
#define MIN_SPEED 10
#define CRASH_PROB 5

// Define car struct
typedef struct car {
  int id;
  int speed;
} Car;

// Define function to randomly generate car speeds
int generateSpeed() {
  return rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
}

// Define function to move cars forward
void moveCars(Car carLane[]) {
  int i;
  for (i = 0; i < MAX_CARS; i++) {
    if (carLane[i].id != 0) { // If car exists
      if (rand() % 100 < CRASH_PROB) { // Check if car crashes
        printf("Car %d has crashed!\n", carLane[i].id);
        carLane[i].id = 0; // Remove crashed car from lane
      } else { // If car doesn't crash
        int distance = carLane[i].speed;
        if (rand() % 3 == 0) { // Add an extra random distance
          distance += rand() % 5 + 1;
        }
        if (i + distance < MAX_CARS && carLane[i + distance].id == 0) { // Check if car can move forward
          carLane[i + distance] = carLane[i];
          carLane[i] = (Car) {0}; // Set original spot to empty
        } else { // If car can't move forward
          printf("Car %d is stuck in traffic.\n", carLane[i].id);
        }
      }
    }
  }
}

int main() {
  
  srand(time(NULL)); // Seed random number generator
  
  // Initialize car lane
  Car carLane[MAX_CARS] = {0};
  int i;
  for (i = 0; i < MAX_CARS; i++) {
    int speed = generateSpeed();
    if (speed >= 40) { // Determine if car is a speed demon
      printf("Car %d is a speed demon with a speed of %d.\n", i+1, speed);
    } else {
      printf("Car %d is driving with a speed of %d.\n", i+1, speed);
    }
    carLane[i] = (Car) {i+1, speed};
  }
  
  // Start traffic flow simulation
  int tick = 0;
  printf("Traffic flow simulation starting...\n");
  while (1) {
    printf("Tick %d\n", tick++);
    moveCars(carLane);
    if (carLane[MAX_CARS-1].id != 0) { // Check if last spot in lane is occupied
      printf("Traffic jam in lane! Simulation ending...\n");
      break;
    }
  }
  
  return 0;
}