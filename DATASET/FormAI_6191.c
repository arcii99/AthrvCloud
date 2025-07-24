//FormAI DATASET v1.0 Category: Temperature monitor ; Style: active
#include <stdio.h>

int main() {
   float temp[5], average = 0;
   int i;

   printf("Enter the temperature of five days:\n");

   for (i = 0; i < 5; i++) {
      scanf("%f", &temp[i]);
   }

   for (i = 0; i < 5; i++) {
      average += temp[i];
   }

   average /= 5;

   printf("\nThe average temperature is: %.2f\n\n", average);

   for (i = 0; i < 5; i++) {
       if (temp[i] > average) {
           printf("%.2f is above average.\n", temp[i]);
       } 
       else if (temp[i] == average) {
           printf("%.2f is on average.\n", temp[i]);
       }
       else {
           printf("%.2f is below average.\n", temp[i]);
       }
   }

   return 0;
}