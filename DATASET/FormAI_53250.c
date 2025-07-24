//FormAI DATASET v1.0 Category: Memory management ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, n;
  printf("Enter the number of integers to be allocated:\n");
  scanf("%d", &n);

  int *ptr = (int*) malloc(n * sizeof(int)); // Allocate space for n integers

  // Check if memory was successfully allocated
  if (ptr == NULL) {
    printf("Memory allocation failed!\n");
    exit(0);
  }

  // Get input integers from user
  printf("Enter %d integers separated by spaces:\n", n);
  for (i = 0; i < n; i++) {
    scanf("%d", ptr + i);
  }

  // Calculate average of input integers
  double average = 0;
  for (i = 0; i < n; i++) {
    average += *(ptr + i);
  }
  average /= n;

  // Print out input integers and their distance from the average
  printf("Input integers and their distance from the average:\n");
  for (i = 0; i < n; i++) {
    printf("%d %+.2lf\n", *(ptr + i), (double) *(ptr + i) - average);
  }

  free(ptr); // Release allocated memory
  return 0;
}