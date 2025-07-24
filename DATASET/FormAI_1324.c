//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

/* Decentralized remote control vehicle simulation */

/* define vehicle structure */
typedef struct Vehicle{  
  int speed;  // speed in km/h
  int direction;  // direction in degrees
} Vehicle;

/* define function to accelerate vehicle */
void accelerate(Vehicle *vehicle, int amount){
  vehicle->speed += amount;
}

/* define function to steer vehicle */
void steer(Vehicle *vehicle, int degrees){
  vehicle->direction += degrees;
}

int main(){
  /* initialize vehicle */
  Vehicle myVehicle = {0, 0};

  /* test functionality */
  accelerate(&myVehicle, 50);
  steer(&myVehicle, 90);
  accelerate(&myVehicle, 20);

  /* print vehicle status */
  printf("Current Speed: %d km/h\n", myVehicle.speed);
  printf("Current Direction: %d degrees\n", myVehicle.direction);

  return 0;
}