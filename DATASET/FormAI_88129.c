//FormAI DATASET v1.0 Category: Searching algorithm ; Style: romantic
#include <stdio.h>

int linearSearch(int arr[], int n, int x) {

  for (int i = 0; i < n; i++) {

      if (arr[i] == x) {

          return i;

      }

  }

  return -1;

}

int main() {

  int arr[] = {27, 15, 34, 76, 98, 56, 42};
  int n = sizeof(arr) / sizeof(arr[0]);
  int x = 76;
  
  int result = linearSearch(arr, n, x);
  
  if(result == -1) {
  
      printf("The element is not present in the array.");
  
  } else {
      
      printf("The element %d is present at index %d.", x, result);

  }
  
  return 0;

}