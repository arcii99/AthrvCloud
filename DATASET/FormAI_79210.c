//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Function to generate a random integer between 0 and 99
int generateRandomInt() {
   return rand() % 100;
}
int main() {
   // Seed the random number generator with the current time
   srand(time(NULL));
   // Create an array of 10 random integers
   int array[10];
   for (int i = 0; i < 10; i++) {
      array[i] = generateRandomInt();
   }
   // Sort the array using the bubble sort algorithm
   int sorted;
   do {
      sorted = 1;
      for (int i = 0; i < 9; i++) {
         if (array[i] > array[i+1]) {
            int temp = array[i];
            array[i] = array[i+1];
            array[i+1] = temp;
            sorted = 0;
         }
      }
   } while (!sorted);
   // Print the sorted array
   printf("Sorted Array: ");
   for (int i = 0; i < 10; i++) {
      printf("%d ", array[i]);
   }
   printf("\n");
   return 0;
}