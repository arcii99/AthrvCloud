//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: intelligent
#include <stdio.h>

int main() {
  int n, i, j, temp;
  printf("Enter the size of array: ");
  scanf("%d", &n);

  int arr[n];
  printf("Enter elements of array:\n");

  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  for (i = 0; i < n-1; i++) {
    for (j = i+1; j < n; j++) {
      if (arr[j] < arr[i]) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }

  printf("The sorted array in ascending order:\n");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}