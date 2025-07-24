//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: ephemeral
#include<stdio.h>
#include<math.h>

int main()
{
    int choice;
    float num1, num2, result;
    
    printf("Welcome to the Scientific Calculator!\n\n");
    
    printf("Select an operation:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exponential\n6. Square Root\n7. Logarithmic\n");
    scanf("%d", &choice);
    
    switch(choice)
    {
        case 1:
            printf("Enter two numbers to add:\n");
            scanf("%f %f", &num1, &num2);
            result = num1 + num2;
            printf("The sum of %.2f and %.2f is: %.2f\n", num1, num2, result);
            break;
            
        case 2:
            printf("Enter two numbers to subtract:\n");
            scanf("%f %f", &num1, &num2);
            result = num1 - num2;
            printf("The difference between %.2f and %.2f is: %.2f\n", num1, num2, result);
            break;
            
        case 3:
            printf("Enter two numbers to multiply:\n");
            scanf("%f %f", &num1, &num2);
            result = num1 * num2;
            printf("The product of %.2f and %.2f is: %.2f\n", num1, num2, result);
            break;
            
        case 4:
            printf("Enter two numbers to divide:\n");
            scanf("%f %f", &num1, &num2);
            if(num2 != 0)
            {
                result = num1 / num2;
                printf("The quotient of %.2f and %.2f is: %.2f\n", num1, num2, result);
            }
            else
            {
                printf("Cannot divide by zero.\n");
            }
            break;
            
        case 5:
            printf("Enter a number and its exponent:\n");
            scanf("%f %f", &num1, &num2);
            result = pow(num1, num2);
            printf("%.2f raised to the power of %.2f is: %.2f\n", num1, num2, result);
            break;
            
        case 6:
            printf("Enter a number to find its square root:\n");
            scanf("%f", &num1);
            if(num1 >= 0)
            {
                result = sqrt(num1);
                printf("The square root of %.2f is: %.2f\n", num1, result);
            }
            else
            {
                printf("Cannot find square root of a negative number.\n");
            }
            break;
            
        case 7:
            printf("Enter a number to find its logarithm:\n");
            scanf("%f", &num1);
            if(num1 > 0)
            {
                result = log10(num1);
                printf("The logarithm of %.2f is: %.2f\n", num1, result);
            }
            else
            {
                printf("Cannot find logarithm of zero or a negative number.\n");
            }
            break;
            
        default:
            printf("Invalid choice.\n");
            break;
    }
    
    printf("\nThank you for using the Scientific Calculator!\n");
    
    return 0;
}