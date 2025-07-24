//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("This is an immersive scientific calculator program!\n");
    printf("You can perform various mathematical functions using this calculator.\n");

    int choice;
    float num1, num2, ans;
    
    printf("\nPlease choose the operation that you want to perform:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Square Root\n6. Power\n7. Sine\n8. Cosine\n9. Tangent\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nEnter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);
            ans = num1 + num2;
            printf("\nResult: %.2f + %.2f = %.2f\n", num1, num2, ans);
            break;

        case 2:
            printf("\nEnter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);
            ans = num1 - num2;
            printf("\nResult: %.2f - %.2f = %.2f\n", num1, num2, ans);
            break;

        case 3:
            printf("\nEnter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);
            ans = num1 * num2;
            printf("\nResult: %.2f * %.2f = %.2f\n", num1, num2, ans);
            break;

        case 4:
            printf("\nEnter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);
            if(num2 == 0) {
                printf("\nCannot divide by zero!\n");
                exit(0);
            }
            ans = num1 / num2;
            printf("\nResult: %.2f / %.2f = %.2f\n", num1, num2, ans);
            break;

        case 5:
            printf("\nEnter number to find square root: ");
            scanf("%f", &num1);
            ans = sqrt(num1);
            printf("\nResult: Square root of %.2f = %.2f\n", num1, ans);
            break;

        case 6:
            printf("\nEnter base: ");
            scanf("%f", &num1);
            printf("Enter power: ");
            scanf("%f", &num2);
            ans = pow(num1, num2);
            printf("\nResult: %.2f ^ %.2f = %.2f\n", num1, num2, ans);
            break;

        case 7:
            printf("\nEnter angle in degrees: ");
            scanf("%f", &num1);
            ans = sin(num1 * (M_PI / 180));
            printf("\nResult: Sin(%.2f) = %.2f\n", num1, ans);
            break;

        case 8:
            printf("\nEnter angle in degrees: ");
            scanf("%f", &num1);
            ans = cos(num1 * (M_PI / 180));
            printf("\nResult: Cos(%.2f) = %.2f\n", num1, ans);
            break;

        case 9:
            printf("\nEnter angle in degrees: ");
            scanf("%f", &num1);
            ans = tan(num1 * (M_PI / 180));
            printf("\nResult: Tan(%.2f) = %.2f\n", num1, ans);
            break;

        default:
            printf("\nInvalid choice!\n");
    }

    return 0;
}