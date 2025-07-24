//FormAI DATASET v1.0 Category: Searching algorithm ; Style: safe
#include <stdio.h>

// Function to perform linear search in an array
int linear_search(int arr[], int n, int key) {
  
  for (int i = 0; i < n; i++) {
    if (arr[i] == key)
      return i;
  }

  return -1;
}

// Function to perform binary search in an array
int binary_search(int arr[], int n, int key) {
  
  int low = 0, high = n - 1;
  
  while (low <= high) {
    int mid = low + (high - low) / 2;
    
    if (arr[mid] == key)
      return mid;
    else if (arr[mid] < key)
      low = mid + 1;
    else
      high = mid - 1;
  }

  return -1;
}

int main() {
  
  int arr[] = {1, 3, 5, 7, 9};
  int n = sizeof(arr)/sizeof(arr[0]);
  int key = 5;
  
  // Performing linear search
  int index_l = linear_search(arr, n, key);
  
  if (index_l == -1)
    printf("Element not found using linear search.");
  else
    printf("Element found at index %d using linear search.", index_l);
  
  printf("\n");
  
  // Performing binary search
  int index_b = binary_search(arr, n, key);
  
  if (index_b == -1)
    printf("Element not found using binary search.");
  else
    printf("Element found at index %d using binary search.", index_b);
  
  return 0;
}