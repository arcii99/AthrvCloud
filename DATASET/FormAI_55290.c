//FormAI DATASET v1.0 Category: Searching algorithm ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int search(int* arr, int target, int size) {
  int current = 0;
  int increment = 2;
  while(current < size) {
    if(arr[current] == target) {
      return current;
    }
    else if(arr[current] < target) {
      current += increment;
      increment++;
    }
    else {
      for(int i = current; i > current - increment; i--) {
        if(arr[i] == target) {
          return i;
        }
      }
      return -1;
    }
  }
  return -1;
}

int main() {
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int index = search(arr, 8, 10);
  if(index != -1) {
    printf("Item found at index: %d", index);
  }
  else {
    printf("Item not found.");
  }
  return 0;
}