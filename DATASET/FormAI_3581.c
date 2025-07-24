//FormAI DATASET v1.0 Category: Searching algorithm ; Style: futuristic
#include <stdio.h>

int main() {
  int arr[10] = {2, 5, 9, 12, 14, 16, 18, 20, 25, 28};
  int x, left = 0, right = 9, mid;

  printf("Enter the number you want to search for: ");
  scanf("%d", &x);

  while (left <= right) {
    mid = (left + right) / 2;

    // Checking if x is present at mid position
    if (arr[mid] == x) {
      printf("\nFound %d at index %d\n", x, mid+1);
      break;
    }

    // If x is greater, ignore left half
    else if (arr[mid] < x) {
      left = mid + 1;
      printf("\n%d is greater than mid-position %d. Ignoring left half.\n", x, mid+1);
    }

    // If x is smaller, ignore right half
    else {
      right = mid - 1;
      printf("\n%d is smaller than mid-position %d. Ignoring right half.\n", x, mid+1);
    }
  }

  if(left > right)
    printf("\n%d is not present in the given array\n", x);

  return 0;
}