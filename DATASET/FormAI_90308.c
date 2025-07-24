//FormAI DATASET v1.0 Category: Sorting ; Style: romantic
#include <stdio.h>

int main() {
  int nums[] = {7, 4, 2, 9, 1, 5}; // Our unsorted array of numbers

  // Bubble Sort algorithm to sort the array
  int n = sizeof(nums) / sizeof(nums[0]);
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (nums[j] > nums[j + 1]) {
        int temp = nums[j];
        nums[j] = nums[j + 1];
        nums[j + 1] = temp;
      }
    }
  }

  // Print out the romantic sorted array
  printf("My love, I present to you: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");

  return 0;
}