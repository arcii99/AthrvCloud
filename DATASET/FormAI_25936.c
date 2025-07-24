//FormAI DATASET v1.0 Category: Memory management ; Style: satisfied
/**
 * This program demonstrates the use of dynamic memory allocation in C.
 * It creates an array of size n using malloc(), then prompts the user to
 * input n integers, which are stored in the array. The program then
 * prints out the sum of the integers and frees the dynamically allocated
 * memory.
**/

#include <stdio.h>
#include <stdlib.h>

int main() {
  int *array;
  int sum = 0;
  int n;

  printf("Enter the size of the array: ");
  scanf("%d", &n);

  // Allocate memory for the array
  array = (int *) malloc(n * sizeof(int));

  // Prompt user to input n integers
  printf("Enter %d integers:\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }

  // Calculate the sum of the integers
  for (int i = 0; i < n; i++) {
    sum += array[i];
  }

  printf("The sum of the integers is %d.\n", sum);

  // Free dynamically allocated memory
  free(array);

  return 0;
}