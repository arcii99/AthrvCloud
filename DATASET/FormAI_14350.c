//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main () {
   int i, j, k, n, m, time, delay, comp;
   int weight[20], flight[20], conveyor[20], loaded[20];
   printf("Enter the total number of flights: ");
   scanf("%d", &n);

   printf("Enter the total capacity of conveyor belt: ");
   scanf("%d", &m);

   printf("Enter the delay time for processing a luggage: ");
   scanf("%d", &delay);

   printf("Enter the maximum weight capacity for a luggage: ");
   scanf("%d", &comp);

   printf("Enter the weight and flight number of each luggage: ");
   for (i = 0; i < n; i++) {
      scanf("%d %d", &weight[i], &flight[i]);
      conveyor[i] = 0;
      loaded[i] = 0;
   }
   time = 0;
   while (1) {
      for (i = 0; i < n; i++) {
         if (loaded[i] == 0) {
            if ((conveyor[0] + weight[i]) <= comp) {
               printf("At time t = %d, Flight %d luggage of weight %d kg loaded onto the conveyor belt.\n", time, flight[i], weight[i]);
               conveyor[0] += weight[i];
               weight[i] = 0;
               loaded[i] = 1;
            }
         }
      }
      time += delay;
      for (j = 0; j < (m - 1); j++) {
         conveyor[j] = conveyor[j+1];
      }
      conveyor[m-1] = 0;

      if ((loaded[n-1] == 1) && (conveyor[0] == 0)) {
         break;
      }
   }
   printf("All luggage has been loaded onto the plane.\n");
}