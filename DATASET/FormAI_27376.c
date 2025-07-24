//FormAI DATASET v1.0 Category: Sorting ; Style: lively
#include <stdio.h>

int main() {
  int n, i, j, temp;

  printf("Enter the number of elements to sort: ");
  scanf("%d", &n);

  int arr[n];

  printf("Enter %d integers: ", n);

  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // sorting the elements using bubble sort
  for (i = 0; i < n-1; i++) {
    for (j = 0; j < n-i-1; j++) {
      if (arr[j] > arr[j+1]) {
        // swapping the elements
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }

  printf("Sorted array in ascending order: ");

  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}