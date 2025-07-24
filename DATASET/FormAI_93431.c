//FormAI DATASET v1.0 Category: Sorting ; Style: cheerful
#include <stdio.h>

int main() {
  int arr[] = {10, 5, 8, 3, 6, 2, 4, 9, 1, 7}; // our lovely array
  int n = sizeof(arr) / sizeof(arr[0]); // determine size of array
  int i, j;

  printf("Let's sort this beautiful array! :D \n\n");

  for(i = 0; i < n - 1; i++){ // bubble sort algorithm
    for(j = 0; j < n - i - 1; j++) {
      if(arr[j] > arr[j+1]) {
        int swap = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = swap;
      }
    }
  }

  printf("Ta-da! The array is now sorted: \n");

  for(i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n\nThat was fun! Let's sort more arrays! :D \n");

  return 0;
}