//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of lanes and the max number of cars that can fit in each lane
#define NUM_LANES 4
#define MAX_CARS_PER_LANE 10

// Define constants for the simulation
#define SIMULATION_TIME 60 // in minutes
#define CAR_GEN_INTERVAL 3 // in seconds
#define MIN_CAR_SPEED 40 // in kmph
#define MAX_CAR_SPEED 120 // in kmph

// Define a struct for a car
typedef struct {
  int speed;
  int position; // position within the lane (in meters)
  int lane; // 0-indexed lane number
} Car;

// Define a struct for a lane
typedef struct {
  Car cars[MAX_CARS_PER_LANE];
  int num_cars;
} Lane;

// Define a struct for the traffic simulation
typedef struct {
  Lane lanes[NUM_LANES];
  int time; // elapsed time (in seconds)
} Simulation;

// Function to generate a random number between min and max (inclusive)
int rand_range(int min, int max) {
  return min + rand() % (max - min + 1);
}

// Function to update the position of a car based on its speed
void update_car_position(Car *car, int time_elapsed) {
  car->position += (car->speed * time_elapsed) / 3600; // convert kmph to m/s
}

// Function to generate a new car and add it to the specified lane
void generate_car(Lane *lane) {
  if (lane->num_cars < MAX_CARS_PER_LANE) {
    Car car;
    car.speed = rand_range(MIN_CAR_SPEED, MAX_CAR_SPEED);
    car.position = 0;
    car.lane = 0;
    lane->cars[lane->num_cars++] = car;
  }
}

// Function to print the current state of the simulation
void print_simulation(Simulation *sim) {
  printf("Time: %d\n", sim->time);
  printf("|");
  for (int i = 0; i < NUM_LANES; i++) {
    for (int j = 0; j < MAX_CARS_PER_LANE; j++) {
      if (j < sim->lanes[i].num_cars) {
        printf("X");
      } else {
        printf(" ");
      }
    }
    printf("|");
  }
  printf("\n\n");
}

int main() {
  // Initialize the RNG with the current time as the seed
  srand(time(NULL));

  // Initialize a new simulation
  Simulation sim;
  sim.time = 0;
  for (int i = 0; i < NUM_LANES; i++) {
    sim.lanes[i].num_cars = 0;
  }

  // Loop until the simulation time has elapsed
  while (sim.time < SIMULATION_TIME * 60) {
    // Generate a new car in a random lane every CAR_GEN_INTERVAL seconds
    if (sim.time % CAR_GEN_INTERVAL == 0) {
      generate_car(&sim.lanes[rand() % NUM_LANES]);
    }

    // Update the position of each car in each lane
    for (int i = 0; i < NUM_LANES; i++) {
      for (int j = 0; j < sim.lanes[i].num_cars; j++) {
        update_car_position(&sim.lanes[i].cars[j], CAR_GEN_INTERVAL);
      }
    }

    // Print the current state of the simulation
    print_simulation(&sim);

    // Increment the elapsed time
    sim.time += CAR_GEN_INTERVAL;
  }

  return 0;
}