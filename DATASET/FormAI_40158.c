//FormAI DATASET v1.0 Category: Searching algorithm ; Style: beginner-friendly
#include <stdio.h>

int main() {
  int arr[10] = {1, 3, 5, 2, 4, 6, 8, 9, 10, 7};
  int x = 4;

  int n = sizeof(arr)/sizeof(arr[0]);
  int i;

  for(i = 0; i < n; i++) {
    if(arr[i] == x) {
      printf("Element found at index %d", i);
      break;
    }
  }

  if(i == n) {
    printf("Element not found");
  }

  return 0;
}