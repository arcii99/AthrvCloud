//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  // Initialize traffic variables
  int num_cars = 0;
  int num_motorcycles = 0;
  int num_trucks = 0;
  int num_buses = 0;

  // Set traffic maximums
  int max_cars = 50;
  int max_motorcycles = 20;
  int max_trucks = 10;
  int max_buses = 5;

  // Initialize travel variables
  int distance_traveled = 0;
  int fuel_efficiency = 3; // miles per gallon

  // Initialize random number generator
  srand(time(NULL));

  // Simulate traffic flow
  for (int i = 0; i < 100; i++) {
    // Generate random number to see if new vehicle enters traffic
    int random_number = rand() % 100;

    if (random_number < 10 && num_cars < max_cars) {
      printf("A car enters traffic.\n");
      num_cars++;
    } else if (random_number < 20 && num_motorcycles < max_motorcycles) {
      printf("A motorcycle enters traffic.\n");
      num_motorcycles++;
    } else if (random_number < 25 && num_trucks < max_trucks) {
      printf("A truck enters traffic.\n");
      num_trucks++;
    } else if (random_number < 30 && num_buses < max_buses) {
      printf("A bus enters traffic.\n");
      num_buses++;
    }

    // Simulate travel
    distance_traveled += (num_cars * 10) + (num_motorcycles * 5) + (num_trucks * 20) + (num_buses * 30);
    printf("The vehicles have traveled a total of %d miles.\n", distance_traveled);

    // Simulate fuel consumption
    int fuel_consumed = (num_cars * 5) + (num_motorcycles * 3) + (num_trucks * 10) + (num_buses * 15);
    printf("The vehicles have consumed %d gallons of fuel.\n", fuel_consumed);

    // Simulate accidents
    int accident_chance = rand() % 100;
    if (accident_chance < 5) {
      printf("There has been an accident. Traffic slows to a crawl.\n");
      num_cars /= 2;
      num_motorcycles /= 2;
      num_trucks /= 2;
      num_buses /= 2;
    }

    // Simulate traffic light changes
    int traffic_light = rand() % 2;
    if (traffic_light == 0) {
      printf("The traffic light is red. Vehicles come to a stop.\n");
      num_cars = 0;
      num_motorcycles = 0;
      num_trucks = 0;
      num_buses = 0;
    } else {
      printf("The traffic light is green. Vehicles continue on their way.\n");
    }

    // Check if traffic has stopped completely
    if (num_cars == 0 && num_motorcycles == 0 && num_trucks == 0 && num_buses == 0) {
      printf("All vehicles have come to a stop. Traffic is at a standstill.\n");
      break;
    }
  }

  return 0;
}