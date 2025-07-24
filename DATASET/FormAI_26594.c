//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define the size of the bucket array
#define BUCKET_SIZE 10

void bucketSort(int arr[], int n) {
   // Create bucket array
   int bucket[BUCKET_SIZE] = {0};
   
   // Create sorted array
   int sorted[n];
   
   // Count the occurrences of each element in the input array
   for (int i = 0; i < n; i++) {
      bucket[arr[i]]++;
   }
   
   // Calculate the cumulative sum of the elements in the bucket array
   for (int i = 1; i < BUCKET_SIZE; i++) {
      bucket[i] = bucket[i] + bucket[i-1];
   }
   
   // Sort the elements into the sorted array
   for (int i = n - 1; i >= 0; i--) {
      sorted[--bucket[arr[i]]] = arr[i];
   }
   
   // Copy the sorted array back into the original array
   for (int i = 0; i < n; i++) {
      arr[i] = sorted[i];
   }
}

int main() {
   // Initialize the array
   int arr[] = {3, 1, 5, 9, 8, 6, 2, 4, 7, 0};
   int n = sizeof(arr) / sizeof(arr[0]);
   
   // Print the initial array
   printf("Initial array: ");
   for (int i = 0; i < n; i++) {
      printf("%d ", arr[i]);
   }
   printf("\n");
   
   // Sort the array using bucket sort
   bucketSort(arr, n);
   
   // Print the sorted array
   printf("Sorted array: ");
   for (int i = 0; i < n; i++) {
      printf("%d ", arr[i]);
   }
   printf("\n");

   return 0;
}