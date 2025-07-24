//FormAI DATASET v1.0 Category: Physics simulation ; Style: curious
#include <stdio.h>
#include <math.h>

int main() {
  int time, position, velocity, acceleration;
  double force, mass;
  
  printf("Welcome to the Physics Simulation Program!\n");

  printf("Please enter the mass of the object in kg: ");
  scanf("%lf", &mass);

  printf("Please enter the initial velocity of the object in m/s: ");
  scanf("%d", &velocity);

  printf("Please enter the initial position of the object in meters: ");
  scanf("%d", &position);

  printf("Please enter the force acting on the object in Newtons: ");
  scanf("%lf", &force);

  acceleration = force / mass;

  printf("The acceleration of the object is %d m/s^2.\n", acceleration);

  printf("How long would you like to run the simulation for (in seconds)? ");
  scanf("%d", &time);

  int i;
  for(i = 0; i <= time; i++) {
    position = position + velocity * i + 0.5 * acceleration * pow(i, 2);
    velocity = velocity + acceleration * i;
    printf("Time: %d sec | Position: %d m | Velocity: %d m/s | Acceleration: %d m/s^2\n", i, position, velocity, acceleration);
  }

  printf("Simulation complete! Thank you for using the Physics Simulation Program.\n");

  return 0;
}