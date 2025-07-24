//FormAI DATASET v1.0 Category: Sorting ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int size) {
   int i, j, temp;
   for (i = 0; i < size - 1; ++i) {
      for (j = 0; j < size - 1 - i; ++j) {
         if (arr[j] > arr[j+1]) {
            temp = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = temp;
         }
      }
   }
}

void generateRandomArray(int arr[], int size) {
   int i;
   srand(time(NULL));
   for (i = 0; i < size; ++i) {
      arr[i] = rand()%50;
   }
}

void printArray(int arr[], int size) {
   int i;
   for (i = 0; i < size; ++i) {
      printf("%d ", arr[i]);
   }
}

int main() {
   int arr[10], size = 10;
   generateRandomArray(arr, size);
   printf("The randomly generated array is: \n");
   printArray(arr, size);
   printf("\n\nSorting the array using bubble sort... \n");
   bubbleSort(arr, size);
   printf("\n\nThe sorted array is: \n");
   printArray(arr, size);
   return 0;
}