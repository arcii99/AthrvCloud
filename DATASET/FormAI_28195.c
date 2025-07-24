//FormAI DATASET v1.0 Category: Searching algorithm ; Style: inquisitive
#include <stdio.h>

int main() {
  // Initialize an array of integers
  int arr[] = { 1, 3, 5, 7, 9, 11, 13, 15 };
  
  // Get the length of the array
  int length = sizeof(arr) / sizeof(int);
  
  // Prompt the user for the element to search
  printf("Enter the element to search: ");
  int elem;
  scanf("%d", &elem);
  
  // Iterate through the array and find the element
  int position = -1;
  for (int i = 0; i < length; i++) {
    if (arr[i] == elem) {
      position = i + 1;
      break;
    }
  }
  
  // Print the position of the element
  if (position == -1) {
    printf("The element was not found.\n");
  } else {
    printf("The element was found at position %d.\n", position);
  }
  
  return 0;
}