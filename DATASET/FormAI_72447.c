//FormAI DATASET v1.0 Category: Educational ; Style: interoperable
#include <stdio.h>

/* A program that performs addition and multiplication using pointers */

int main() {
  int num1, num2;
  int *ptr1, *ptr2; // declaring integer pointers
  
  printf("Enter two numbers: ");
  scanf("%d %d", &num1, &num2);

  ptr1 = &num1; // assigning the pointer to num1
  ptr2 = &num2; // assigning the pointer to num2

  printf("\nThe sum of %d and %d is: %d\n", *ptr1, *ptr2, (*ptr1 + *ptr2));

  printf("The product of %d and %d is: %d\n", *ptr1, *ptr2, (*ptr1 * *ptr2));

  return 0;
}