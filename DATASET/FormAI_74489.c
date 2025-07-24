//FormAI DATASET v1.0 Category: Physics simulation ; Style: complex
#include <stdio.h>
#include <math.h>
#define PI 3.14159265359

int main() {
   int step, n;
   double G, m, M, d, r, a, V, T;
   
   printf("Enter number of steps: ");
   scanf("%d", &step);
   
   printf("Enter mass of the smaller object (kg): ");
   scanf("%lf", &m);
   
   printf("Enter mass of the larger object (kg): ");
   scanf("%lf", &M);
   
   printf("Enter distance between the objects (m): ");
   scanf("%lf", &d);
   
   r = d/2.0;
   G = 6.67 * pow(10,-11);
   
   a = G * M / pow(r,2);
   V = sqrt(G * M / r);
   T = (2 * PI * r) / V;
   
   printf("Acceleration of smaller object: %lf m/s^2\n", a);
   printf("Velocity of smaller object: %lf m/s\n", V);
   printf("Orbital period: %.2lf seconds\n\n", T);
   
   for(n = 1; n <= step; ++n) {
      double x, y, vx, vy, ax, ay, Fx, Fy, F;
      
      printf("Step %2d:  ", n);
      printf("Position (m): (%12lf,%12lf)  ", x, y);
      printf("Velocity (m/s): (%12lf,%12lf)  ", vx, vy);
      printf("Force (N): (%12lf,%12lf)  ", Fx, Fy);
      printf("Acceleration (m/s^2): (%12lf,%12lf)\n", ax, ay);
      
      F = G * m * M / pow(r, 2);
      Fx = F * cos(PI);
      Fy = F * sin(PI);
      
      ax = Fx / m;
      ay = Fy / m;
      
      vx += ax * 1.0;
      vy += ay * 1.0;
      
      x += vx * 1.0;
      y += vy * 1.0;
   }
   
   return 0;
}