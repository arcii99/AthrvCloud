//FormAI DATASET v1.0 Category: Searching algorithm ; Style: minimalist
#include <stdio.h>

int search(int arr[], int size, int key) {
  int i;
  
  for (i = 0; i < size; i++) {
    if (arr[i] == key) {
      return i;
    }
  }
  
  return -1;
}

int main() {
  int arr[] = { 2, 3, 4, 10, 40 };
  int size = sizeof(arr)/sizeof(arr[0]);
  int key = 10;
  
  int result = search(arr, size, key);
  
  if (result == -1) {
    printf("Element not found");
  } else {
    printf("Element found at index %d", result);
  }
  
  return 0;
}