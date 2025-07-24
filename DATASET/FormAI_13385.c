//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  printf("Enter the size of the array: ");
  scanf("%d", &n);

  int* arr = (int*) malloc(n * sizeof(int));

  // Initialize array with random values
  for(int i = 0; i < n; i++)
    arr[i] = rand();

  printf("Before sorting:\n");
  for(int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  
  for(int i = 0; i < n-1; i++) {
    for(int j = 0; j < n-i-1; j++) {
      if(arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }

  printf("\n\nAfter sorting:\n");
  for(int i = 0; i < n; i++)
    printf("%d ", arr[i]);

  free(arr);
  return 0;
}