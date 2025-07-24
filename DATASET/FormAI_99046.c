//FormAI DATASET v1.0 Category: Arithmetic ; Style: retro
#include <stdio.h> //Include standard I/O header file

int main() //Start main function
{
    int num1, num2, result; //Declare integer variables

    printf("Enter the first number: "); //Output prompt for user input
    scanf("%d", &num1); //Accept user input

    printf("Enter the second number: "); //Output prompt for user input
    scanf("%d", &num2); //Accept user input

    result = num1 + num2; //Add two numbers and store in result variable

    printf("The sum of %d and %d is %d\n", num1, num2, result); //Output the result of addition

    result = num1 - num2; //Subtract one number from another and store in result variable

    printf("The difference between %d and %d is %d\n", num1, num2, result); //Output the result of subtraction

    result = num1 * num2; //Multiply two numbers and store in result variable

    printf("The product of %d and %d is %d\n", num1, num2, result); //Output the result of multiplication

    result = num1 / num2; //Divide one number by another and store in result variable

    printf("The quotient of %d divided by %d is %d\n", num1, num2, result); //Output the result of division

    result = num1 % num2; //Calculate the modulus of two numbers and store in result variable

    printf("The remainder of %d divided by %d is %d\n", num1, num2, result); //Output the remainder

    return 0; //Return 0 to end the program
}