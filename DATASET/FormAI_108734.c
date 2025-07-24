//FormAI DATASET v1.0 Category: Sorting ; Style: authentic
#include <stdio.h>

void bubble_sort(int arr[], int n) {
   int temp;
   for(int i = 0; i < n-1; i++) {
      for(int j = 0; j < n-i-1; j++) {
         if(arr[j] > arr[j+1]) {
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
         }
      }
   }
}

void selection_sort(int arr[], int n) {
   int i, j, min_idx;
   for (i = 0; i < n-1; i++) {
      min_idx = i;
      for (j = i+1; j < n; j++) {
         if(arr[j] < arr[min_idx])
            min_idx = j;
      }
      int temp = arr[min_idx];
      arr[min_idx] = arr[i];
      arr[i] = temp;
   }
}

void insertion_sort(int arr[], int n) {
   int i, key, j;
   for (i = 1; i < n; i++) {
      key = arr[i];
      j = i-1;

      while (j >= 0 && arr[j] > key) {
         arr[j+1] = arr[j];
         j = j-1;
      }
      arr[j+1] = key;
   }
}

int main() {
   int arr[] = {34, 56, 7, 89, 23, 67, 43, 12};
   int n = sizeof(arr)/sizeof(arr[0]);

   printf("Original Array: ");
   for(int i = 0; i < n; i++) {
      printf("%d ", arr[i]);
   }
   printf("\n");

   // Bubble sort
   bubble_sort(arr, n);
   printf("Array sorted using bubble sort: ");
   for(int i = 0; i < n; i++) {
      printf("%d ", arr[i]);
   }
   printf("\n");

   // Selection Sort
   int arr2[] = {34, 56, 7, 89, 23, 67, 43, 12};
   printf("Original Array: ");
   for(int i = 0; i < n; i++) {
      printf("%d ", arr2[i]);
   }
   printf("\n");

   selection_sort(arr2, n);
   printf("Array sorted using selection sort: ");
   for(int i = 0; i < n; i++) {
      printf("%d ", arr2[i]);
   }
   printf("\n");

   // Insertion Sort
   int arr3[] = {34, 56, 7, 89, 23, 67, 43, 12};
   printf("Original Array: ");
   for(int i = 0; i < n; i++) {
      printf("%d ", arr3[i]);
   }
   printf("\n");

   insertion_sort(arr3, n);
   printf("Array sorted using insertion sort: ");
   for(int i = 0; i < n; i++) {
      printf("%d ", arr3[i]);
   }
   printf("\n");

   return 0;
}