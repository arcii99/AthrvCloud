//FormAI DATASET v1.0 Category: Physics simulation ; Style: mind-bending
#include <stdio.h>
#include <math.h>

int main() {
  float time = 0;
  float dt = 0.01;
  float mass = 1;
  float position = 0;
  float velocity = 10;
  float acceleration = 0;

  printf("Starting simulation...\n");

  while (time < 10) {
    // update position
    position += velocity*dt + 0.5*acceleration*dt*dt;

    // update velocity
    velocity += acceleration*dt;

    // update acceleration
    acceleration = -sin(position)/mass;

    // print results
    printf("t = %f, x = %f, v = %f, a = %f\n", time, position, velocity, acceleration);

    // increment time
    time += dt;
  }

  printf("Simulation complete.\n");
  return 0;
}