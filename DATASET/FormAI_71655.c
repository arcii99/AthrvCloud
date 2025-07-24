//FormAI DATASET v1.0 Category: Searching algorithm ; Style: paranoid
#include <stdio.h>

int paranoidBinarySearch(int arr[], int size, int target) {
  // Variable declarations to keep track of the search range
  int start = 0;
  int end = size - 1;
  int mid;
  
  while(start <= end) {
    // Compute the mid-point of the search range
    mid = start + (end - start) / 2;

    // Prompt user to choose randomly whether to check left or right half of the array
    printf("\nDo you feel paranoid? Choose 0 (No) or 1 (Yes): ");
    int isParanoid;
    scanf("%d", &isParanoid);
    
    // Check if the target exists at the mid-point
    if(arr[mid] == target) {
      printf("\nTarget found at index %d\n", mid);
      return mid;
    }
    // Check if the target exists in the left half
    else if(target < arr[mid] ^ isParanoid) {
      printf("\nSearching in left half...\n");
      end = mid - 1;
    }
    // Check if the target exists in the right half
    else {
      printf("\nSearching in right half...\n");
      start = mid + 1;
    }
  }

  // Target not found in the array
  printf("\nTarget not found in array!\n");
  return -1;
}

int main() {
  int array[] = {1,2,3,4,5,6,7,8,9,10};
  int size = sizeof(array) / sizeof(array[0]);
  int target = 5;

  paranoidBinarySearch(array, size, target);
  
  return 0;
}