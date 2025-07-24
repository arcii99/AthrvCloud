//FormAI DATASET v1.0 Category: Memory management ; Style: mathematical
/* This program calculates the sum of an array of integers after dynamically allocating memory for the array and freeing the memory at the end. */
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, i, sum = 0;

  printf("Enter the number of integers to be added: ");
  scanf("%d", &n);

  int *arr = (int *)malloc(n * sizeof(int)); // dynamically allocating memory for the array

  if (arr == NULL) {
    printf("Memory allocation failed. \n");
    exit(0);
  }

  printf("Enter the integers to be added:\n");

  for (i = 0; i < n; i++) {
    scanf("%d", arr+i);
  }

  for (i = 0; i < n; i++) {
    sum += *(arr+i); // adding the integers to the sum
  }

  printf("The sum of the integers is: %d \n", sum);

  free(arr); // freeing the dynamically allocated memory

  return 0;
}