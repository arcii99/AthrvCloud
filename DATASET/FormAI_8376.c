//FormAI DATASET v1.0 Category: Educational ; Style: Linus Torvalds
/* 
  This piece of code demonstrates the use of pointers, arrays and functions in C.
  Written by [Your Name], [Your Email], [Your Date of Creation].
*/

#include <stdio.h>

/* Function declaration */
void sum_array(int *arr, int size);

int main(void) {
  int arr[] = {5, 2, 1, 4, 3};
  int size = sizeof(arr)/sizeof(arr[0]);

  /* Print the original array */
  printf("Original Array: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  /* Call the function to sum the array */
  sum_array(&arr[0], size);

  return 0;
}

/* Function definition */
void sum_array(int *arr, int size) {
  int sum = 0;

  /* Loop through the array and add up the values */
  for (int i = 0; i < size; i++) {
    sum += *(arr + i); // Using pointer arithmetic to access each element of the array
  }

  /* Print the sum of the array */
  printf("Sum of Array: %d\n", sum);
}