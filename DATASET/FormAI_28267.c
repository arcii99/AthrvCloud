//FormAI DATASET v1.0 Category: Sorting ; Style: Ken Thompson
#include <stdio.h>

void quick_sort(int arr[], int left, int right) {
  int i = left, j = right;
  int pivot = arr[(left + right) / 2];

  while (i <= j) {
    while (arr[i] < pivot)
      i++;
    while (arr[j] > pivot)
      j--;
    if (i <= j) {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++;
      j--;
    }
  }

  if (left < j)
    quick_sort(arr, left, j);
  if (i < right)
    quick_sort(arr, i, right);
}

int main() {
  int arr[10] = {9, 2, 5, 7, 4, 8, 1, 6, 3, 0};

  quick_sort(arr, 0, 9);

  for (int i = 0; i < 10; i++)
    printf("%d ", arr[i]);

  printf("\n");

  return 0;
}