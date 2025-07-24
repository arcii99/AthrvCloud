//FormAI DATASET v1.0 Category: Physics simulation ; Style: all-encompassing
#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main() {
   double timestep = 0.001;
   double time = 0.0;
   
   double m1 = 1.0;
   double m2 = 2.0;
   double r = 1.0;
   
   double G = 6.67408e-11;
   
   double x1 = 0.0;
   double y1 = 0.0;
   double vx1 = 0.0;
   double vy1 = 0.0;
   
   double x2 = r;
   double y2 = 0.0;
   double vx2 = 0.0;
   double vy2 = sqrt(G * m1 / r);
   
   double ax1, ay1, ax2, ay2;
   
   while (time < 10.0) {
      double dx = x2 - x1;
      double dy = y2 - y1;
      
      double dist = sqrt(dx * dx + dy * dy);
      double force = G * m1 * m2 / (dist * dist);
      
      double fx = force * dx / dist;
      double fy = force * dy / dist;
      
      ax1 = fx / m1;
      ay1 = fy / m1;
      
      ax2 = -fx / m2;
      ay2 = -fy / m2;
      
      x1 += vx1 * timestep;
      y1 += vy1 * timestep;
      vx1 += ax1 * timestep;
      vy1 += ay1 * timestep;
      
      x2 += vx2 * timestep;
      y2 += vy2 * timestep;
      vx2 += ax2 * timestep;
      vy2 += ay2 * timestep;
      
      time += timestep;
      
      printf("Time: %.3f, Distance: %.3f\n", time, dist);
   }
   
   return 0;
}