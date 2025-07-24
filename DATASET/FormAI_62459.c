//FormAI DATASET v1.0 Category: Data mining ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

int main() {

   // Create dataset
   int dataset[10][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}, {11, 12}, {13, 14}, {15, 16}, {17, 18}, {19, 20}};
   
   // Initialize variables
   float sum_x = 0, sum_y = 0, sum_x2 = 0, sum_xy = 0;
   float mean_x, mean_y;
   float b, a;

   // Calculate sums
   for(int i = 0; i < 10; i++) {
       sum_x += dataset[i][0];
       sum_y += dataset[i][1];
       sum_x2 += dataset[i][0] * dataset[i][0];
       sum_xy += dataset[i][0] * dataset[i][1];
   }

   // Calculate means
   mean_x = sum_x / 10;
   mean_y = sum_y / 10;

   // Calculate slope and intercept
   b = (sum_xy - 10 * mean_x * mean_y) / (sum_x2 - 10 * mean_x * mean_x);
   a = mean_y - b * mean_x;

   // Output results
   printf("Slope (b) = %f\n", b);
   printf("Intercept (a) = %f\n", a);

   return 0;
}