//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Function to simulate traffic flow*/
void simulate_traffic_flow(int num_vehicles) {
   int speed, i, time_passed = 0;
   float avg_speed = 0;

   printf("Simulating traffic flow for %d vehicles...\n", num_vehicles);

   /*Randomly generate speeds for each vehicle (between 0-60 mph)*/
   srand(time(NULL));
   for (i = 1; i <= num_vehicles; i++) {
      speed = rand() % 61;
      printf("Vehicle %d: %d mph\n", i, speed);
      avg_speed += speed;
   }

   /*Calculate average speed of all vehicles*/
   avg_speed /= num_vehicles;
   printf("\nAverage speed of all %d vehicles: %.2f mph\n", num_vehicles, avg_speed);

   /*Update time passed for each vehicle (assumes they are all driving at the same speed)*/
   time_passed = 5280 / (avg_speed * 60) * 60; //1 mile = 5280 ft
   printf("\nAssuming all vehicles are driving at an average speed of %.2f mph, it would take %d seconds to travel one mile.\n", avg_speed, time_passed);
}

int main() {
   /*simulate traffic flow for 30 vehicles*/
   simulate_traffic_flow(30);
   
   return 0;
}