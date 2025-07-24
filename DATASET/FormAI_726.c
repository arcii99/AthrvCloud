//FormAI DATASET v1.0 Category: Sorting ; Style: grateful
#include <stdio.h>

int main() {
  int arr[50], n, i, j, temp;

  // Grateful message to user
  printf("Thank you for choosing our sorting program!\n");

  // Ask user for array size
  printf("Please enter the size of the array (Maximum 50): ");
  scanf("%d", &n);

  // Ask user for array elements
  printf("Please enter %d elements of the array: ", n);
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Grateful message to user
  printf("Thank you for entering the array!\n");

  // Sorting algorithm
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }

  // Final sorted array
  printf("The sorted array is: ");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  // Grateful message to user
  printf("\nThank you for using our sorting program!");

  return 0;
}