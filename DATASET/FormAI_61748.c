//FormAI DATASET v1.0 Category: Physics simulation ; Style: Alan Touring
#include<stdio.h>
#include<math.h>

#define g 9.81 // acceleration due to gravity in m/s^2

int main(){

   float height, time, velocity, distance; // variables to store user input
   float time_of_flight, max_height, impact_velocity; // variables to calculate results
   
   printf("Enter the height of the object (in meters): ");
   scanf("%f", &height);
   
   printf("Enter the time it takes to fall (in seconds): ");
   scanf("%f", &time);
   
   // calculate initial velocity
   velocity = sqrt(2 * g * height);
   printf("The initial velocity is %.2f m/s\n", velocity);
   
   // calculate time of flight
   time_of_flight = 2 * time;
   printf("The time of flight is %.2f seconds\n", time_of_flight);
   
   // calculate maximum height
   max_height = height + (velocity * velocity)/(2 * g);
   printf("The maximum height reached is %.2f meters\n", max_height);
   
   // calculate impact velocity
   impact_velocity = velocity + (g * time);
   printf("The impact velocity is %.2f m/s\n", impact_velocity);
   
   // calculate total distance traveled
   distance = velocity * time + 0.5 * g * time * time;
   printf("The total distance traveled is %.2f meters\n", distance);

   return 0;
}