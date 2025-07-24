//FormAI DATASET v1.0 Category: Data mining ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

int main() {
   int dataset[] = {3, 5, 2, 7, 1, 6, 8, 4};
   int dataset_length = sizeof(dataset)/sizeof(dataset[0]);

   int min = dataset[0];
   int max = dataset[0];
   float mean = 0.0;
   float variance = 0.0;
   float std_deviation = 0.0;

   for(int i=0; i<dataset_length; i++) {
      if(dataset[i] < min) {
         min = dataset[i];
      }
  
      if(dataset[i] > max) {
         max = dataset[i];
      }

      mean += (float)dataset[i]/(float)dataset_length;
   }

   for(int i=0; i<dataset_length; i++) {
      variance += ((float)dataset[i] - mean)*((float)dataset[i] - mean)/(float)dataset_length;
   }

   std_deviation = sqrt(variance);

   printf("Data Mining Report: \n");
   printf("The minimum value in the dataset is %d\n", min);
   printf("The maximum value in the dataset is %d\n", max);
   printf("The mean of the dataset is %.2f\n", mean);
   printf("The variance of the dataset is %.2f\n", variance);
   printf("The standard deviation of the dataset is %.2f\n", std_deviation);

   return 0;
}