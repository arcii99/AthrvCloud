//FormAI DATASET v1.0 Category: Sorting ; Style: retro
#include <stdio.h>

void bubble_sort(int arr[], int n) {
  int i, j, temp;
  for (i = 0; i < n-1; i++) {
    for (j = 0; j < n-i-1; j++) {
      if (arr[j] > arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

int main() {
  int n, i;
  printf("Enter number of elements: ");
  
  scanf("%d", &n);
  int arr[n];
  
  printf("Enter %d integers:\n", n);
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  
  bubble_sort(arr, n);
  
  printf("Sorted List: ");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  
  return 0;
}