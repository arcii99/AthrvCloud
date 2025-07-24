//FormAI DATASET v1.0 Category: Searching algorithm ; Style: lively
#include <stdio.h>

// This program demonstrates a unique searching algorithm called "Dancing Elephants Algorithm"
int main() {
  printf("Welcome to Dancing Elephants Algorithm!\n");

  // Let's initialise our array to be searched
  int arr[10] = {1, 4, 6, 8, 9, 10, 11, 14, 15, 20};

  // Taking user input for search key
  int search_key;
  printf("Enter the element to be searched:");
  scanf("%d", &search_key);

  // Declaring variables needed for the search
  int left_index = 0;
  int right_index = 9; // Last index of array
  int num_of_steps = 0;

  // Searching the array using Dancing Elephants Algorithm
  while(left_index <= right_index) {
    num_of_steps++; // Counting the number of steps taken in the search
    int mid_index = (left_index + right_index) / 2;
    int mid_value = *(arr + mid_index);

    if(mid_value == search_key) {
      printf("Element found at index %d\n", mid_index);
      printf("Number of steps taken: %d\n", num_of_steps);
      return 0;
    }
    else if(mid_value < search_key) {
      left_index = mid_index + 1;
    }
    else {
      right_index = mid_index - 1; 
    }
  }

  printf("Element not found in the array!\n");
  printf("Number of steps taken: %d\n", num_of_steps);

  return 0;
}