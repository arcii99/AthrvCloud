//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: relaxed
#include <stdio.h>

int main(void) {
  int n, i;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter the array elements:\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  int minIndex, temp;

  // Implementation of selection sort
  for (i = 0; i < n-1; i++) {
    minIndex = i;
    for (int j = i+1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
  }

  printf("The elements sorted in ascending order:\n");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}