//FormAI DATASET v1.0 Category: Searching algorithm ; Style: random
#include <stdio.h>

int main() {
  int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49};
  int n = sizeof(arr) / sizeof(arr[0]);
  int x; 
  int left = 0, right = n - 1;

  printf("Enter the number you want to search: ");
  scanf("%d", &x);

  while (left <= right) {
    int mid_left = left + (right - left) / 3;
    int mid_right = right - (right - left) / 3;
    
    if (arr[mid_left] == x) {
      printf("%d is found at index %d", x, mid_left);
      return 0;
    }
    if (arr[mid_right] == x) {
      printf("%d is found at index %d", x, mid_right);
      return 0;
    }
    if (x < arr[mid_left]) {
      right = mid_left - 1;
    } else if (x > arr[mid_right]) {
      left = mid_right + 1;
    } else {
      left = mid_left + 1;
      right = mid_right - 1;
    }
  }
  printf("%d is not found", x);
  return 0;
}