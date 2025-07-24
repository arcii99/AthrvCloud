//FormAI DATASET v1.0 Category: Scientific ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define ARRAY_SIZE 1000

int main(){

   // Initialize random seed
   srand((unsigned) time(NULL));

   // Generate a random dataset of 1000 values between 0 and 99
   int dataset[ARRAY_SIZE];
   for(int i = 0; i < ARRAY_SIZE; i++){
      dataset[i] = rand() % 100;
   }

   // Calculate the mean of the dataset
   float sum = 0;
   float mean = 0;
   for(int i = 0; i < ARRAY_SIZE; i++){
      sum += dataset[i];
   }
   mean = sum / ARRAY_SIZE;
   printf("Mean: %f\n", mean);

   // Calculate the standard deviation of the dataset
   float variance = 0;
   float deviation = 0;
   for(int i = 0; i < ARRAY_SIZE; i++){
      variance += pow(dataset[i] - mean, 2);
   }
   variance /= ARRAY_SIZE;
   deviation = sqrt(variance);
   printf("Standard Deviation: %f\n", deviation);

   // Calculate the median of the dataset
   int temp = 0;
   for(int i = 0; i < ARRAY_SIZE-1; i++){
      for(int j = 0; j < ARRAY_SIZE-i-1; j++){
         if(dataset[j] > dataset[j+1]){
            temp = dataset[j];
            dataset[j] = dataset[j+1];
            dataset[j+1] = temp;
         }
      }
   }
   float median = 0;
   if(ARRAY_SIZE % 2 == 0){
      median = (dataset[ARRAY_SIZE/2] + dataset[ARRAY_SIZE/2-1]) / 2.0;
   } else{
      median = dataset[ARRAY_SIZE/2];
   }
   printf("Median: %f\n", median);

   // Calculate the mode of the dataset
   int mode = 0;
   int count = 0;
   int max_count = 0;
   for(int i = 0; i < ARRAY_SIZE; i++){
      count = 0;
      for(int j = i; j < ARRAY_SIZE; j++){
         if(dataset[j] == dataset[i]){
            count++;
         }
      }
      if(count > max_count){
         mode = dataset[i];
         max_count = count;
      }
   }
   printf("Mode: %d\n", mode);

   return 0;
}