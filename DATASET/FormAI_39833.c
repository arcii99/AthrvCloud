//FormAI DATASET v1.0 Category: Physics simulation ; Style: cheerful
#include<stdio.h>
#include<math.h>

int main()
{
  // Initializing variables
  double time = 0.0, dt = 0.1;
  double mass = 5.0, force = 0.0, acceleration = 0.0, velocity = 0.0, position = 0.0;
  
  // Looping through time steps
  while(time < 10.0)
  {
    // Calculating the force and acceleration
    force = sin(time); // A playful example force calculation
    acceleration = force / mass;
    
    // Updating the velocity and position
    velocity += acceleration * dt;
    position += velocity * dt;
    
    // Printing the results for each time step
    printf("Time: %.2f s | Position: %.2f m | Velocity: %.2f m/s\n", time, position, velocity);
    
    // Increasing the time variable
    time += dt;
  }
  
  return 0;
}