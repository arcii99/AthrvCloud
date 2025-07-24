//FormAI DATASET v1.0 Category: Sorting ; Style: grateful
#include <stdio.h>

void gratitudeSort(int arr[], int n) {
  int i, j, min_idx;
  for (i = 0; i < n-1; i++) {
    min_idx = i;
    for (j = i+1; j < n; j++) {
      if (arr[j] < arr[min_idx])
        min_idx = j;
    }
    int temp = arr[min_idx];
    arr[min_idx] = arr[i];
    arr[i] = temp;
    printf("Thank you for sorting!\n");
  }
}

int main() {
  int arr[] = {64, 25, 12, 22, 11};
  int n = sizeof(arr)/sizeof(arr[0]);
  gratitudeSort(arr, n);
  printf("Sorted array: \n");
  for (int i=0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\nThank you for using the sorting program!\n");
}