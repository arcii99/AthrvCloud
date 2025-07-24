//FormAI DATASET v1.0 Category: Sorting ; Style: active
#include <stdio.h>

int main() {
  int n, i, j, temp;
  printf("Enter number of elements: ");
  scanf("%d", &n);

  int arr[n];

  printf("Enter elements:\n");

  for (i = 0; i < n; i++) 
    scanf("%d", &arr[i]);

  printf("Array before sorting: ");

  for (i = 0; i < n; i++) 
    printf("%d ", arr[i]);

  printf("\n");

  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  printf("Array after sorting: ");

  for (i = 0; i < n; i++) 
    printf("%d ", arr[i]);

  printf("\n");

  return 0;
}