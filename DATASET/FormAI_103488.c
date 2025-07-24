//FormAI DATASET v1.0 Category: Educational ; Style: minimalist
#include <stdio.h>

// function to calculate the sum of a given array
int sum(int arr[], int size) {
  int total = 0;
  for(int i=0; i<size; i++) {
    total += arr[i];
  }
  return total;
}

int main()
{
  // declare an array of integers
  int nums[] = {1, 2, 3, 4, 5};
  int size = sizeof(nums)/sizeof(nums[0]);

  // call the sum function and print the result
  int result = sum(nums, size);
  printf("The sum is %d\n", result);

  return 0;
}