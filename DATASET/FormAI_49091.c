//FormAI DATASET v1.0 Category: Physics simulation ; Style: energetic
#include<stdio.h>
#include<math.h>

int main()
{
   float r,vel,time,energy;
   printf("\nEnter the radius of the circular path (in meters): ");
   scanf("%f",&r);
   printf("\nEnter the velocity of the particle (in meters per second): ");
   scanf("%f",&vel);
   printf("\nEnter the time taken by the particle to complete one revolution (in seconds): ");
   scanf("%f",&time);

   float mass = 1; //mass of the particle
   float g = 9.81; //acceleration due to gravity

   energy = 0.5 * mass * pow(vel,2) + mass * g * r; //calculating the energy of the particle

   float angular_vel = (2 * M_PI)/time; //calculating the angular velocity of the particle

   printf("\nAngular velocity: %.2f rad/s\n",angular_vel);

   float centripetal_acc = pow(vel,2)/r; //calculating the centripetal acceleration of the particle

   printf("\nCentripetal acceleration: %.2f m/s^2\n",centripetal_acc);

   float force = mass * centripetal_acc; //calculating the force on the particle

   printf("\nForce acting on the particle: %.2f N\n",force);

   float magnetic_field = 1.2; //magnetic field in tesla
   float charge = 1.6 * pow(10,-19); //charge of the particle in coulombs

   float magnetic_force = charge * vel * magnetic_field; //calculating the magnetic force on the particle

   printf("\nMagnetic force acting on the particle: %.2e N\n",magnetic_force);
   
   return 0;
}