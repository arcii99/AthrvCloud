//FormAI DATASET v1.0 Category: Sorting ; Style: excited
#include <stdio.h>

int main() {
  printf("Welcome to the most amazing sorting program ever!\n");
  
  int arr[] = {5, 2, 8, 3, 1, 7, 9, 4, 6, 0};
  int n = sizeof(arr) / sizeof(arr[0]);
  
  printf("Unsorted array: ");
  for(int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  
  printf("Let's sort this baby!\n");
  
  for(int i = 0; i < n - 1; i++) {
    for(int j = 0; j < n - i - 1; j++) {
      if(arr[j] > arr[j+1]) {
        // swap
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  
  printf("Sorted array: ");
  for(int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  
  printf("Ta-daa! Wasn't that amazing? I know, right?\n");
  
  return 0;
}