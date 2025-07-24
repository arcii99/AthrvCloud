//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum { ADD, SUBTRACT, MULTIPLY, DIVIDE, POWER, SIN, COS, TAN, LOG } operation;

int main()
{
    double a, b, result = 0;
    operation op;

    printf("Enter first number: ");
    scanf("%lf", &a);

    printf("\nEnter second number: ");
    scanf("%lf", &b);

    printf("\nAvailable operations: \n");
    printf("1. ADD\n");
    printf("2. SUBTRACT\n");
    printf("3. MULTIPLY\n");
    printf("4. DIVIDE\n");
    printf("5. POWER\n");
    printf("6. SINE\n");
    printf("7. COSINE\n");
    printf("8. TANGENT\n");
    printf("9. LOGARITHM\n");

    printf("\nEnter operation number: ");
    scanf("%u", &op);

    switch (op) {
        case ADD:
            result = a + b;
            printf("\nResult: %lf\n", result);
            break;
        case SUBTRACT:
            result = a - b;
            printf("\nResult: %lf\n", result);
            break;
        case MULTIPLY:
            result = a * b;
            printf("\nResult: %lf\n", result);
            break;
        case DIVIDE:
            if (b == 0) {
                printf("\nCannot divide by zero.\n");
            } else {
                result = a / b;
                printf("\nResult: %lf\n", result);
            }
            break;
        case POWER:
            result = pow(a, b);
            printf("\nResult: %lf\n", result);
            break;
        case SIN:
            result = sin(a);
            printf("\nResult: %lf\n", result);
            break;
        case COS:
            result = cos(a);
            printf("\nResult: %lf\n", result);
            break;
        case TAN:
            result = tan(a);
            printf("\nResult: %lf\n", result);
            break;
        case LOG:
            if (a <= 0 || b <= 0) {
                printf("\nInvalid arguments for logarithm.\n");
            } else {
                result = log(a) / log(b);
                printf("\nResult: %lf\n", result);
            }
            break;
        default:
            printf("\nInvalid operation number selected.\n");
            break;
    }

    return 0;
}