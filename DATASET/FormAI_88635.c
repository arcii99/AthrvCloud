//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 20 
#define MAX_CAR_SPEED 5 
#define TICKS_PER_SECOND 5 
#define TICK_LENGTH 1000000 

typedef struct {
  int distance_from_top;
  int distance_from_left;
  int speed;
  int is_active;
} Car;

// Function prototypes
void initialize_road(char road[ROAD_LENGTH][2]);
void add_car_to_road(char road[ROAD_LENGTH][2], Car *car);
void remove_car_from_road(char road[ROAD_LENGTH][2], Car *car);
int update_car_location(char road[ROAD_LENGTH][2], Car *car);
void print_road(char road[ROAD_LENGTH][2]);

int main() {
  char road[ROAD_LENGTH][2];  // 2 lanes of 20 units each
  Car cars[ROAD_LENGTH/2];    // Up to 1 car per lane
  int num_cars = 0;

  // Use the current time as the random seed for car creation
  srand(time(NULL));

  // Initialize the road
  initialize_road(road);

  // Main simulation loop
  while (1) {
    // Add a car to the road with a small probability
    if (num_cars < ROAD_LENGTH/2 && (rand() % 10) == 0) {
      Car new_car = {0, 0, 1, 1};
      add_car_to_road(road, &new_car);
      cars[num_cars] = new_car;
      num_cars++;
      printf("Car added!\n");
    }

    // Update the position of each active car on the road
    for (int i = 0; i < num_cars; i++) {
      int new_distance = update_car_location(road, &cars[i]);

      if (new_distance == -1) {
        // Car has reached end of the road
        printf("Car removed!\n");
        remove_car_from_road(road, &cars[i]);
        i--;
        num_cars--;
      }
    }

    // Print the current state of the road
    print_road(road);

    // Pause for a short time before the next tick
    usleep(TICK_LENGTH);
  }

  return 0;
}

void initialize_road(char road[ROAD_LENGTH][2]) {
  // Clear the road
  for (int i = 0; i < ROAD_LENGTH; i++) {
    for (int j = 0; j < 2; j++) {
      road[i][j] = ' ';
    }
  }

  // Add starting markers to both lanes
  road[0][0] = '|';
  road[0][1] = '|';
}

void add_car_to_road(char road[ROAD_LENGTH][2], Car *car) {
  // Find an empty starting location
  int lane = rand() % 2;
  int distance = 1;
  while (road[distance][lane] != ' ') {
    distance++;
  }

  // Add the car to the road
  road[distance][lane] = 'o';
  car->distance_from_top = distance;
  car->distance_from_left = lane;
}

void remove_car_from_road(char road[ROAD_LENGTH][2], Car *car) {
  // Remove the car from the road
  road[car->distance_from_top][car->distance_from_left] = ' ';
  car->is_active = 0;
}

int update_car_location(char road[ROAD_LENGTH][2], Car *car) {
  if (!car->is_active) {
    // Car is inactive and should not be updated
    return -1;
  }

  int current_distance = car->distance_from_top;
  int current_lane = car->distance_from_left;
  int current_speed = car->speed;

  // Choose a new speed (between 0 and MAX_CAR_SPEED)
  int new_speed = (rand() % (MAX_CAR_SPEED + 1));

  // Calculate the new distance (distance = speed * ticks)
  int new_distance = current_distance + new_speed;

  // Check for collisions with other cars
  if (new_distance < ROAD_LENGTH) {
    for (int i = 0; i < ROAD_LENGTH/2; i++) {
      if (road[new_distance][i] != ' ') {
        // Crash!
        printf("Crash! Car removed!\n");
        remove_car_from_road(road, car);
        return -1;
      }
    }
  }

  // Update the car's position on the road
  road[current_distance][current_lane] = ' ';
  road[new_distance][current_lane] = 'o';
  car->distance_from_top = new_distance;
  car->speed = new_speed;

  // Return -1 if the car has reached the end of the road
  if (new_distance == ROAD_LENGTH - 1) {
    return -1;
  } else {
    return new_distance;
  }
}

void print_road(char road[ROAD_LENGTH][2]) {
  // Clear the screen
  system("clear");

  // Print the road
  for (int i = 0; i < ROAD_LENGTH; i++) {
    printf("%c %c\n", road[i][0], road[i][1]);
  }
}