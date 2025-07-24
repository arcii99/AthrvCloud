//FormAI DATASET v1.0 Category: Data mining ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int data[100];            // Declare an array to store the data
   int num = 0;
   srand(time(NULL));        // Seed random number generator with current time
   
   // Generate 100 random integers between 1 and 1000 and store them in the array
   for (int i = 0; i < 100; i++) {
      data[i] = rand() % 1000 + 1;
   }
   
   // Print out the original data
   printf("Original data: ");
   for (int i = 0; i < 100; i++) {
      printf("%d ", data[i]);
   }
   printf("\n");
   
   // Use data mining algorithms to find the smallest and largest numbers in the data
   int smallest = data[0];
   int largest = data[0];
   
   for (int i = 1; i < 100; i++) {
      if (data[i] < smallest) {
         smallest = data[i];
      }
      if (data[i] > largest) {
         largest = data[i];
      }
   }
   
   // Print out the smallest and largest numbers found
   printf("Smallest number: %d\n", smallest);
   printf("Largest number: %d\n", largest);
   
   // Use data mining algorithms to find the average of all the numbers in the data
   int sum = 0;
   for (int i = 0; i < 100; i++) {
      sum += data[i];
   }
   
   float average = (float)sum / 100;
   
   // Print out the average
   printf("Average: %f\n", average);
   
   // Use data mining algorithms to find the mode of all the numbers in the data
   int mode = 0;
   int count = 0;
   for (int i = 0; i < 100; i++) {
      int tempCount = 0;
      for (int j = 0; j < 100; j++) {
         if (data[j] == data[i]) {
            tempCount++;
         }
      }
      if (tempCount > count) {
         mode = data[i];
         count = tempCount;
      }
   }
   
   // Print out the mode
   printf("Mode: %d\n", mode);
   
   return 0;
}