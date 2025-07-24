//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: random
#include <stdio.h>

int main() {
   /* declare variables */
   double G = 6.67430e-11; // gravitational constant
   double time = 0; //initialize time
   double dt = 0.001; // time step
   double m1, m2; // mass of the planets
   double r; // distance between planets
   double x1 = 0, y1 = 0; // initialize position of planet 1
   double x2 = 10, y2 = 0; // initialize position of planet 2
   double vx1 = 0, vy1 = 1; // initialize velocity of planet 1
   double vx2 = 0, vy2 = -1; // initialize velocity of planet 2

   /* ask user for input */
   printf("Enter mass of planet 1: ");
   scanf("%lf", &m1);
   printf("Enter mass of planet 2: ");
   scanf("%lf", &m2);

   /* simulate gravity between planets */
   while (time < 10) { // stop at 10 seconds
      r = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); // calculate distance
      double force = G * m1 * m2 / pow(r, 2); // calculate force
      double ax1 = force * (x2 - x1) / (m1 * r); // calculate acceleration of planet 1
      double ay1 = force * (y2 - y1) / (m1 * r); // calculate acceleration of planet 1
      double ax2 = force * (x1 - x2) / (m2 * r); // calculate acceleration of planet 2
      double ay2 = force * (y1 - y2) / (m2 * r); // calculate acceleration of planet 2
      vx1 += ax1 * dt; // update velocity of planet 1
      vy1 += ay1 * dt; // update velocity of planet 1
      vx2 += ax2 * dt; // update velocity of planet 2
      vy2 += ay2 * dt; // update velocity of planet 2
      x1 += vx1 * dt; // update position of planet 1
      y1 += vy1 * dt; // update position of planet 1
      x2 += vx2 * dt; // update position of planet 2
      y2 += vy2 * dt; // update position of planet 2
      time += dt; // increment time
   }

   /* print results */
   printf("Position of planet 1: (%lf, %lf)\n", x1, y1);
   printf("Position of planet 2: (%lf, %lf)\n", x2, y2);

   return 0;
}