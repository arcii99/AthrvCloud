//FormAI DATASET v1.0 Category: Compression algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void print_array(int arr[], int size) {
   int i;
   for(i = 0; i < size; i++) {
      printf("%d ", arr[i]);
   }
   printf("\n");
}

int main() {
   int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
   int size = sizeof(arr)/sizeof(arr[0]);
   printf("Original Array: ");
   print_array(arr, size);

   int compressed_arr[size-1];
   int i, j = 0;
   for(i = 1; i < size; i+=2) {
      compressed_arr[j++] = arr[i] - arr[i-1];
   }
   printf("Compressed Array: ");
   print_array(compressed_arr, size/2);

   int decompressed_arr[size];
   decompressed_arr[0] = arr[0];
   j = 1;
   int sum = 0;
   for(i = 0; i < size/2; i++) {
      sum += compressed_arr[i];
      decompressed_arr[j++] = sum;
      decompressed_arr[j++] = arr[i*2+2];
   }
   printf("Decompressed Array: ");
   print_array(decompressed_arr, size);

   return 0;
}