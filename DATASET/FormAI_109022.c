//FormAI DATASET v1.0 Category: Arithmetic ; Style: thoughtful
/*
This is a program that takes two integers input from the user and performs arithmetic calculations on them.
The calculations it performs are addition, subtraction, multiplication, division, modulus and exponentiation.
It then prints the results to the console.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int num1, num2;
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    //perform addition
    int sum = num1 + num2;
    printf("%d + %d = %d\n", num1, num2, sum);

    //perform subtraction
    int diff = num1 - num2;
    printf("%d - %d = %d\n", num1, num2, diff);

    //perform multiplication
    int prod = num1 * num2;
    printf("%d * %d = %d\n", num1, num2, prod);

    //perform division
    if(num2 == 0){
        printf("Cannot divide by zero.\n");
    } else {
        double quotient = (double)num1 / num2;
        printf("%d / %d = %f\n", num1, num2, quotient);
    }

    //perform modulus
    int mod = num1 % num2;
    printf("%d mod %d = %d\n", num1, num2, mod);

    //perform exponentiation
    double result = pow(num1, num2);
    printf("%d to the power of %d = %f\n", num1, num2, result);

    return 0;
}