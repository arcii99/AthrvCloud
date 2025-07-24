//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <math.h>

int main() {
   int i, j;
   double G = 6.67259e-11;
   double dt = 0.01;
   double m1 = 2.0e30; // Mass of first planet (Romeo)
   double m2 = 2.0e30; // Mass of second planet (Juliet)
   double r, ax, ay, vx, vy, x, y;

   // Initial positions and velocities
   double x1 = 0.0, y1 = 0.0, vx1 = 0.0, vy1 = 0.0;
   double x2 = 4.5e12, y2 = 0.0, vx2 = 0.0, vy2 = 20000.0;

   for (i = 0; i < 100000; i++) {
      r = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
      ax = G*m2*(x2-x1)/(r*r*r);
      ay = G*m2*(y2-y1)/(r*r*r);
      vx1 += ax*dt;
      vy1 += ay*dt;
      vx2 -= ax*dt;
      vy2 -= ay*dt;
      x1 += vx1*dt;
      y1 += vy1*dt;
      x2 += vx2*dt;
      y2 += vy2*dt;

      if (i % 1000 == 0) {
         printf("%lf %lf %lf %lf %lf %lf\n", x1, y1, x2, y2, vx1, vy1, vx2, vy2);
      }
   }

   return 0;
}