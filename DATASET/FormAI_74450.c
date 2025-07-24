//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int choice;
    float num1, num2, result;

    while(1) {
        printf("\t*** Welcome to Futuristic Calculator ***\n");
        printf("\nChoose an option:\n");
        printf("[1] Addition\n");
        printf("[2] Subtraction\n");
        printf("[3] Multiplication\n");
        printf("[4] Division\n");
        printf("[5] Power\n");
        printf("[6] Square Root\n");
        printf("[7] Logarithm (base 10)\n");
        printf("[8] Sine\n");
        printf("[9] Cosine\n");
        printf("[10] Tangent\n");
        printf("[11] Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter two values: ");
                scanf("%f %f", &num1, &num2);
                result = num1 + num2;
                printf("\n%f + %f = %f\n", num1, num2, result);
                break;
            case 2:
                printf("\nEnter two values: ");
                scanf("%f %f", &num1, &num2);
                result = num1 - num2;
                printf("\n%f - %f = %f\n", num1, num2, result);
                break;
            case 3:
                printf("\nEnter two values: ");
                scanf("%f %f", &num1, &num2);
                result = num1 * num2;
                printf("\n%f * %f = %f\n", num1, num2, result);
                break;
            case 4:
                printf("\nEnter two values: ");
                scanf("%f %f", &num1, &num2);
                result = num1 / num2;
                printf("\n%f / %f = %f\n", num1, num2, result);
                break;
            case 5:
                printf("\nEnter two values: ");
                scanf("%f %f", &num1, &num2);
                result = pow(num1, num2);
                printf("\n%f^%f = %f\n", num1, num2, result);
                break;
            case 6:
                printf("\nEnter a value: ");
                scanf("%f", &num1);
                result = sqrt(num1);
                printf("\nSquare root of %f = %f\n", num1, result);
                break;
            case 7:
                printf("\nEnter a value: ");
                scanf("%f", &num1);
                result = log10(num1);
                printf("\nLogarithm of %f (base 10) = %f\n", num1, result);
                break;
            case 8:
                printf("\nEnter a value (in degrees): ");
                scanf("%f", &num1);
                result = sin(num1 * M_PI / 180);
                printf("\nSine of %f = %f\n", num1, result);
                break;
            case 9:
                printf("\nEnter a value (in degrees): ");
                scanf("%f", &num1);
                result = cos(num1 * M_PI / 180);
                printf("\nCosine of %f = %f\n", num1, result);
                break;
            case 10:
                printf("\nEnter a value (in degrees): ");
                scanf("%f", &num1);
                result = tan(num1 * M_PI / 180);
                printf("\nTangent of %f = %f\n", num1, result);
                break;
            case 11:
                printf("\nThank you for using Futuristic Calculator!\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice, please try again.\n");
        }

        printf("\n");
    }

    return 0;
}