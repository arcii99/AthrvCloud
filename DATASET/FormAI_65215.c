//FormAI DATASET v1.0 Category: Searching algorithm ; Style: recursive
#include <stdio.h>

int recursive_binary_search(int arr[], int low, int high, int target);

int main() {
  int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
  int size = 10;
  int target = 16;
  int result = recursive_binary_search(arr, 0, size-1, target);
  if (result != -1) {
    printf("Target %d found at index %d\n", target, result);
  } else {
    printf("Target %d not found in the array\n", target);
  }
}

int recursive_binary_search(int arr[], int low, int high, int target) {
  // Base case: search interval is empty
  if (low > high) {
    return -1;
  }
  // Calculate the middle index
  int mid = low + (high - low) / 2;
  // Check if target is at middle index
  if (arr[mid] == target) {
    return mid;
  }
  // Recurse on left half if target is less than middle element
  if (target < arr[mid]) {
    return recursive_binary_search(arr, low, mid-1, target);
  }
  // Recurse on right half if target is greater than middle element
  return recursive_binary_search(arr, mid+1, high, target);
}