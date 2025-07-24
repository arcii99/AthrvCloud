//FormAI DATASET v1.0 Category: Searching algorithm ; Style: creative
#include <stdio.h>

int main() {
  int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  int n = sizeof(arr) / sizeof(arr[0]);
  int x = 50;
  int i, j;

  // Sort the array in ascending order
  for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      if (arr[i] > arr[j]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }

  // Use binary search to find x
  int lower = 0;
  int upper = n - 1;
  int mid;

  while (lower <= upper) {
    mid = (lower + upper) / 2;

    if (arr[mid] == x) {
      printf("%d found at index %d", x, mid);
      break;
    } else if (arr[mid] < x) {
      lower = mid + 1;
    } else {
      upper = mid - 1;
    }
  }

  if (lower > upper) {
    printf("%d not found in the array", x);
  }

  return 0;
}