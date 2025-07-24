//FormAI DATASET v1.0 Category: Physics simulation ; Style: intelligent
#include <stdio.h>

int main() {
   double mass, velocity, time, force, acceleration;
   
   printf("Enter the mass (in kg): ");
   scanf("%lf", &mass);
   
   printf("Enter the velocity (in m/s): ");
   scanf("%lf", &velocity);
   
   printf("Enter the time (in seconds): ");
   scanf("%lf", &time);
   
   force = mass * velocity / time;
   
   acceleration = force / mass;
   
   printf("\nForce = %.2lf N\n", force);
   printf("Acceleration = %.2lf m/s^2\n", acceleration);

   return 0;
}