//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_CARS 50

// This struct represents a car on the road
typedef struct {
  int position; // Position of the car on the road
  int speed; // Speed of the car
} car;

int main() {
  srand(time(NULL)); // Initialize random number generator with current time
  car cars[MAX_CARS]; // Array of cars on the road
  int num_cars = 0; // Number of cars on the road
  int time_step = 1; // Time in seconds for each iteration of the simulation
  int road_length = 1000; // Length of the road in meters
  int max_speed_limit = 120; // Maximum speed limit in km/h
  int min_distance_between_cars = 10; // Minimum distance between two cars in meters
  int max_acceleration = 5; // Maximum acceleration in m/s^2
  int max_deceleration = -10; // Maximum deceleration in m/s^2

  // Generate initial set of cars randomly
  for (int i = 0; i < MAX_CARS; i++) {
    if (num_cars == MAX_CARS) {
      break;
    }
    int position = rand() % road_length;
    int speed = rand() % (max_speed_limit + 1);
    cars[i] = (car) {position, speed};
    num_cars++;
  }

  // Run the simulation for 100 time steps
  for (int t = 0; t < 100; t++) {
    // Update each car's position and speed
    for (int i = 0; i < num_cars; i++) {
      car *current_car = &cars[i];
      car *next_car = NULL;
      for (int j = 1; j < num_cars - i; j++) {
        if (cars[i + j].position - current_car->position > min_distance_between_cars) {
          next_car = &cars[i + j];
          break;
        }
      }
      if (next_car == NULL) {
        current_car->speed += max_acceleration * time_step;
      } else {
        int dist_to_next_car = next_car->position - current_car->position;
        int ideal_speed = (dist_to_next_car - min_distance_between_cars) / time_step;
        int speed_diff = ideal_speed - current_car->speed;
        if (speed_diff > max_acceleration * time_step) {
          current_car->speed += max_acceleration * time_step;
        } else if (speed_diff < max_deceleration * time_step) {
          current_car->speed += max_deceleration * time_step;
        } else {
          current_car->speed += speed_diff;
        }
      }
      current_car->position += current_car->speed * time_step;
      if (current_car->position >= road_length) {
        current_car->position = current_car->position - road_length;
      }
    }

    // Print the state of the road
    for (int i = 0; i < road_length; i++) {
      int car_found = 0;
      for (int j = 0; j < num_cars; j++) {
        if (cars[j].position == i) {
          printf("o");
          car_found = 1;
          break;
        }
      }
      if (!car_found) {
        printf("-");
      }
    }
    printf("\n");
  }

  return 0;
}