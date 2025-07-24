//FormAI DATASET v1.0 Category: Searching algorithm ; Style: shocked
#include <stdio.h>

int main() {
  printf("What? You want me to come up with a unique C searching algorithm example program?!\n");
  
  int arr[] = {5, 6, 2, 8, 4, 9, 1, 7, 3};   // Let's use this unsorted array of integers for our program
  int key = 4;    // Let's search for the number 4 in the array
  int index = -1;   // We'll use this variable to keep track of the index where the key is found
  
  for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {    // Let's iterate through the array
    if (arr[i] == key) {    // If we find the key
      index = i;    // Store the index where it's found
    }
  }
  
  if (index == -1) {    // If the key isn't found
    printf("Sorry, the key %d is not found in the array.\n", key);
  } else {    // If the key is found
    printf("Hallelujah! The key %d is found at index %d.\n", key, index);
  }
  
  return 0;
}