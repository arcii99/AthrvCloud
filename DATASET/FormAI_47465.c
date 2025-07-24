//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Claude Shannon
#include <stdio.h>

int BinarySearch(int arr[], int low, int high, int target) {
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) {
      return mid;
    }
    else if (arr[mid] < target) {
      low = mid + 1;
    }
    else {
      high = mid - 1;
    }
  }
  return -1;
}

int main() {
  int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};  // Sorted array
  int n = sizeof(arr) / sizeof(arr[0]);
  int target = 7;
  int index = BinarySearch(arr, 0, n-1, target);
  if (index != -1) {
    printf("Target found at index %d", index);
  }
  else {
    printf("Target not found");
  }
  return 0;
}