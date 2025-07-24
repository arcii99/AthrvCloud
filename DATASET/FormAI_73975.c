//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: all-encompassing
#include<stdio.h>
#include<math.h>

int main()
{
    float num1, num2, result;
    int choice;
    printf("Enter the first number: ");
    scanf("%f", &num1);
    printf("Enter the second number: ");
    scanf("%f", &num2);
    printf("Choose an operation to perform:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Power\n6. Square Root\n");
    scanf("%d", &choice);
    switch (choice) 
    {
        case 1:
            result = num1 + num2;
            printf("Result of addition is: %.2f", result);
            break;
        case 2:
            result = num1 - num2;
            printf("Result of subtraction is: %.2f", result);
            break;
        case 3:
            result = num1 * num2;
            printf("Result of multiplication is: %.2f", result);
            break;
        case 4:
            if (num2 == 0)
            {
                printf("Cannot divide by zero");
            }
            else
            {
                result = num1 / num2;
                printf("Result of division is: %.2f", result);
            }
            break;
        case 5:
            result = pow(num1, num2);
            printf("Result of power is: %.2f", result);
            break;
        case 6:
            if(num1<0)
            {
                printf("Invalid Input. Cannot find square root of negative number");
            }
            else
            {
                result = sqrt(num1);
                printf("Square Root of %f is: %f",num1,result);
            }
            break;
        default:
            printf("Invalid Choice");
            break;
    }
    return 0;
}