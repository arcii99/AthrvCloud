//FormAI DATASET v1.0 Category: Educational ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

   srand(time(NULL));

   int arraySize = 10;
   int numbers[arraySize];

   printf("Generating %d random numbers:\n", arraySize);

   for(int i = 0; i < arraySize; i++) {
      numbers[i] = rand() % 1000;
      printf("%d ", numbers[i]);
   }

   // Bubble sort
   int temp;
   for(int i = 0; i < arraySize-1; i++) {
      for(int j = 0; j < arraySize-i-1; j++) {
         if(numbers[j] > numbers[j+1]) {
            temp = numbers[j];
            numbers[j] = numbers[j+1];
            numbers[j+1] = temp;
         }
      }
   }

   printf("\n\nSorting in ascending order:\n");

   for(int i = 0; i < arraySize; i++) {
      printf("%d ", numbers[i]);
   }

   printf("\n\nSorting in descending order:\n");

   for(int i = arraySize-1; i >= 0; i--) {
      printf("%d ", numbers[i]);
   }
   
   printf("\nDone\n");
   
   return 0;
}