//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: dynamic
#include <stdio.h>
#include <stdbool.h>

#define MAX_SPEED 100
#define MIN_SPEED 0
#define MAX_TURN_ANGLE 90
#define MIN_TURN_ANGLE -90

struct RemoteControlVehicle {
  int speed;
  int angle;
  bool isMovingForward;
};

void increaseSpeed(struct RemoteControlVehicle *vehicle) {
  vehicle->speed += 10;
  if (vehicle->speed > MAX_SPEED) {
    vehicle->speed = MAX_SPEED;
  }
}

void decreaseSpeed(struct RemoteControlVehicle *vehicle) {
  vehicle->speed -= 10;
  if (vehicle->speed < MIN_SPEED) {
    vehicle->speed = MIN_SPEED;
  }
}

void turnLeft(struct RemoteControlVehicle *vehicle, int angle) {
  vehicle->angle -= angle;
  if (vehicle->angle < MIN_TURN_ANGLE) {
    vehicle->angle = MIN_TURN_ANGLE;
  }
}

void turnRight(struct RemoteControlVehicle *vehicle, int angle) {
  vehicle->angle += angle;
  if (vehicle->angle > MAX_TURN_ANGLE) {
    vehicle->angle = MAX_TURN_ANGLE;
  }
}

void switchDirection(struct RemoteControlVehicle *vehicle) {
  vehicle->isMovingForward = !vehicle->isMovingForward;
}

void printVehicleState(struct RemoteControlVehicle vehicle) {
  printf("Speed: %d\n", vehicle.speed);
  printf("Angle: %d\n", vehicle.angle);
  printf("Direction: %s\n", vehicle.isMovingForward ? "Forward" : "Backward");
}

int main() {
  struct RemoteControlVehicle vehicle = {0, 0, true};
  printf("Starting vehicle simulation\n");
  printf("---------------------------\n");
  printf("Initial state:\n");
  printVehicleState(vehicle);
  
  printf("Accelerating...\n");
  increaseSpeed(&vehicle);
  printVehicleState(vehicle);
  
  printf("Turning left...\n");
  turnLeft(&vehicle, 45);
  printVehicleState(vehicle);
  
  printf("Slowing down...\n");
  decreaseSpeed(&vehicle);
  printVehicleState(vehicle);
  
  printf("Turning right...\n");
  turnRight(&vehicle, 180);
  printVehicleState(vehicle);
  
  printf("Switching direction...\n");
  switchDirection(&vehicle);
  printVehicleState(vehicle);
  
  printf("Stopping vehicle simulation\n");
  return 0;
}