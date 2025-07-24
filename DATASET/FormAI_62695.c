//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define maximum number of cars allowed on the road
#define MAX_CARS 50

// Define maximum speed limit
#define MAX_SPEED 120

// Define length of the road
#define ROAD_LENGTH 1000

// Define struct for cars on the road
struct Car {
  int position;
  int speed;
};

int main() {
  // Initialize array of cars on the road
  struct Car road[MAX_CARS];

  // Initialize variables for simulation
  int num_cars = 10; // Default: 10 cars
  int sim_time = 60; // Default: 60 seconds
  int car_density = num_cars * 10 / ROAD_LENGTH; // Calculate initial car density
  int total_cars_passed = 0;
  int total_cars_stopped = 0;
  int seconds_elapsed = 0;

  // Seed the random number generator with current time
  srand(time(NULL));

  // Populate cars on the road randomly
  for (int i = 0; i < num_cars; i++) {
    struct Car car;
    car.position = rand() % ROAD_LENGTH;
    car.speed = rand() % MAX_SPEED;
    road[i] = car;
  }

  // Start simulation
  while (seconds_elapsed < sim_time) {
    // Calculate car density on the road
    car_density = num_cars * 10 / ROAD_LENGTH;

    // Print current time and car density on the road
    printf("Time: %d seconds | Car density: %d cars/km\n", seconds_elapsed, car_density);

    // Move each car on the road
    for (int i = 0; i < num_cars; i++) {
      // Calculate the distance to the next car
      int distance_to_next_car = ROAD_LENGTH;
      for (int j = i + 1; j < num_cars; j++) {
        if (road[j].position > road[i].position) {
          distance_to_next_car = road[j].position - road[i].position;
          break;
        }
      }

      // Calculate the new speed of the car
      int new_speed = road[i].speed;
      if (distance_to_next_car <= new_speed) {
        new_speed = distance_to_next_car - 1;
      }
      if (new_speed >= MAX_SPEED) {
        new_speed = MAX_SPEED;
      }

      // Move the car
      road[i].position += new_speed;
      road[i].speed = new_speed;
      total_cars_passed++;

      // Check if the car has passed the end of the road
      if (road[i].position >= ROAD_LENGTH) {
        road[i].position = 0;
        total_cars_passed--;
      }

      // Check if the car has stopped
      if (new_speed == 0) {
        total_cars_stopped++;
      }
    }

    // Print the number of cars stopped
    printf("Number of stopped cars: %d\n", total_cars_stopped);

    // Increment seconds elapsed
    seconds_elapsed++;

    // Reset the number of cars stopped
    total_cars_stopped = 0;
  }

  // Print the total number of cars passed during the simulation
  printf("Total number of cars passed: %d\n", total_cars_passed);

  return 0;
}