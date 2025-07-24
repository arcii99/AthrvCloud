//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: systematic
#include <stdio.h>

int main() {
   int n, i, j, temp, max_index, max_value;
   
   printf("Enter the size of the array: ");
   scanf("%d", &n);
   
   int arr[n];
   
   printf("Enter the elements of the array: ");
   for(i = 0; i < n; i++) {
       scanf("%d", &arr[i]);
   }
   
   printf("Array before sorting: ");
   for(i = 0; i < n; i++) {
       printf("%d ", arr[i]);
   }
   
   // Applying selection sort algorithm
   for(i = 0; i < n-1; i++) {
       max_index = i;
       
       for(j = i+1; j < n; j++) {
           if(arr[j] > arr[max_index]) {
               max_index = j;
           }
       }
       
       // Swapping the maximum element with the current element
       temp = arr[max_index];
       arr[max_index] = arr[i];
       arr[i] = temp;
   }
   
   printf("\nArray after sorting: ");
   for(i = 0; i < n; i++) {
       printf("%d ", arr[i]);
   }
   
   return 0;
}