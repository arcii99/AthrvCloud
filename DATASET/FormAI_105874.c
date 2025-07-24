//FormAI DATASET v1.0 Category: Arithmetic ; Style: invasive
#include<stdio.h>

int main()
{
    int num_1, num_2, result;
    char operator;

    printf("Enter first number: ");
    scanf("%d", &num_1);

    printf("Enter second number: ");
    scanf("%d", &num_2);

    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);

    switch(operator)
    {
        case '+':
            result = num_1 + num_2;
            printf("The sum of %d and %d is %d.", num_1, num_2, result);
            break;
        case '-':
            result = num_1 - num_2;
            printf("The difference of %d and %d is %d.", num_1, num_2, result);
            break;
        case '*':
            result = num_1 * num_2;
            printf("The product of %d and %d is %d.", num_1, num_2, result);
            break;
        case '/':
            if(num_2 == 0)
            {
                printf("Error! Division by zero is not possible.");
            }
            else
            {
                result = num_1 / num_2;
                printf("The quotient of %d and %d is %d.", num_1, num_2, result);
            }
            break;
        default:
            printf("Error! Invalid operator entered.");
    }

    return 0;
}