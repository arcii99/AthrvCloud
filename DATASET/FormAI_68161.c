//FormAI DATASET v1.0 Category: Sorting ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void bubbleSort(int arr[], int n) {
   int i, j, temp;
   for (i = 0; i < n-1; i++) {
       for (j = 0; j < n-i-1; j++) {
           if (arr[j] > arr[j+1]) {
               temp = arr[j];
               arr[j] = arr[j+1];
               arr[j+1] = temp;
           }
       }
   }
}

int main() {
   int arr[MAX_SIZE];
   int i, n;

   printf("Enter number of elements: ");
   scanf("%d", &n); // User input for number of elements

   printf("Enter %d numbers: ", n);
   for (i = 0; i < n; i++) {
       scanf("%d", &arr[i]); // User inputs the numbers to be sorted
   }

   bubbleSort(arr, n); // Sorting function call

   printf("Sorted list in ascending order:\n");
   for (i = 0; i < n; i++) {
       printf("%d ", arr[i]); // Sorted list output
   }
   printf("\n");

   return 0; // Program terminates
}