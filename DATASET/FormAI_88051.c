//FormAI DATASET v1.0 Category: Educational ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int choice;  // to store user's choice
    float num, result; // to store user's input number and result

    printf("Welcome to the mathematical calculation program!\n");
    printf("Select the operation you want to perform:\n");
    printf("1. Square root\n");
    printf("2. Cube root\n");
    printf("3. Power\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter a number to find its square root: ");
            scanf("%f", &num);
            result = sqrt(num);
            printf("The square root of %f is %f\n", num, result);
            break;

        case 2:
            printf("Enter a number to find its cube root: ");
            scanf("%f", &num);
            result = cbrt(num);
            printf("The cube root of %f is %f\n", num, result);
            break;

        case 3:
            printf("Enter the base number: ");
            float base;
            scanf("%f", &base);

            printf("Enter the power: ");
            float power;
            scanf("%f", &power);

            result = pow(base, power);
            printf("%f raised to the power of %f is %f\n", base, power, result);
            break;

        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}