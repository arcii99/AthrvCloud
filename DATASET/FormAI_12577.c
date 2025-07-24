//FormAI DATASET v1.0 Category: Arithmetic ; Style: rigorous
#include <stdio.h>

int main()
{
    int num1, num2, result;
    
    printf("Enter the first number: ");
    scanf("%d", &num1);
    
    printf("Enter the second number: ");
    scanf("%d", &num2);
      
    result = num1 + num2;
    printf("The sum of %d and %d is %d\n", num1, num2, result);
    
    result = num1 - num2;
    printf("The difference of %d and %d is %d\n", num1, num2, result);
    
    result = num1 * num2;
    printf("The product of %d and %d is %d\n", num1, num2, result);
    
    result = num1 / num2;
    printf("The quotient of %d and %d is %d\n", num1, num2, result);
    
    result = num1 % num2;
    printf("The remainder of %d and %d is %d\n", num1, num2, result);
    
    return 0;
}