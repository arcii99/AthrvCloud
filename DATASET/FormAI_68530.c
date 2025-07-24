//FormAI DATASET v1.0 Category: Physics simulation ; Style: excited
#include <stdio.h>
#include <math.h>

#define PI 3.1415926535

int main()
{
   // Declare initial position and velocity of the ball
   float x = 0.0, y = 0.0, z = 0.0;
   float vx = 10.0, vy = 10.0, vz = 0.0;
   
   // Declare acceleration of the ball due to gravity
   float ax = 0.0, ay = 0.0, az = -9.8;
   
   // Declare time step and simulation time
   float dt = 0.01;
   float t = 0.0;
   
   // Simulation loop
   while (z >= 0.0)
   {
      // Update position of the ball using current velocity
      x += vx*dt;
      y += vy*dt;
      z += vz*dt + 0.5*az*dt*dt;
      
      // Update velocity of the ball using current acceleration
      vx += ax*dt;
      vy += ay*dt;
      vz += az*dt;
      
      // Print current position and time
      printf("t = %f : x = %f y = %f z = %f\n", t, x, y, z);
      
      // Increment time
      t += dt;
   }
   
   // End of simulation
   printf("Simulation complete at time t = %f\n", t);
   
   return 0;
}