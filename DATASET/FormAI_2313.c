//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(float *arr, int n) {
  // Find the maximum value in the array
  float max_value = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > max_value) {
      max_value = arr[i];
    }
  }

  // Create the buckets and initialize them to empty
  int num_buckets = n;
  float **buckets = malloc(sizeof(float*) * num_buckets);
  for (int i = 0; i < num_buckets; i++) {
    buckets[i] = NULL;
  }

  // Distribute the values into the buckets
  for (int i = 0; i < n; i++) {
    int bucket_index = (int)(arr[i] / max_value * (num_buckets - 1));
    if (buckets[bucket_index] == NULL) {
      buckets[bucket_index] = malloc(sizeof(float));
      *(buckets[bucket_index]) = arr[i];
    } else {
      int bucket_size = 1;
      while (buckets[bucket_index][bucket_size - 1] > 0 &&
             arr[i] > buckets[bucket_index][bucket_size - 1]) {
        bucket_size++;
        buckets[bucket_index] = realloc(buckets[bucket_index],
                                         sizeof(float) * bucket_size);
        buckets[bucket_index][bucket_size - 1] = buckets[bucket_index][bucket_size - 2];
      }
      *(buckets[bucket_index] + bucket_size - 1) = arr[i];
    }
  }

  // Sort the values in each non-empty bucket
  for (int i = 0; i < num_buckets; i++) {
    if (buckets[i] != NULL) {
      int bucket_size = 0;
      while (buckets[i][bucket_size] > 0) {
        bucket_size++;
      }
      for (int j = 0; j < bucket_size - 1; j++) {
        for (int k = 0; k < bucket_size - j - 1; k++) {
          if (buckets[i][k] > buckets[i][k + 1]) {
            float temp = buckets[i][k];
            buckets[i][k] = buckets[i][k + 1];
            buckets[i][k + 1] = temp;
          }
        }
      }
    }
  }

  // Copy the sorted values back into the original array
  int index = 0;
  for (int i = 0; i < num_buckets; i++) {
    if (buckets[i] != NULL) {
      int bucket_size = 0;
      while (buckets[i][bucket_size] > 0) {
        arr[index] = buckets[i][bucket_size];
        index++;
        bucket_size++;
      }
      free(buckets[i]);
    }
  }

  // Free the memory used by the buckets
  free(buckets);
}

int main() {
  float arr[10] = {0.5, 0.1, 0.9, 0.3, 0.7, 0.2, 0.8, 0.4, 0.6, 0};
  int n = sizeof(arr) / sizeof(float);
  printf("Before sorting:\n");
  for (int i = 0; i < n; i++) {
    printf("%.1f ", arr[i]);
  }
  printf("\n");

  bucket_sort(arr, n);

  printf("After sorting:\n");
  for (int i = 0; i < n; i++) {
    printf("%.1f ", arr[i]);
  }
  printf("\n");

  return 0;
}