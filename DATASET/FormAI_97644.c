//FormAI DATASET v1.0 Category: Educational ; Style: Dennis Ritchie
#include <stdio.h>

/* This program calculates the sum of the square of two numbers */

int main()
{
    int num1, num2, sum;
    
    printf("Enter the first number: ");
    scanf("%d", &num1);
    
    printf("Enter the second number: ");
    scanf("%d", &num2);
    
    sum = (num1 * num1) + (num2 * num2);
    
    printf("The sum of the square of the two numbers is %d", sum);
    
    return 0;
}