//FormAI DATASET v1.0 Category: Sorting ; Style: lively
#include <stdio.h>

int main() {
   int arr[] = {5, 4 ,78, 35, 2, 123, 999, 456};
   int n = sizeof(arr)/sizeof(arr[0]);
   printf("Unsorted array: ");
   for(int i=0; i<n; i++) printf("%d ", arr[i]);

   // bubble sort
   for(int i=0; i<n-1; i++){
       for(int j=0; j<n-i-1; j++){
           if(arr[j] > arr[j+1]){
               // swapping
               int temp = arr[j];
               arr[j] = arr[j+1];
               arr[j+1] = temp;
           }
       }
   }

   // print sorted array
   printf("\nSorted array: ");
   for(int i=0; i<n; i++) printf("%d ", arr[i]);

   return 0;
}