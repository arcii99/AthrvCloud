//FormAI DATASET v1.0 Category: Physics simulation ; Style: medieval
#include <stdio.h>
#include <math.h>

int main()
{
   // Initialize variables
   double v = 10.0;  // initial velocity
   double m = 1.0;   // mass of object
   double x = 0.0;   // initial position
   double t = 0.0;   // initial time
   double dt = 0.1;  // time step
   double k = 50.0;  // spring constant
   double a, F, dx;
   
   // Simulate motion
   while (t < 5.0)  // simulate for 5 seconds
   {
       // Calculate spring force
       dx = x - 0.5;  // displacement from equilibrium
       F = -k * dx;   // Hooke's Law: F = -kx
      
       // Calculate acceleration
       a = F / m;
      
       // Update velocity and position
       v += a * dt;
       x += v * dt;
      
       // Print current values
       printf("time: %.2f, position: %.2f, velocity: %.2f\n", t, x, v);
      
       // Increment time
       t += dt;
   }
   
   return 0;
}