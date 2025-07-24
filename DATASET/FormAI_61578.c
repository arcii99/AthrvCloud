//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: medieval
#include <stdio.h>
#include <math.h>

int main()
{
    int choice, a, b;
    float result;

    printf("Welcome to the Medieval Scientific Calculator!\n");
    printf("Please select an option from below to proceed:\n");
    printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Square root\n6. Power\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter two integers to add: ");
            scanf("%d %d", &a, &b);
            result = a + b;
            printf("The sum of %d and %d is %f\n", a, b, result);
            break;

        case 2:
            printf("Enter two integers to subtract: ");
            scanf("%d %d", &a, &b);
            result = a - b;
            printf("The difference between %d and %d is %f\n", a, b, result);
            break;

        case 3:
            printf("Enter two integers to multiply: ");
            scanf("%d %d", &a, &b);
            result = a * b;
            printf("The product of %d and %d is %f\n", a, b, result);
            break;

        case 4:
            printf("Enter two integers to divide: ");
            scanf("%d %d", &a, &b);
            if(b == 0) {
                printf("Cannot divide by zero!\n");
            } else {
                result = (float) a / b;
                printf("The quotient of %d and %d is %f\n", a, b, result);
            }
            break;

        case 5:
            printf("Enter a number to find the square root: ");
            scanf("%d", &a);
            result = sqrt(a);
            printf("The square root of %d is %f\n", a, result);
            break;

        case 6:
            printf("Enter a number and its power: ");
            scanf("%d %d", &a, &b);
            result = pow(a, b);
            printf("%d raised to the power of %d is %f\n", a, b, result);
            break;

        default:
            printf("Invalid option!\n");
    }

    return 0;
}