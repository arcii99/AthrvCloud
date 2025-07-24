//FormAI DATASET v1.0 Category: Searching algorithm ; Style: puzzling
#include <stdio.h>

int mysterySearch(int arr[], int size, int target) {

  int low = 0;
  int high = size - 1;

  while (low <= high) {

    int mid = (low + high) / 2;

    if (arr[mid] == target) {
      return mid;
    }

    if (arr[low] <= arr[mid]) {
      if (target >= arr[low] && target < arr[mid]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    if (arr[low] >= arr[mid]) {
      if (target > arr[mid] && target <= arr[high]) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

  }

  return -1;
}

int main() {

  int arr[] = {8, 9, 10, 11, 1, 2, 3, 4, 5, 6, 7};
  int size = sizeof(arr) / sizeof(int);

  printf("The array is : ");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  int target = 5;
  printf("\nThe target number is: %d\n", target);

  int result = mysterySearch(arr, size, target);
  if (result == -1) {
    printf("The target number is NOT in the array.");
  } else {
    printf("The target number is at index %d in the array.", result);
  }

  return 0;
}