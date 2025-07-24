//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Function to perform bucket sort
void bucketSort(int arr[], int n, int no_of_buckets) {

  // Create no_of_buckets empty buckets
  int buckets[no_of_buckets][n/2];

  // Initialize bucket sizes as 0
  int bucket_sizes[no_of_buckets];
  for (int i = 0; i < no_of_buckets; i++) {
    bucket_sizes[i] = 0;
  }

  // Assign elements into their respective buckets
  for (int i = 0; i < n; i++) {
    int bucket_index = arr[i] / no_of_buckets;
    buckets[bucket_index][bucket_sizes[bucket_index]] = arr[i];
    bucket_sizes[bucket_index]++;
  }

  // Sort elements in each bucket and merge
  int k = 0;
  for (int i = 0; i < no_of_buckets; i++) {
    int* bucket_arr = buckets[i];
    int bucket_size = bucket_sizes[i];

    // Sort elements in current bucket using insertion sort
    for (int j = 1; j < bucket_size; j++) {
      int key = bucket_arr[j];
      int l = j-1;
      while (l >= 0 && bucket_arr[l] > key) {
        bucket_arr[l+1] = bucket_arr[l];
        l--;
      }
      bucket_arr[l+1] = key;
    }

    // Merge sorted bucket elements into final array
    for (int j = 0; j < bucket_size; j++) {
      arr[k++] = bucket_arr[j];
    }
  }
}

// Driver function
int main() {

  // Initialize array to be sorted
  int n = 15;
  int arr[] = {10, 8, 6, 4, 2, 7, 9, 1, 3, 5, 13, 15, 12, 11, 14};

  // Print unsorted array
  printf("Unsorted Array:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  // Call bucket sort function with no_of_buckets as 3
  bucketSort(arr, n, 3);

  // Print sorted array
  printf("\n\nSorted Array:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}