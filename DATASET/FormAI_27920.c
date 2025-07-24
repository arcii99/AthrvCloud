//FormAI DATASET v1.0 Category: Memory management ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main() {
  int* ptr; // Declare a pointer of type int
  int size, i, sum = 0; // Declare other variables

  printf("How many integers do you want to enter?\n");
  scanf("%d", &size);

  ptr = (int*) malloc(size * sizeof(int)); // Allocate memory to the pointer

  if (ptr == NULL) {
    printf("Memory allocation failed. Exiting program.\n");
    exit(0);
  } else {
    printf("Memory allocation successful. Begin entering integers.\n");
    for (i = 0; i < size; i++) {
      printf("Enter integer %d: ", i+1);
      scanf("%d", ptr+i); // Use pointer arithmetic to fill in values
      sum += *(ptr+i); // Use dereferencing to calculate sum
    }

    printf("\nThe integers you entered are: ");
    for (i = 0; i < size; i++) {
      printf("%d ", *(ptr+i)); // Display values using dereferencing
    }

    printf("\nThe sum of the integers is: %d\n", sum);

    free(ptr); // Free up the allocated memory
  }

  return 0;
}