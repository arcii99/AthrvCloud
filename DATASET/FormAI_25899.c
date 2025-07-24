//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, i, *ptr, sum = 0;

  printf("Enter number of elements: ");
  scanf("%d", &n);

  /* Allocate memory dynamically */
  ptr = (int*) malloc(n * sizeof(int));

  if(ptr == NULL) {
    printf("Error! Memory not allocated.");
    exit(0);
  }

  printf("Enter elements of array: ");

  for(i = 0; i < n; ++i) {
    scanf("%d", ptr + i);
    sum += *(ptr + i);  /* Compute sum of all elements */
  }

  printf("Sum = %d", sum);

  /* Free memory */
  free(ptr);

  return 0;
}