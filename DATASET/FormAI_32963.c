//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Dennis Ritchie
#include <stdio.h>

void bucket_sort(int *arr, int n) {
  // find max element in array
  int max_val = arr[0];
  for(int i = 0; i < n; i++) {
    if(arr[i] > max_val) {
      max_val = arr[i];
    }
  }
  
  // create buckets with max value + 1 size
  int buckets[max_val + 1];
  for(int i = 0; i < max_val + 1; i++) {
    buckets[i] = 0;
  }
  
  // add values to the appropriate bucket
  for(int i = 0; i < n; i++) {
    buckets[arr[i]]++;
  }
  
  // iterate over buckets and put items back in original array
  int i = 0;
  for(int j = 0; j < max_val + 1; j++) {
    while(buckets[j] > 0) {
      arr[i++] = j;
      buckets[j]--;
    }
  }
}

int main() {
  int arr[] = {4, 2, 6, 8, 1, 3, 9, 5, 7};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: ");
  for(int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  bucket_sort(arr, n);

  printf("\nSorted array: ");
  for(int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}