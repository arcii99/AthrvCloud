//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: puzzling
#include <stdio.h>

int main() {
  // Welcome message
  printf("You've stumbled upon the C Checksum Calculator!\n");
  printf("This program will compute the checksum of an integer array of size n.\n");

  // User input for array length
  printf("How many numbers are in your array?\n");
  int n;
  scanf("%d", &n);

  // Dynamic allocation for array
  int *arr = malloc(n * sizeof(int));

  // User input for array elements
  printf("Enter each number in the array, separated by a space:\n");
  for (int i = 0; i < n; i++) {
    if (i == (n - 1)) {
      scanf("%d", &arr[i]);
    } else {
      scanf("%d ", &arr[i]);
    }
  }

  // Checksum calculation
  int checksum = 0;
  printf("\nThe checksum is being calculated as we speak...\n");
  for (int i = 0; i < n; i++) {
    checksum += arr[i];
  }

  // Display checksum
  printf("The checksum of your array is: %d\n", checksum);

  // End message
  printf("Congratulations! You have successfully computed the checksum.\n");
  printf("May you use this skill wisely in all of your future endeavors.\n");

  // Deallocate memory
  free(arr);

  return 0;
}