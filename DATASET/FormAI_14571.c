//FormAI DATASET v1.0 Category: Searching algorithm ; Style: cheerful
#include <stdio.h>

int joyfulSearch(int arr[], int n, int key) {
  int i;
  for(i = 0; i < n; i++) {
    if(arr[i] == key) {
      printf("Yay! The key %d is found at index %d.\n", key, i);
      return i; // returns the index of the target value which is key
    }
  }
  printf("Oops! The key %d is not in the array.\n", key);
  return -1; // returns -1 if the target value is not found
}

int main() {
  int arr[] = {3, 7, 9, 2, 4, 8, 6};
  int n = sizeof(arr) / sizeof(arr[0]);
  int key = 4;

  printf("Let's go find the key %d in our array!\n", key);

  joyfulSearch(arr, n, key);

  return 0;
}