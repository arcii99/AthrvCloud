//FormAI DATASET v1.0 Category: Arithmetic ; Style: surprised
#include <stdio.h>
#include <stdlib.h> // Don't forget to include the stdlib.h library!

int main(){

int num1, num2, num3; // Initializing three integer variables to store user input.
int result_addition, result_subtraction, result_multiplication, result_division, remainder; // Initializing result variables.

printf("Enter the first number: ");
scanf("%d", &num1); // Getting user input for the first number.

printf("Enter the second number: ");
scanf("%d", &num2); // Getting user input for the second number.

printf("Enter the third number: ");
scanf("%d", &num3); // Getting user input for the third number.

// Addition
result_addition = num1 + num2 + num3; // Adding up all three numbers.
printf("\n\nThe sum of the three numbers is: %d", result_addition);
printf("\nWow! You are a math genius! Adding up numbers is so much fun!\n\n");

// Subtraction
result_subtraction = num1 - num2 - num3; // Subtracting the second and third number from the first number.
printf("The difference of the three numbers is: %d", result_subtraction);
printf("\nSubtracting numbers is like solving a mystery. It's thrilling!\n\n");

// Multiplication
result_multiplication = num1 * num2 * num3; // Multiplying all three numbers.
printf("The product of the three numbers is: %d", result_multiplication);
printf("\nMultiplying numbers is like watching a magic show. It's spectacular!\n\n");

// Division
result_division = num1 / num2 / num3; // Dividing the first number by the second and third number.
remainder = num1 % (num2 * num3); // Getting the remainder by dividing the first number by the product of the second and third number.
printf("The quotient of the three numbers is: %d with a remainder of %d", result_division, remainder);
printf("\nDividing numbers is like exploring new territories. It's adventurous!\n\n");

return 0; // Always remember to return a value!
}