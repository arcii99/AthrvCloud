//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: accurate
#include <stdio.h>

int main() {
   int n;
   printf("Enter the number of cars to simulate: ");
   scanf("%d", &n);

   int i, timeCounter = 0, totalWaitingTime = 0;
   for(i = 1; i <= n; i++) {
      int arrivalTime, serviceTime;
      printf("Enter arrival time and service time for car %d: ", i);
      scanf("%d %d", &arrivalTime, &serviceTime);

      if(timeCounter < arrivalTime) {
         timeCounter = arrivalTime;
      }

      printf("Car %d arrives at time t = %d\n", i, timeCounter);

      totalWaitingTime += timeCounter - arrivalTime;

      timeCounter += serviceTime;

      printf("Car %d serviced at time t = %d\n", i, timeCounter);
   }

   printf("Average waiting time: %f\n", (float)totalWaitingTime / n);

   return 0;
}