//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: inquisitive
//Welcome to my Bucket Sort Implementation Program!

#include <stdio.h>
#include <stdlib.h>

//Define the maximum number of buckets
#define MAX_BUCKET 10

//Function to sort the array using bucket sort
void bucketSort(int array[], int size) {

   //Create an array of buckets
   int buckets[MAX_BUCKET];

   //Initialize all values of buckets as 0
   for(int i = 0; i < MAX_BUCKET; i++) {
      buckets[i] = 0;
   }

   //Store the count of each element in buckets array
   for(int i = 0; i < size; i++) {
      ++buckets[array[i]];
   }

   //Sort the array using insertion sort
   for(int i = 0, j = 0; j < MAX_BUCKET; j++) {
      for(int k = buckets[j]; k > 0; k--) {
         array[i++] = j;
      }
   }
}

//Main function
int main() {

   //Declare the array
   int arr[10] = {9,8,7,6,5,4,3,2,1,0};

   //Print the initial array
   printf("Initial array: \n");
   for(int i = 0; i < 10; i++) {
      printf("%d ", arr[i]);
   }

   //Sort the array using bucket sort
   bucketSort(arr, 10);

   //Print the sorted array
   printf("\nSorted array: \n");
   for(int i = 0; i < 10; i++) {
      printf("%d ", arr[i]);
   }

   return 0;
}