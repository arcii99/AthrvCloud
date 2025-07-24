//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int road[10]; // Initialize an array of length 10 to represent the road where 0 is no car and 1 is a car
  int cars_on_road = 0; // Initialize variable to hold the number of cars currently on the road
  int total_cars = 0; // Initialize variable to hold the total number of cars that have passed through the simulation
  srand(time(NULL)); // Initialize random number generator

  // Loop through the simulation 100 times
  for (int i = 0; i < 100; i++) {
    int rand_num = rand() % 10; // Generate a random number between 0-9

    // If the random number is less than or equal to the number of cars on the road, remove a car
    if (rand_num <= cars_on_road) {
      road[cars_on_road - 1] = 0; // Remove the car from the road
      cars_on_road--; // Decrement cars_on_road count
    }
    // If the random number is greater than the number of cars on the road, add a car
    else {
      road[cars_on_road] = 1; // Add car to the road
      cars_on_road++; // Increment cars_on_road count
      total_cars++; // Increment total_cars count
    }

    printf("Time: %d - Cars on Road: %d - Total Cars: %d\n", i+1, cars_on_road, total_cars);
  }

  return 0;
}