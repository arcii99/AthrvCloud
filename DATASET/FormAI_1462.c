//FormAI DATASET v1.0 Category: Physics simulation ; Style: shocked
#include <stdio.h>
#include <math.h>

int main() {
  float mass = 10;
  float velocity = 50;
  float acceleration = -9.8;
  float time = 0;
  float delta_time = 0.01;
  float position = 0;
  
  printf("Welcome to the Physics Simulation Program!\n");
  printf("Today we will simulate a ball being thrown into the air and coming back down.\n");
  printf("The ball has a mass of %.2fkg and is being thrown upwards at a velocity of %.2f m/s.\n", mass, velocity);
  printf("The force of gravity will be pulling the ball downwards with an acceleration of %.2f m/s^2.\n", acceleration);
  
  while (position >= 0) {
    //Calculate the new position and velocity
    position = position + velocity * delta_time;
    velocity = velocity + acceleration * delta_time;
    time = time + delta_time;
    
    //Print the current state of the ball
    printf("After %.2f seconds, the ball is %.2fm off the ground with a velocity of %.2f m/s.\n", time, position, velocity);
  }
  
  printf("After %.2f seconds, the ball has hit the ground.\n", time);
  
  return 0;
}