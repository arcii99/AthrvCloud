//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: modular
#include<stdio.h>
#include<stdlib.h>

//function to swap two integers
void swap(int* a, int* b) {
   int t = *a;
   *a = *b;
   *b = t;
}

//function to perform insertion sort on the buckets
void insertionSort(int arr[], int n) {
   int i, key, j;
   for (i = 1; i < n; i++) {
       key = arr[i];
       j = i - 1;
 
       while (j >= 0 && arr[j] > key) {
           arr[j + 1] = arr[j];
           j = j - 1;
       }
       arr[j + 1] = key;
   }
}

//main bucket sort function
void bucketSort(int arr[], int n) {
   int i, j;
   
   //create an array of buckets
   int* buckets[n];

   //initialize the buckets with 0 elements
   for (i = 0; i < n; i++) {
       buckets[i] = (int*)malloc(n * sizeof(int));
   }
   
   //distribute the elements into buckets
   for (i = 0; i < n; i++) {
       int bucketIndex = arr[i] / n;
       buckets[bucketIndex][i] = arr[i];
   }
   
   //sort the buckets
   for (i = 0; i < n; i++) {
       insertionSort(buckets[i], n-i);
   }

   //concatenate the sorted buckets into the original array
   int index = 0;
   for (i = 0; i < n; i++) {
       for (j = 0; j < n-i; j++) {
           arr[index] = buckets[i][j];
           index++;
       }
   }

   //free the memory allocated to the buckets
   for (i = 0; i < n; i++) {
       free(buckets[i]);
   }
}

//driver function to test the bucket sort
int main() {

   //initialize the unsorted array
   int arr[10] = { 8, 6, 1, 3, 9, 7, 2, 4, 5, 0 };
   
   //print the unsorted array
   printf("Unsorted array: ");
   for (int i = 0; i < 10; i++) {
       printf("%d ", arr[i]);
   }

   //sort the array using bucket sort
   bucketSort(arr, 10);

   //print the sorted array
   printf("\nSorted array: ");
   for (int i = 0; i < 10; i++) {
       printf("%d ", arr[i]);
   }

   return 0;
}