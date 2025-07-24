//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: active
#include <stdio.h>

int main() {
   int numWells, i, j;
   float x[100], y[100], depth[100], volume[100], ans = 0.0;

   printf("Enter the number of wells: ");
   scanf("%d", &numWells);

   printf("\nEnter the x, y, depth, and volume for each well:\n");
   for (i = 0; i < numWells; i++) {
      scanf("%f %f %f %f", &x[i], &y[i], &depth[i], &volume[i]);
   }

   for (i = 0; i < numWells; i++) {
      float dist, minDist = 10000.0;
      int minIndex;
      for (j = 0; j < numWells; j++) {
         if (i != j) {
            dist = (x[j]-x[i])*(x[j]-x[i]) + (y[j]-y[i])*(y[j]-y[i]);
            if (dist < minDist) {
               minDist = dist;
               minIndex = j;
            }
         }
      }
      ans += volume[minIndex]/(depth[minIndex]-depth[i]);
   }

   printf("\nThe maximum oil production is: %f\n", ans);

   return 0;
}