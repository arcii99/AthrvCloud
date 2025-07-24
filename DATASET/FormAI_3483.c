//FormAI DATASET v1.0 Category: Sorting ; Style: calm
#include <stdio.h>

// Function to implement Bubble Sort Algorithm
void bubbleSort(int arr[], int n) {
  int i, j, temp;
  
  // Loop for each pass
  for (i = 0; i < n - 1; i++) {
    
    // Loop for each comparison
    for (j = 0; j < n - i - 1; j++) {
      
      // Swap the elements if they are in the wrong order
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main() {
  int arr[] = {9, 6, 7, 3, 5, 4, 1, 2, 8}; // Test array
  int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
  
  printf("Unsorted Array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  
  bubbleSort(arr, n); // Sort the array
  
  printf("\nSorted Array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  
  return 0; // Return 0 to indicate successful execution of the program
}