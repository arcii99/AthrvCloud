//FormAI DATASET v1.0 Category: Searching algorithm ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int search(int arr[], int n, int x) {
  int i;
  for(i = 0; i < n; i++) {
    if(arr[i] == x) {
      return i;
    }
  }
  return -1;
}

int main() {
  int size, x, result, i;
  printf("Welcome to the Happy Searching algorithm! Let's find a number in an array.\n");
  printf("Enter the size of the array: ");
  scanf("%d", &size);

  int arr[size];

  printf("Enter %d numbers: ", size);

  for(i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  printf("\nEnter the number you want to find: ");
  scanf("%d", &x);

  result = search(arr, size, x);

  if(result == -1) {
    printf("\nSorry, %d not found in the array. Keep smiling and try again next time!", x);
  } else {
    printf("\nCongratulations! %d is located at index %d in the array. Keep smiling!", x, result);
  }

  return 0;
}