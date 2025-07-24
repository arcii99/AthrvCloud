//FormAI DATASET v1.0 Category: Physics simulation ; Style: scalable
#include <stdio.h>
#include <math.h>

#define GRAVITY 9.8 // acceleration due to gravity in m/s^2

struct Object {
  double mass; // mass of the object in kg
  double x; // horizontal position in m
  double y; // vertical position in m
  double vx; // horizontal velocity in m/s
  double vy; // vertical velocity in m/s
};

void simulate(struct Object* obj, double time_step, double duration) {
  double t = 0; // initial time
  while (t < duration) {
    // update the position and velocity of the object
    obj->x += obj->vx * time_step;
    obj->y += obj->vy * time_step;
    obj->vy -= GRAVITY * time_step;
    
    // check for collisions with the ground
    if (obj->y < 0) {
      // bounce the object off the ground
      obj->y = -obj->y;
      obj->vy = -obj->vy;
    }
    
    // print the position of the object
    printf("t=%.2f x=%.2f y=%.2f\n", t, obj->x, obj->y);
    
    // update the time
    t += time_step;
  }
}

int main() {
  // create a new object
  struct Object obj = {1, 0, 10, 5, 0};
  
  // simulate the object for 5 seconds with a time step of 0.1 seconds
  simulate(&obj, 0.1, 5);
  
  return 0;
}