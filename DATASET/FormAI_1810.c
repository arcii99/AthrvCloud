//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: peaceful
#include<stdio.h>
#include<math.h>

int main()
{
    int choice;
    float num1, num2, result, degree;
    printf("Welcome to the Scientific Calculator\n");
    printf("Select an Operation from Below:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exponentiation\n6. Square Root\n7. Sine\n8. Cosine\n9. Tangent\n10. Exit\n");

    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);
            result = num1 + num2;
            printf("Result: %f\n", result);
            break;

        case 2:
            printf("Enter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);
            result = num1 - num2;
            printf("Result: %f\n", result);
            break;

        case 3:
            printf("Enter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);
            result = num1 * num2;
            printf("Result: %f\n", result);
            break;

        case 4:
            printf("Enter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);
            result = num1 / num2;
            printf("Result: %f\n", result);
            break;

        case 5:
            printf("Enter the base: ");
            scanf("%f", &num1);
            printf("Enter the exponent: ");
            scanf("%f", &num2);
            result = pow(num1, num2);
            printf("Result: %f\n", result);
            break;

        case 6:
            printf("Enter the number: ");
            scanf("%f", &num1);
            result = sqrt(num1);
            printf("Result: %f\n", result);
            break;

        case 7:
            printf("Enter the degree: ");
            scanf("%f", &degree);
            result = sin(degree * 3.14159 / 180);
            printf("Result: %f\n", result);
            break;

        case 8:
            printf("Enter the degree: ");
            scanf("%f", &degree);
            result = cos(degree * 3.14159 / 180);
            printf("Result: %f\n", result);
            break;

        case 9:
            printf("Enter the degree: ");
            scanf("%f", &degree);
            result = tan(degree * 3.14159 / 180);
            printf("Result: %f\n", result);
            break;

        case 10:
            printf("Thank you for using the calculator.\n");
            exit(0);

        default:
            printf("Invalid operation.\n");
    }

    return 0;
}