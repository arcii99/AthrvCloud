//FormAI DATASET v1.0 Category: Physics simulation ; Style: synchronous
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main() {
   double mass = 10; // mass in kg
   double springConstant = 2.0; // spring constant in N/m
   double initialPosition = 1.0; // initial position in m
   double initialVelocity = 0.0; // initial velocity in m/s
   double timeStep = 0.1; // time step in s
   double time = 0.0; // initial time in s
   double acceleration = -springConstant * initialPosition / mass; // initial acceleration in m/s^2
   double velocity = initialVelocity; // initial velocity in m/s
   double position = initialPosition; // initial position in m

   printf("Time\tPosition\tVelocity\tAcceleration\n");

   while (time <= 10.0) { // simulate for 10 seconds
      printf("%.2f\t%.2f\t%.2f\t%.2f\n", time, position, velocity, acceleration);

      // calculate new position, velocity, and acceleration
      double newPosition = position + velocity * timeStep + 0.5 * acceleration * timeStep * timeStep;
      double newVelocity = velocity + acceleration * timeStep;
      double newAcceleration = -springConstant * newPosition / mass;

      // update variables for next iteration
      time += timeStep;
      position = newPosition;
      velocity = newVelocity;
      acceleration = newAcceleration;
   }

   return 0;
}