//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL)); // Initialize random number generator
   
   int current_latitude, current_longitude;
   printf("Enter your current latitude: ");
   scanf("%d", &current_latitude);
   printf("Enter your current longitude: ");
   scanf("%d", &current_longitude);
   
   int destination_latitude, destination_longitude;
   printf("Enter your destination latitude: ");
   scanf("%d", &destination_latitude);
   printf("Enter your destination longitude: ");
   scanf("%d", &destination_longitude);
   
   double distance = sqrt(pow(destination_latitude - current_latitude, 2) + pow(destination_longitude - current_longitude, 2));
   printf("The distance between your current location and your destination is: %lf kilometers\n", distance);
   
   // Simulate GPS navigation
   int steps = distance * 1000;
   int current_step_latitude = current_latitude;
   int current_step_longitude = current_longitude;
   int i;
   for (i = 0; i < steps; i++) {
      int next_step_latitude = current_step_latitude + rand() % 3 - 1; // Simulate GPS inaccuracies
      int next_step_longitude = current_step_longitude + rand() % 3 - 1;
      printf("Current Location: (%d,%d) | Next Location: (%d,%d)\n", current_step_latitude, current_step_longitude, next_step_latitude, next_step_longitude);
      current_step_latitude = next_step_latitude;
      current_step_longitude = next_step_longitude;
   }
   
   printf("You have reached your destination!\n");
   
   return 0;
}