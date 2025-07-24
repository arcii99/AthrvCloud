//FormAI DATASET v1.0 Category: Searching algorithm ; Style: peaceful
#include <stdio.h>

int sequential_search(int arr[], int length, int key) {
  int i;

  for(i = 0; i < length; i++) {
    if(arr[i] == key) {
      return i;
    }
  }

  return -1; // indicate that 'key' is not found in 'arr'
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int length = sizeof(arr) / sizeof(arr[0]);
  int key = 3;

  int index = sequential_search(arr, length, key);

  if(index != -1) {
    printf("Key found at index: %d\n", index);
  } else {
    printf("Key not found\n");
  }
  
  return 0;
}