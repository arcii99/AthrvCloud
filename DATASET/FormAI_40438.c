//FormAI DATASET v1.0 Category: Recursive ; Style: optimized
#include <stdio.h>

int multiply(int num1, int num2); // function prototype declaration

int main()
{
    int result, num1, num2;
    printf("Enter two numbers to multiply:\n");
    scanf("%d%d", &num1, &num2);
    result = multiply(num1, num2);
    printf("The result of multiplication of %d and %d is %d\n", num1, num2, result);
    return 0;
}

int multiply(int num1, int num2) // function definition
{
    if (num2 == 0) // base case
        return 0;
    else if (num2 > 0) // recursive case 1
        return (num1 + multiply(num1, num2-1));
    else // recursive case 2
        return (-multiply(num1, -num2));
}