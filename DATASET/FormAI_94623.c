//FormAI DATASET v1.0 Category: Physics simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int main()
{
   /* Physics simulation: Pendulum */

   /* Variables */
   double g = 9.81;   // Gravitational acceleration
   double L = 2.00;   // Length of the pendulum
   double theta0 = 0.50;  // Initial angle
   double theta = theta0;  // Current angle
   double omega = 0.00;  // Angular velocity
   double t = 0.00;   // Time
   double dt = 0.01;  // Time step

   /* Simulation */
   while (t < 10.00) {
      // Calculate the angular acceleration
      double alpha = -(g / L) * sin(theta);

      // Update the angular velocity and angle
      omega += alpha * dt;
      theta += omega * dt;

      // Print the current time and angle
      printf("%.2f %.2f\n", t, theta);

      // Increment the time
      t += dt;
   }

   return 0;
}