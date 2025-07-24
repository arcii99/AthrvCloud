//FormAI DATASET v1.0 Category: Physics simulation ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define GRAVITY 9.81 // acceleration due to gravity
#define TIME_STEP 0.01 // time interval between each calculation
#define TOTAL_TIME 10 // total time of simulation

int main(){
  float mass = 0.05; // mass of the object in kg
  float radius = 0.01; // radius of the object in meters
  float position = 0.2; // initial position of the object in meters
  float velocity = 0; // initial velocity of the object in meters/second
  float time = 0; // time elapsed in the simulation

  while(time <= TOTAL_TIME){
    float acceleration = -(GRAVITY * pow(sin(position/radius),2)); // acceleration is dependent on position
    velocity += acceleration * TIME_STEP; // update velocity
    position += velocity * TIME_STEP; // update position
    printf("Time: %.2f s | Position: %.2f m | Velocity: %.2f m/s\n", time, position, velocity);
    time += TIME_STEP; // update time
  }

  return 0;
}