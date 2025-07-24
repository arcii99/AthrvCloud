//FormAI DATASET v1.0 Category: Physics simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <math.h>

int main() {
   float v0, theta;
   const float g = 9.8;
   
   printf("Enter initial velocity (m/s): ");
   scanf("%f", &v0);
   
   printf("Enter angle of launch (degrees): ");
   scanf("%f", &theta);
   
   // convert angle from degrees to radians
   theta = theta * M_PI / 180.0;
   
   // calculate maximum height and range of projectile
   float hmax = pow(v0, 2) * pow(sin(theta), 2) / (2 * g);
   float r = pow(v0, 2) * sin(2 * theta) / g;
   
   printf("Maximum height: %f meters\n", hmax);
   printf("Range of projectile: %f meters\n", r);
   
   // simulate projectile motion
   float x = 0.0, y = 0.0;
   float t = 0.0, dt = 0.01;
   float vx = v0 * cos(theta);
   float vy = v0 * sin(theta);
   
   printf("Simulating projectile motion...\n");
   printf("Time (s)\tX position (m)\tY position (m)\n");
   printf("------------------------------------------------\n");
   
   while (y >= 0) {
      printf("%f\t\t%f\t\t%f\n", t, x, y);
      x = vx * t;
      y = vy * t - 0.5 * g * pow(t, 2);
      t += dt;
   }
   
   printf("Projectile has landed.\n");
   
   return 0;
}