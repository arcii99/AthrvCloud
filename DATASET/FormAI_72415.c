//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int choice;
    double num1, num2, result=0;

    printf("Enter your choice: \n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Power\n6. Square Root\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = num1+num2;
            printf("Result: %lf", result);
            break;

        case 2:
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = num1-num2;
            printf("Result: %lf", result);
            break;

        case 3:
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = num1*num2;
            printf("Result: %lf", result);
            break;

        case 4:
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            if(num2==0)
            {
                printf("Cannot divide by zero");
            }
            else
            {
                result = num1/num2;
                printf("Result: %lf", result);
            }
            break;

        case 5:
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result=pow(num1,num2);
            printf("Result: %lf", result);
            break;

        case 6:
            printf("Enter number: ");
            scanf("%lf",&num1);
            result=sqrt(num1);
            printf("Square root of %lf is %lf", num1, result);
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}