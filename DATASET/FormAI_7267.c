//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define NUM_BUCKETS 10

void bucket_sort(int *arr, int n, int bucket_size);
void print_array(int *arr, int n);

int main() {
  srand(time(NULL));
  int arr[MAX_SIZE];
  int n = MAX_SIZE;
  int bucket_size = n / NUM_BUCKETS;
  
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % n;
  }
  
  printf("Array before sorting:\n");
  print_array(arr, n);
  
  printf("Sorting using bucket sort...\n");
  bucket_sort(arr, n, bucket_size);

  printf("Array after sorting:\n");
  print_array(arr, n);
  
  return 0;
}

void bucket_sort(int *arr, int n, int bucket_size) {
  // Allocate memory for buckets
  int **buckets = (int **)malloc(NUM_BUCKETS * sizeof(int *));
  for (int i = 0; i < NUM_BUCKETS; i++) {
    buckets[i] = (int *)malloc(bucket_size * sizeof(int));
  }
  
  // Initialize buckets with zeroes
  for (int i = 0; i < NUM_BUCKETS; i++) {
    for (int j = 0; j < bucket_size; j++) {
      buckets[i][j] = 0;
    }
  }
  
  // Determine the range of values in the array
  int min_val = arr[0];
  int max_val = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] < min_val) {
      min_val = arr[i];
    }
    if (arr[i] > max_val) {
      max_val = arr[i];
    }
  }
  
  // Distribute array values into the buckets
  for (int i = 0; i < n; i++) {
    int bucket_idx = (arr[i] - min_val) / bucket_size;
    for (int j = 0; j < bucket_size; j++) {
      if (buckets[bucket_idx][j] == 0) {
        buckets[bucket_idx][j] = arr[i];
        break;
      }
    }
  }
  
  // Sort each bucket individually
  #pragma omp parallel for
  for (int i = 0; i < NUM_BUCKETS; i++) {
    int *bucket = buckets[i];
    for (int j = 0; j < bucket_size - 1; j++) {
      for (int k = j + 1; k < bucket_size; k++) {
        if (bucket[j] > bucket[k]) {
          int temp = bucket[j];
          bucket[j] = bucket[k];
          bucket[k] = temp;
        }
      }
    }
  }
  
  // Merge all the buckets back into the original array
  int idx = 0;
  for (int i = 0; i < NUM_BUCKETS; i++) {
    int *bucket = buckets[i];
    for (int j = 0; j < bucket_size; j++) {
      if (bucket[j] != 0) {
        arr[idx] = bucket[j];
        idx++;
      }
    }
  }
  
  // Free memory used by buckets
  for (int i = 0; i < NUM_BUCKETS; i++) {
    free(buckets[i]);
  }
  free(buckets);
}

void print_array(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}