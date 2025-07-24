//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int i, j, light, car;
   srand((unsigned)time(NULL));
   
   // initialize the traffic flow array
   int traffic[6][6] = {0};

   // display the traffic flow array
   printf("Initial Traffic Flow\n");
   for (i = 0; i < 6; i++){
      for (j = 0; j < 6; j++){
         printf("%d  ", traffic[i][j]);
      }
      printf("\n");
   }
   printf("\n");

   // simulate the traffic flow for 10 iterations
   for (i = 0; i < 10; i++){
      // determine which way the traffic light is facing
      light = rand() % 4;

      // simulate the cars approaching the intersection
      for (j = 0; j < 6; j++){
         car = rand() % 2;
         traffic[j][light] += car;
      }

      // display the traffic flow array after each iteration
      printf("Iteration %d\n", i+1);
      for (j = 0; j < 6; j++){
         for (int k = 0; k < 6; k++){
            printf("%d  ", traffic[j][k]);
         }
         printf("\n");
      }
      printf("\n");
   }

   return 0;
}