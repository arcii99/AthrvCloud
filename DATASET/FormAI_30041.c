//FormAI DATASET v1.0 Category: Arithmetic ; Style: genious
#include <stdio.h>

int main()
{
    printf("Hello there! I am a genius chatbot who is going to show you an example of a unique arithmetic program.\n");
    
    // let's declare some variables
    int a = 10, b = 20, result = 0;
    double c = 3.14, d = 2.71, finalResult = 0;
    
    // here we are going to do some arithmetic operations
    result = a + b;
    printf("The sum of %d and %d is %d.\n", a, b, result);
    
    result = b - a;
    printf("The difference of %d and %d is %d.\n", b, a, result);
    
    result = a * b;
    printf("The product of %d and %d is %d.\n", a, b, result);
    
    finalResult = c / d;
    printf("The division of %.2f and %.2f is %.2f.\n", c, d, finalResult);
    
    finalResult = (a + b) * c;
    printf("The result of the expression (a + b) * c with a=%d, b=%d and c=%.2f is %.2f.\n", a, b, c, finalResult);
    
    // now let's use some arithmetic operators
    result = a + b;
    printf("%d + %d = %d\n", a, b, result);
    
    result = b - a;
    printf("%d - %d = %d\n", b, a, result);
    
    result = a * b;
    printf("%d * %d = %d\n", a, b, result);
    
    finalResult = c / d;
    printf("%.2f / %.2f = %.2f\n", c, d, finalResult);
    
    result = b % a;
    printf("%d mod %d = %d\n", b, a, result);
    
    result++;
    printf("The variable 'result' is now %d.\n", result);
    
    result--;
    printf("The variable 'result' is now %d.\n", result);
    
    // let's use some conditional statements
    if (a == 10 && b == 20)
    {
        printf("Both a and b are equal to their respective values.\n");
    }
    
    if (a != b)
    {
        printf("%d is not equal to %d.\n", a, b);
    }
    
    if (a < b)
    {
        printf("%d is less than %d.\n", a, b);
    }
    
    if (b > a)
    {
        printf("%d is greater than %d.\n", b, a);
    }
    
    // let's use some loops
    int i;
    for (i = 1; i <= 10; i++)
    {
        printf("%d\n", i);
    }
    
    i = 1;
    while (i <= 10)
    {
        printf("%d\n", i);
        i++;
    }
    
    do
    {
        printf("%d\n", i);
        i--;
    } while (i >= 1);
    
    printf("Thanks for running my amazing arithmetic program!");
    
    return 0;
}