//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

// define constants
#define MAX_X 100
#define MAX_Y 100
#define MIN_X 0
#define MIN_Y 0
#define MAX_SPEED 10
#define MIN_SPEED 1

// define struct for vehicle
typedef struct {
  int x;
  int y;
  int speed;
  int direction;
} Vehicle;

// define function prototypes
void moveVehicle(Vehicle* vehicle);
void* moveVehicleAsync(void* arg);

// global variable
bool running = true;

int main() {
  // seed the random number generator
  srand(time(NULL));

  // create the vehicle
  Vehicle vehicle = {
    .x = rand() % (MAX_X + 1 - MIN_X) + MIN_X,
    .y = rand() % (MAX_Y + 1 - MIN_Y) + MIN_Y,
    .speed = rand() % (MAX_SPEED + 1 - MIN_SPEED) + MIN_SPEED,
    .direction = rand() % 360
  };

  // print initial position
  printf("Initial position: (%d, %d)\n", vehicle.x, vehicle.y);

  // create thread to move the vehicle asynchronously
  pthread_t thread_id;
  int ret = pthread_create(&thread_id, NULL, moveVehicleAsync, &vehicle);
  if(ret) {
    printf("Error creating thread.\n");
    exit(EXIT_FAILURE);
  }

  // simulate remote control commands
  while(running) {
    int command = rand() % 4;
    switch(command) {
      case 0:
        printf("Move forward.\n");
        vehicle.direction += 0;
        break;
      case 1:
        printf("Move left.\n");
        vehicle.direction += 90;
        break;
      case 2:
        printf("Move backward.\n");
        vehicle.direction += 180;
        break;
      case 3:
        printf("Move right.\n");
        vehicle.direction += 270;
        break;
    }
    // update direction to be within 0-359 degrees
    vehicle.direction = (vehicle.direction + 360) % 360;
    usleep(500000);
  }

  // wait for thread to finish
  pthread_join(thread_id, NULL);

  return 0;
}

void moveVehicle(Vehicle* vehicle) {
  // calculate new position based on current direction
  vehicle->x += (int)(vehicle->speed * cos(vehicle->direction * 3.14159 / 180));
  vehicle->y += (int)(vehicle->speed * sin(vehicle->direction * 3.14159 / 180));
  // make sure vehicle stays within bounds
  if(vehicle->x < MIN_X) {
    vehicle->x = MIN_X;
    vehicle->direction = rand() % 180 + 90;
  }
  if(vehicle->x > MAX_X) {
    vehicle->x = MAX_X;
    vehicle->direction = rand() % 180 - 90;
  }
  if(vehicle->y < MIN_Y) {
    vehicle->y = MIN_Y;
    vehicle->direction = rand() % 180;
  }
  if(vehicle->y > MAX_Y) {
    vehicle->y = MAX_Y;
    vehicle->direction = rand() % 180 + 180;
  }
  // print new position
  printf("New position: (%d, %d)\n", vehicle->x, vehicle->y);
}

void* moveVehicleAsync(void* arg) {
  while(running) {
    moveVehicle(arg);
    usleep(1000000);
  }
  return NULL;
}