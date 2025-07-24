//FormAI DATASET v1.0 Category: Benchmarking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

void populate_array(int arr[]) {
  srand(time(NULL));
  for(int i = 0; i < SIZE; i++) {
    arr[i] = rand() % 100 + 1;
  }
}

void print_array(int arr[]) {
  for(int i = 0; i < SIZE; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int max(int arr[], int start, int end) {
  int mid = (start + end) / 2;
  if(start == end) {
    return arr[start];
  } else {
    int left = max(arr, start, mid);
    int right = max(arr, mid+1, end);
    if(left > right) {
      return left;
    } else {
      return right;
    }
  }
}

int min(int arr[], int start, int end) {
  int mid = (start + end) / 2;
  if(start == end) {
    return arr[start];
  } else {
    int left = min(arr, start, mid);
    int right = min(arr, mid+1, end);
    if(left < right) {
      return left;
    } else {
      return right;
    }
  }
}

int main() {
  int arr[SIZE];
  populate_array(arr);
  printf("Array: ");
  print_array(arr);
  clock_t t;

  t = clock();
  int maximum = max(arr, 0, SIZE-1);
  t = clock() - t;
  double time_taken1 = ((double)t)/CLOCKS_PER_SEC;
  printf("Maximum value: %d\n", maximum);
  printf("Max function took %f seconds to execute \n", time_taken1);

  t = clock();
  int minimum = min(arr, 0, SIZE-1);
  t = clock() - t;
  double time_taken2 = ((double)t)/CLOCKS_PER_SEC;
  printf("Minimum value: %d\n", minimum);
  printf("Min function took %f seconds to execute \n", time_taken2);

  return 0;
}