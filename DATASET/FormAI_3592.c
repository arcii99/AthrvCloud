//FormAI DATASET v1.0 Category: Searching algorithm ; Style: creative
#include <stdio.h>

int main() {
  int arr[10] = {4, 8, 15, 16, 23, 42, 56, 72, 91, 100};
  int n = 10;
  int x;
  int position = -1;

  printf("Enter the number to be searched: ");
  scanf("%d", &x);

  int left = 0;
  int right = n - 1;
  int mid;

  while(left <= right) {
    mid = (left + right) / 2;
    
    if(arr[mid] == x) {
      position = mid;
      break;
    } else if(arr[mid] < x) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  if(position == -1) {
    printf("The number %d was not found.\n", x);
  } else {
    printf("The number %d was found at index %d.\n", x, position);
  }

  return 0;
}