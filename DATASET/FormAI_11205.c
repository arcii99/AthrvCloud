//FormAI DATASET v1.0 Category: Searching algorithm ; Style: happy
#include <stdio.h> 

int main() 
{ 
  // Declare an array of numbers 
  int arr[10] = { 5, 4, 6, 8, 3, 2, 1, 9, 7, 10 }; 

  // Declare a variable to store the search key 
  int key = 7; 

  // Declare a flag variable for search status 
  int found = 0; 

  // Loop through the array to search for the key 
  for (int i = 0; i < 10; i++) { 
    // Check if the current element is equal to the key 
    if (arr[i] == key) { 
      // Set the flag variable to indicate successful search 
      found = 1; 

      // Print a happy message revealing the index of the key 
      printf("Hooray! Key found at position %d!\n",i+1); 

      // Exit the loop since the key has been found 
      break; 
    } 
  } 

  // If the key was not found, print a sad message 
  if (!found) { 
      printf("Oh no! Key not found!\n"); 
  } 

  return 0; 
}