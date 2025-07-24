//FormAI DATASET v1.0 Category: Searching algorithm ; Style: light-weight
#include <stdio.h>

int search(int arr[], int n, int key) {
  for(int i=0; i<n; i++) {
    if(arr[i] == key) {
      return i;
    }
  }
  return -1;
}

int main() {
  int arr[] = {3, 6, 9, 12, 15, 18, 21};
  int n = sizeof(arr) / sizeof(arr[0]);
  int key = 18;

  int result = search(arr, n, key);
  if(result == -1) {
    printf("%d is not present in the array.\n", key);
  } else {
    printf("%d is present at index %d.", key, result);
  }
  
  return 0;
}