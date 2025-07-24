//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// define maximum value for integers to be sorted
#define MAX_VALUE 1000

// define number of buckets and size of each bucket
#define NUM_BUCKETS 10
#define BUCKET_SIZE (MAX_VALUE / NUM_BUCKETS)

// define struct for a bucket
typedef struct bucket {
  int count;
  int values[BUCKET_SIZE];
} Bucket;

int main() {
  int arr[] = {75, 28, 97, 45, 2, 76, 23, 44, 78, 88, 15, 9, 67, 47, 91, 84};
  int n = sizeof(arr) / sizeof(int);

  // create buckets
  Bucket buckets[NUM_BUCKETS];

  // initialize each bucket count to 0
  for (int i = 0; i < NUM_BUCKETS; i++) {
    buckets[i].count = 0;
  }

  // distribute each element of array into the corresponding bucket
  for (int i = 0; i < n; i++) {
    int bucket_index = arr[i] / BUCKET_SIZE;
    buckets[bucket_index].values[buckets[bucket_index].count++] = arr[i];
  }

  // sort each bucket using bubble sort
  for (int i = 0; i < NUM_BUCKETS; i++) {
    for (int j = 0; j < buckets[i].count - 1; j++) {
      for (int k = 0; k < buckets[i].count - j - 1; k++) {
        if (buckets[i].values[k] > buckets[i].values[k+1]) {
          int temp = buckets[i].values[k];
          buckets[i].values[k] = buckets[i].values[k+1];
          buckets[i].values[k+1] = temp;
        }
      }
    }
  }

  // concatenate all buckets into final sorted array
  int index = 0;
  for (int i = 0; i < NUM_BUCKETS; i++) {
    for (int j = 0; j < buckets[i].count; j++) {
      arr[index++] = buckets[i].values[j];
    }
  }

  // print sorted array
  printf("Sorted array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}