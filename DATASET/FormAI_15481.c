//FormAI DATASET v1.0 Category: Arithmetic ; Style: detailed
/*
 * This program will take two integers from user and perform basic arithmetic operations.
 * The user will also choose the operation through a menu.
 * Supported operations are: Addition, Subtraction, Multiplication and Division.
 * The program provides error-checking for division by zero.
 */

#include <stdio.h>

int main() {
  	int num1, num2, result;
  	char option;

  	printf("Enter two numbers: ");
  	scanf("%d%d", &num1, &num2);

  	printf("Select an option:\n");
  	printf("a. Add\nb. Subtract\nc. Multiply\nd. Divide\n");
  	scanf(" %c", &option); // Note the space before %c to clear the input buffer.

  	switch(option) {
    	case 'a':
      		result = num1 + num2;
      		break;

    	case 'b':
      		result = num1 - num2;
      		break;

    	case 'c':
      		result = num1 * num2;
      		break;

    	case 'd':
      		if(num2 == 0) { // Check for division by zero.
        		printf("Error: division by zero.\n");
        		return 1;
      		}
      		result = num1 / num2;
      		break;

    	default:
      		printf("Invalid option.\n");
      		return 1;
  	}

  	printf("The result is %d.\n", result);

  	return 0;
}