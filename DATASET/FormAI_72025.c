//FormAI DATASET v1.0 Category: Searching algorithm ; Style: irregular
#include <stdio.h>

int search(int arr[], int n, int x) {
  int i = 0, j = n - 1;
  while (i <= j) {
    int mid = (i + j) / 2;

    if (arr[mid] == x) {
      return mid;
    }

    if (arr[mid] > x && arr[i] <= x) {
      j = mid - 1;
    } else if (arr[mid] < x && arr[j] >= x) {
      i = mid + 1;
    } else if (arr[mid] < x && arr[i] > x) {
      i = mid + 1;
    } else if (arr[mid] > x && arr[j] < x) {
      j = mid - 1;
    }
  }
  return -1;
}

int main() {
  int arr[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40 };
  int n = sizeof(arr) / sizeof(arr[0]);

  int x;
  printf("Enter the number to be searched in the array: ");
  scanf("%d", &x);

  int result = search(arr, n, x);

  if (result == -1) {
    printf("Element not present in array\n");
  } else {
    printf("Element found at index %d\n", result);
  }

  return 0;
}