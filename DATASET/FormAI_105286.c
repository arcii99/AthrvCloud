//FormAI DATASET v1.0 Category: Searching algorithm ; Style: recursive
#include <stdio.h>

int recursiveBinarySearch(int arr[], int low, int high, int target) {
  if (low > high) {
    return -1;
  }

  int middle = (low + high) / 2;

  if (arr[middle] == target) {
    return middle;
  } else if (arr[middle] > target) {
    return recursiveBinarySearch(arr, low, middle - 1, target);
  } else {
    return recursiveBinarySearch(arr, middle + 1, high, target);
  }
}

int main() {
  int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
  int target = 6;

  int index = recursiveBinarySearch(arr, 0, 9, target);

  if (index == -1) {
    printf("Element not found in the array");
  } else {
    printf("Element found at index %d", index);
  }

  return 0;
}