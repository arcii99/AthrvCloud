//FormAI DATASET v1.0 Category: Physics simulation ; Style: inquisitive
#include <stdio.h>

int main() {
   float mass = 10; // mass of the object in kg
   float velocity = 0; // initial velocity of the object in m/s
   float time = 0; // time elapsed in seconds
   float force = 100; // force applied to the object in newtons
   float acceleration = force / mass; // calculate acceleration using Newton's second law
   
   /* simulate the motion of an object */
   printf("Initial velocity: %.2f m/s\n", velocity);
   while (velocity <= 20) { // limit velocity to 20 m/s for safety reasons
       velocity += acceleration * time; // calculate velocity using the formula v = u + at
       printf("Velocity: %.2f m/s\n", velocity);
       time += 1; // increase time by 1 second
   }
   
   /* calculate the distance traveled by the object */
   float distance = 0.5 * acceleration * (time * time); // calculate distance using the formula s = ut + (1/2)at^2
   printf("Distance traveled: %.2f meters\n", distance);
   
   return 0;
}