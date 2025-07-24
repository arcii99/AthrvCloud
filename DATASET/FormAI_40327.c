//FormAI DATASET v1.0 Category: Sorting ; Style: happy
#include <stdio.h>

int main() {
  // Start with an array of integers
  int nums[] = {9,3,6,8,1,2};
  int size = sizeof(nums) / sizeof(nums[0]);

  // Let's print out the unsorted array first
  printf("Unsorted Array: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");

  // Let's sort the array using bubble sort
  for (int i = 0; i < size-1; i++) {
    for (int j = 0; j < size-i-1; j++) {
      if (nums[j] > nums[j+1]) {
        int temp = nums[j];
        nums[j] = nums[j+1];
        nums[j+1] = temp;
      }
    }
  }

  // Let's print out the sorted array
  printf("Sorted Array: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");

  // Let's celebrate the happy sort!
  printf("Yay, the numbers are sorted and we're all smiles! :D\n");
  return 0;
}