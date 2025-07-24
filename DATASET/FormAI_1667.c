//FormAI DATASET v1.0 Category: Error handling ; Style: artistic
#include <stdio.h>

int main()
{
    int num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    // Error Handling
    
    if(num2 == 0)
    {
        printf("Division by zero is not possible!\n");
        printf("Please enter a non-zero divisor:");
        scanf("%d", &num2);
    }
    
    if(num1 < 0 || num2 < 0)
    {
        printf("Please enter only positive numbers!\n");
        return 0;
    }
    
    // Calculation
    
    result = num1 / num2;
    printf("%d divided by %d is %d\n", num1, num2, result);
    
    return 0;
}