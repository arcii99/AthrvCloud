//FormAI DATASET v1.0 Category: Math exercise ; Style: beginner-friendly
#include <stdio.h> // include standard input/output library
 
int main() // main function
{
    int num1, num2, result; // declare variables for numbers and result
    
    printf("Enter first integer: "); // prompt user input for first integer
    scanf("%d", &num1); // read and assign input to variable num1
    
    printf("Enter second integer: "); // prompt user input for second integer
    scanf("%d", &num2); // read and assign input to variable num2
    
    result = num1 + num2; // calculate the sum of num1 and num2
    printf("The sum of %d and %d is %d\n", num1, num2, result); // print the result
    
    result = num1 - num2; // calculate the difference of num1 and num2
    printf("The difference between %d and %d is %d\n", num1, num2, result); // print the result
    
    result = num1 * num2; // calculate the product of num1 and num2
    printf("The product of %d and %d is %d\n", num1, num2, result); // print the result
    
    result = num1 / num2; // calculate the quotient of num1 and num2
    printf("The quotient of %d and %d is %d\n", num1, num2, result); // print the result
    
    result = num1 % num2; // calculate the remainder of num1 and num2
    printf("The remainder of %d and %d is %d\n", num1, num2, result); // print the result
    
    return 0; // end the program
}