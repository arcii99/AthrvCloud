//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

/* Function to swap two integers */
void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

/* Function to display the array */
void display(int arr[], int n) {
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

/* Function to perform bucket sort */
void bucketSort(int arr[], int n) {
  int i, j;
  int buckets[BUCKET_SIZE];
  
  /* Initialize all the buckets to 0 */
  for (i = 0; i < BUCKET_SIZE; i++)
    buckets[i] = 0;
  
  /* Count the number of elements in each bucket */
  for (i = 0; i < n; i++)
    buckets[arr[i]]++;
  
  /* Sort the elements in each bucket using insertion sort */
  for (i = 0, j = 0; i < BUCKET_SIZE; i++) {
    while (buckets[i] > 0) {
      arr[j++] = i;
      buckets[i]--;
    }
  }
}

/* Main Function */
int main() {
  int arr[] = {5, 7, 2, 4, 1, 3, 6, 8, 9, 0};
  int n = sizeof(arr) / sizeof(arr[0]);
  
  printf("Unsorted Array:\n");
  display(arr, n);
  
  bucketSort(arr, n);
  
  printf("Sorted Array:\n");
  display(arr, n);
  
  return 0;
}