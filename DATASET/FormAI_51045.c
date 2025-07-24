//FormAI DATASET v1.0 Category: Arithmetic ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *arr_one, *arr_two, *result;
  int n = 5;
  
  // allocate memory for the arrays and the result
  arr_one = (int*) calloc(n, sizeof(int));
  arr_two = (int*) calloc(n, sizeof(int));
  result = (int*) malloc(n * sizeof(int));
  
  // populate the arrays with random values
  printf("Array One: ");
  for (int i = 0; i < n; i++) {
    arr_one[i] = rand() % 10;
    printf("%d ", arr_one[i]);
  }
  printf("\n");
  
  printf("Array Two: ");
  for (int i = 0; i < n; i++) {
    arr_two[i] = rand() % 10;
    printf("%d ", arr_two[i]);
  }
  printf("\n");
  
  // perform arithmetic operations on the arrays
  for (int i = 0; i < n; i++) {
    result[i] = arr_one[i] + arr_two[i];
  }
  
  // display the result
  printf("Result: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", result[i]);
  }
  printf("\n");
  
  // free the dynamically allocated memory
  free(arr_one);
  free(arr_two);
  free(result);
  
  return 0;
}