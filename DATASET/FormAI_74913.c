//FormAI DATASET v1.0 Category: Searching algorithm ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  
  // Creating an array of integers to search through
  int arr[] = {20, 50, 85, 100, 26, 3, 66, 12, 77, 92};
  
  // Getting the size of the array
  int size = sizeof(arr)/sizeof(arr[0]);
  
  // Printing out the original array
  printf("The original array is: ");
  for(int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  
  // Prompting the user for the integer they want to search for
  printf("Enter the integer you want to search for: ");
  int key;
  scanf("%d", &key);
  
  // Creating variables to keep track of the search
  int found = 0;
  int index;
  
  // Implementing the search algorithm
  for(int i = 0; i < size; i++) {
    if(arr[i] == key) {
      found = 1;
      index = i;
      break;
    }
  }
  
  // Printing out the results of the search
  if(found == 1) {
    printf("The integer %d was found at index %d.\n", key, index);
  } else {
    printf("The integer %d was not found in the array.\n", key);
  }
  
  return 0;
}