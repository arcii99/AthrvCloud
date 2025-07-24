//FormAI DATASET v1.0 Category: Searching algorithm ; Style: expert-level
#include <stdio.h>

int linear_search(int arr[], int n, int x) {
  /* This function searches for the element x in the array arr
     If found, it returns the index of the first occurrence of x
     If not found, it returns -1 */

  int i;
  for (i = 0; i < n; i++) {
    if (arr[i] == x) {
      return i;
    }
  }
  return -1;
}

int main() {
  int arr[] = {2, 3, 5, 8, 11, 25, 37, 42, 61};
  int n = sizeof(arr) / sizeof(arr[0]);

  int x = 25;
  int result = linear_search(arr, n, x);

  if (result == -1) {
    printf("%d not found\n", x);
  } else {
    printf("%d found at index %d\n", x, result);
  }

  x = 70;
  result = linear_search(arr, n, x);

  if (result == -1) {
    printf("%d not found\n", x);
  } else {
    printf("%d found at index %d\n", x, result);
  }

  return 0;
}