//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Alan Touring
// Alan Touring's Searching Algorithm
#include <stdio.h>

int main() {
  int arr[] = { 2, 8, 15, 22, 44, 63, 71, 88, 98 };
  int n = sizeof(arr) / sizeof(arr[0]);
  int x = 63; // Element to be searched

  // Dividing the array in half while the search value is not found
  int start = 0;
  int end = n - 1;
  while (start <= end) {
    int mid = start + (end - start) / 2;

    // If x is present at mid
    if (arr[mid] == x) {
      printf("Element found at index %d", mid);
      return 0;
    }

    // If x is smaller, ignore right half
    if (arr[mid] > x) {
      end = mid - 1;
    }

    // If x is greater, ignore left half
    else {
      start = mid + 1;
    }
  }

  // If element is not present
  printf("Element not found in the array");

  return 0;
}