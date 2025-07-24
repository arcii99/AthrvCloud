//FormAI DATASET v1.0 Category: Searching algorithm ; Style: multivariable
#include <stdio.h>

int main() {
  int i, j, k, n, x;
  int arr[100];

  printf("Enter the size of the array: ");
  scanf("%d", &n);

  printf("Enter %d elements: \n", n);
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Enter the element to be searched: ");
  scanf("%d", &x);

  for (i = 0; i < n; i++) {
    if (arr[i] == x) {
      printf("Element found at index %d\n", i);
      break;
    }
    if(i+1 == n) {
      printf("Element not found in the array\n");
    }
  }

  return 0;
}