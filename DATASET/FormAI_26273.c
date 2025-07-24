//FormAI DATASET v1.0 Category: Sorting ; Style: complete
#include <stdio.h>

int main() {
   // input array with unsorted elements
   int arr[] = {45, 23, 88, 42, 9, 17, 62, 35};
   
   // length of array
   int n = sizeof(arr)/sizeof(arr[0]);
   
   //printing original unsorted array
   printf("Original unsorted array: ");
   for(int i=0; i < n; i++) {
      printf("%d ", arr[i]);
   }
   
   // bubble sort algorithm logic
   int i, j, temp;
   for(i = 0; i < n; i++) {
      for(j = 0; j < n-i-1; j++) {
         if(arr[j] > arr[j+1]) {
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
         }
      }
   }
   
   //printing sorted array
   printf("\nSorted array: ");
   for(int i=0; i < n; i++) {
      printf("%d ", arr[i]);
   }
   
   return 0;
}