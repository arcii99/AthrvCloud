//FormAI DATASET v1.0 Category: Searching algorithm ; Style: detailed
#include <stdio.h>

/* Function to perform binary search */
int binary_search(int arr[], int left, int right, int target) {

  /* Check if the array is sorted */
  if (right >= left) {

    /* Calculate the middle index */
    int mid = left + (right - left) / 2;

    /* Check if the middle element is the target */
    if (arr[mid] == target) {
      return mid;
    }

    /* Check if the target is in the left half of the array */
    if (arr[mid] > target) {
      return binary_search(arr, left, mid - 1, target);
    }

    /* Check if the target is in the right half of the array */
    return binary_search(arr, mid + 1, right, target);
  }

  /* Target not found in the array */
  return -1;
}

int main() {

  /* Declare and initialize the array */
  int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  int n = sizeof(arr) / sizeof(arr[0]);

  /* Prompt user for input */
  int target;
  printf("Enter target: ");
  scanf("%d", &target);

  /* Perform binary search */
  int result = binary_search(arr, 0, n - 1, target);

  /* Check if target was found */
  if (result == -1) {
    printf("Target not found in the array\n");
  } else {
    printf("Target found at index %d\n", result);
  }

  return 0;
}