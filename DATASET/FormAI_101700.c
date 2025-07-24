//FormAI DATASET v1.0 Category: Sorting ; Style: enthusiastic
#include <stdio.h>

int main() {
  int nums[] = {5, 2, 10, 7, 3};
  int i, j, temp;

  printf("Unsorted array: ");
  for(i=0; i < 5; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");

  // Sort the array using bubble sort
  for(i=0; i < 5; i++) {
    for(j=0; j < 5-i-1; j++) {
      if(nums[j] > nums[j+1]) {
        temp = nums[j];
        nums[j] = nums[j+1];
        nums[j+1] = temp;
      }
    }
  }

  printf("Sorted array: ");
  for(i=0; i < 5; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");

  return 0;
}