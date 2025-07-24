//FormAI DATASET v1.0 Category: Syntax parsing ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Create an array of integers
  int arr[5] = {5, 4, 3, 2, 1};
    
  // Loop through the array in reverse order
  for (int i = 4; i >= 0; i--) {
        
    // Print out the current element
    printf("%d ", arr[i]);
        
    // If the current element is divisible by 2
    if (arr[i] % 2 == 0) {
            
      // Subtract 1 from the current element
      arr[i]--;
            
      // Print out a message to indicate the change
      printf("(changed to %d) ", arr[i]);
    }
        
    // If the current element is not divisible by 2
    else {
            
      // Add 1 to the current element
      arr[i]++;
            
      // Print out a message to indicate the change
      printf("(changed to %d) ", arr[i]);
    }
  }
    
  // Print out the final values of the array
  printf("\nFinal array: ");
  for (int i = 0; i < 5; i++) {
    printf("%d ", arr[i]);
  }
    
  return 0;
}