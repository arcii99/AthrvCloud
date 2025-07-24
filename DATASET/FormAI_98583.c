//FormAI DATASET v1.0 Category: Educational ; Style: Ken Thompson
#include <stdio.h>

int main() {
  printf("Welcome to Ken Thompson style educational program!\n");

  // Creating variables
  int number1 = 10;
  int number2 = 5;

  // Performing arithmetic operations
  int sum = number1 + number2;
  int difference = number1 - number2;
  int product = number1 * number2;
  int quotient = number1 / number2;
  int remainder = number1 % number2;

  // Printing results
  printf("The sum of %d and %d is %d.\n", number1, number2, sum);
  printf("The difference between %d and %d is %d.\n", number1, number2, difference);
  printf("The product of %d and %d is %d.\n", number1, number2, product);
  printf("The quotient of %d divided by %d is %d with a remainder of %d.\n", number1, number2, quotient, remainder);

  // Creating an array
  int array[5] = {1, 2, 3, 4, 5};

  // Printing array elements
  printf("The elements of the array are: ");
  for(int i = 0; i < 5; i++) {
    printf("%d ", array[i]);
  }

  // Changing array element
  array[0] = 10;

  // Printing array elements again
  printf("\nAfter changing the first element, the elements of the array are: ");
  for(int i = 0; i < 5; i++) {
    printf("%d ", array[i]);
  }

  // Creating a structure
  struct student {
    char name[20];
    int age;
    float gpa;
  };

  // Creating a structure variable
  struct student john;

  // Assigning values to the structure variable
  strcpy(john.name, "John");
  john.age = 20;
  john.gpa = 3.5;

  // Printing the structure variable
  printf("\n\nName: %s\nAge: %d\nGPA: %f", john.name, john.age, john.gpa);

  return 0;
}