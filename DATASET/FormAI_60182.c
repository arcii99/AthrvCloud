//FormAI DATASET v1.0 Category: Educational ; Style: inquisitive
#include <stdio.h>

int main() {
  int num1, num2; // declare two integer variables
  printf("Enter a number: "); // ask user to enter a number
  scanf("%d", &num1); // read user input and assign it to num1
  printf("Enter another number: "); // ask user to enter another number
  scanf("%d", &num2); // read user input and assign it to num2

  if(num1 > num2) { // check if num1 is greater than num2
    printf("%d is greater than %d", num1, num2); // if true, print num1 is greater than num2
  } else if(num2 > num1) { // check if num2 is greater than num1
    printf("%d is greater than %d", num2, num1); // if true, print num2 is greater than num1
  } else { // if both numbers are equal
    printf("Both numbers are equal"); // print both numbers are equal
  }
  
  return 0; // end the program
}