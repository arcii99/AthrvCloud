//FormAI DATASET v1.0 Category: Searching algorithm ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int cheerful_search(int arr[], int n, int target) {
  int start = 0;
  int end = n - 1;
  
  while (start <= end) {
    int mid = (start + end) / 2;
    
    if (arr[mid] == target) {
      printf("Yay! %d is found at index %d\n", target, mid);
      return mid;
    }
    else if (arr[mid] < target) {
      start = mid + 1;
      printf("Nope, %d is not at index %d. We'll search the right half of the array next!\n", target, mid);
    }
    else {
      end = mid - 1;
      printf("Nope, %d is not at index %d. We'll search the left half of the array next!\n", target, mid);
    }
  }
  
  printf("Sorry, I couldn't find %d in the array :(\n", target);
  return -1;
}

int main() {
  int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18};
  int n = sizeof(arr) / sizeof(arr[0]);
  int target = 12;
  
  printf("Welcome to my cheerful searching program!\n");
  printf("We are searching for the number %d in the array:\n", target);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n\n");
  
  cheerful_search(arr, n, target);
  
  return 0;
}