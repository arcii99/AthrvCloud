//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

void bucket_sort(int arr[], int size) {
  // Create the bucket array
  int bucket[BUCKET_SIZE][size];
  for(int i = 0; i < BUCKET_SIZE; ++i) {
    for(int j = 0; j < size; ++j) {
      bucket[i][j] = -1;
    }
  }
  
  // Insert elements into the bucket array
  for(int i = 0; i < size; ++i) {
    int bucket_index = arr[i] / BUCKET_SIZE;
    for(int j = 0; j < size; ++j) {
      if(bucket[bucket_index][j] == -1) {
        bucket[bucket_index][j] = arr[i];
        break;
      }
    }
  }
  
  // Sort each bucket individually
  for(int i = 0; i < BUCKET_SIZE; ++i) {
    for(int j = 0; j < (size - 1); ++j) {
      if(bucket[i][j] == -1) {
        break;
      }
      for(int k = j + 1; k < size; ++k) {
        if(bucket[i][k] == -1) {
          break;
        }
        if(bucket[i][j] > bucket[i][k]) {
          int temp = bucket[i][j];
          bucket[i][j] = bucket[i][k];
          bucket[i][k] = temp;
        }
      }
    }
  }
  
  // Put all the elements back into the original array
  int index = 0;
  for(int i = 0; i < BUCKET_SIZE; ++i) {
    for(int j = 0; j < size; ++j) {
      if(bucket[i][j] == -1) {
        break;
      }
      arr[index++] = bucket[i][j];
    }
  }
}

int main() {
  int arr[] = {78, 17, 39, 26, 72, 94, 21, 12, 23, 68};
  int size = sizeof(arr) / sizeof(arr[0]);
  
  printf("Original array:\n");
  for(int i = 0; i < size; ++i) {
    printf("%d ", arr[i]);
  }
  
  bucket_sort(arr, size);
  
  printf("\nSorted array:\n");
  for(int i = 0; i < size; ++i) {
    printf("%d ", arr[i]);
  }
  
  return 0;
}