//FormAI DATASET v1.0 Category: Searching algorithm ; Style: shocked
#include <stdio.h>

int main() {
  int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  int n = sizeof(arr) / sizeof(int);
  int x = 70;
  int found = 0;

  printf("Searching for %d in the array...\n", x);

  for (int i = 0; i < n; i++) {
    printf("Comparing %d with %d.\n", x, arr[i]);
    if (arr[i] == x) {
      found = 1;
      printf("Found %d at index %d!\n", x, i);
      break;
    }
  }

  if (!found) {
    printf("Could not find %d in the array.\n", x);
  }

  return 0;
}