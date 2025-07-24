//FormAI DATASET v1.0 Category: Data mining ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {
   int grades[5] = {90, 85, 70, 92, 88}; //data

   printf("The grades are: ");
   for(int i = 0; i < 5; i++) {
      printf("%d ", grades[i]);
   }

   int min = grades[0]; //initialize the min value to the first value
   int max = grades[0]; //initialize the max value to the first value
   float sum = 0; //to calculate the average
   for(int i = 0; i < 5; i++) {
      if(grades[i] < min) {
         min = grades[i]; //update the min value if a smaller value is found
      }
      if(grades[i] > max) {
         max = grades[i]; //update the max value if a larger value is found
      }
      sum += grades[i]; //add each grade to the sum to calculate the average
   }

   float avg = sum/5.0; //calculate the average
   printf("\nThe highest grade is: %d", max);
   printf("\nThe lowest grade is: %d", min);
   printf("\nThe average grade is: %.2f", avg);

   return 0;
}