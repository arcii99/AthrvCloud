//FormAI DATASET v1.0 Category: Data mining ; Style: Ada Lovelace
/* Ada Lovelace style Data Mining Example in C */
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

/* Function to find the maximum element in an array */
int max(int arr[]) {
   int maximum = arr[0];
   for (int i = 1; i < SIZE; i++) {
      if (arr[i] > maximum) {
         maximum = arr[i];
      }
   }
   return maximum;
}

/* Function to find the minimum element in an array */
int min(int arr[]) {
   int minimum = arr[0];
   for (int i = 1; i < SIZE; i++) {
      if (arr[i] < minimum) {
         minimum = arr[i];
      }
   }
   return minimum;
}

/* Function to calculate the mean of an array */
float mean(int arr[]) {
   int sum = 0;
   for (int i = 0; i < SIZE; i++) {
      sum += arr[i];
   }
   float meanValue = (float) sum / (float) SIZE;
   return meanValue;
}

/* Function to calculate the standard deviation of an array */
float standardDeviation(int arr[]) {
   float sum = 0, sd = 0;
   float meanValue = mean(arr);
   for (int i = 0; i < SIZE; i++) {
      sum += pow(arr[i] - meanValue, 2);
   }
   sd = sqrt(sum / (float) SIZE); 
   return sd;
}

int main() {
   int data[SIZE] = {5, 7, 3, 1, 9, 2, 4, 6, 8, 0};
   printf("Data Mining Example Program in C by Ada Lovelace\n\n");
   printf("The data set is: ");
   for (int i = 0; i < SIZE; i++) {
      printf("%d ", data[i]);
   }
   printf("\n\n");
   int maximumElement = max(data);
   printf("Maximum Element = %d\n", maximumElement);
   int minimumElement = min(data);
   printf("Minimum Element = %d\n", minimumElement);
   float meanValue = mean(data);
   printf("Mean Value = %f\n", meanValue);
   float standardDeviationValue = standardDeviation(data);
   printf("Standard Deviation = %f\n", standardDeviationValue);
   return 0;
}