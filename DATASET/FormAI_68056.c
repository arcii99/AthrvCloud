//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: portable
#include <stdio.h>

int main() {
   int car_count = 0;
   int truck_count = 0;
   int bus_count = 0;
   int num_minutes = 0;
   int i = 0;

   // Prompt user for simulation duration
   printf("Enter the number of minutes for the traffic flow simulation: ");
   scanf("%d", &num_minutes);

   for (i = 1; i <= num_minutes; i++) {
      // Generate a random number
      int rand_num = rand() % 3;

      // Determine vehicle type based on the random number
      if (rand_num == 0) {
         printf("Car entered at minute %d.\n", i);
         car_count++;
      } else if (rand_num == 1) {
         printf("Truck entered at minute %d.\n", i);
         truck_count++;
      } else {
         printf("Bus entered at minute %d.\n", i);
         bus_count++;
      }
   }

   // Display simulation results
   printf("\nSimulation complete.\n");
   printf("%d cars entered the traffic flow.\n", car_count);
   printf("%d trucks entered the traffic flow.\n", truck_count);
   printf("%d buses entered the traffic flow.\n", bus_count);

   return 0;
}