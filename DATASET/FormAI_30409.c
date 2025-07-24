//FormAI DATASET v1.0 Category: Benchmarking ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
   int i, j, tmp;
   for (i = 0; i < n-1; i++)      
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] > arr[j+1]) {
              tmp = arr[j];
              arr[j] = arr[j+1];
              arr[j+1] = tmp;
           }
}

void quickSort(int arr[], int low, int high) {
   int i = low, j = high, pivot = arr[(low + high) / 2], tmp;
   while (i <= j) {
       while (arr[i] < pivot)
            i++;
       while (arr[j] > pivot)
            j--;
       if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
       }
   }
   if (low < j)
      quickSort(arr, low, j);
   if (i < high)
      quickSort(arr, i, high);
}

int main() {
   clock_t start, stop;
   int i, n = 10000, arr1[10000], arr2[10000];
   
   srand(time(NULL));

   for (i = 0; i < n; i++) {
      arr1[i] = rand();
      arr2[i] = arr1[i];
   }
   
   start = clock();
   bubbleSort(arr1, n);
   stop = clock();

   printf("Bubble sort took %.3f seconds to execute\n", 
        (double) (stop - start) / CLOCKS_PER_SEC);

   start = clock();
   quickSort(arr2, 0, n-1);
   stop = clock();

   printf("Quick sort took %.3f seconds to execute\n", 
        (double) (stop - start) / CLOCKS_PER_SEC);

   return 0;
}