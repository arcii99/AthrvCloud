//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    printf("\n\n Welcome to Happy Scientific Calculator! \n");
    printf(" This calculator is here to make your day! \n\n");

    int choice;
    float num1, num2, result;

    printf(" 1. Addition \n");
    printf(" 2. Subtraction \n");
    printf(" 3. Multiplication \n");
    printf(" 4. Division \n");
    printf(" 5. Square Root \n");
    printf(" 6. Power \n");
    printf(" 7. Modulo \n");
    printf(" 8. Absolute Value \n\n");

    printf(" Please enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("\n Addition! Yeah this math is HAPPY! \n\n");
            printf(" Enter your first number: ");
            scanf("%f", &num1);
            printf(" Enter your second number: ");
            scanf("%f", &num2);
            result = num1 + num2;
            printf("\n %.2f + %.2f = %.2f\n", num1, num2, result);
            break;

        case 2:
            printf("\n Subtraction! Happiness comes in all forms! \n\n");
            printf(" Enter your first number: ");
            scanf("%f", &num1);
            printf(" Enter your second number: ");
            scanf("%f", &num2);
            result = num1 - num2;
            printf("\n %.2f - %.2f = %.2f\n", num1, num2, result);
            break;

        case 3:
            printf("\n Multiplication! Happiness knows no bounds! \n\n");
            printf(" Enter your first number: ");
            scanf("%f", &num1);
            printf(" Enter your second number: ");
            scanf("%f", &num2);
            result = num1 * num2;
            printf("\n %.2f * %.2f = %.2f\n", num1, num2, result);
            break;

        case 4:
            printf("\n Division! Share your happiness with the world! \n\n");
            printf(" Enter your first number: ");
            scanf("%f", &num1);
            printf(" Enter your second number: ");
            scanf("%f", &num2);
            result = num1 / num2;
            printf("\n %.2f / %.2f = %.2f\n", num1, num2, result);
            break;

        case 5:
            printf("\n Square Root! Embrace the happiness! \n\n");
            printf(" Enter your number: ");
            scanf("%f", &num1);
            result = sqrt(num1);
            printf("\n Square root of %.2f is %.2f\n", num1, result);
            break;

        case 6:
            printf("\n Power! The happiness is in your hands! \n\n");
            printf(" Enter your base number: ");
            scanf("%f", &num1);
            printf(" Enter your exponent number: ");
            scanf("%f", &num2);
            result = pow(num1, num2);
            printf("\n %.2f to the power of %.2f is %.2f\n", num1, num2, result);
            break;

        case 7:
            printf("\n Modulo! Stay happy even when divided! \n\n");
            printf(" Enter your first number: ");
            scanf("%f", &num1);
            printf(" Enter your second number: ");
            scanf("%f", &num2);
            result = fmod(num1, num2);
            printf("\n %.2f modulo %.2f = %.2f\n", num1, num2, result);
            break;

        case 8:
            printf("\n Absolute Value! Happiness is always positive! \n\n");
            printf(" Enter your number: ");
            scanf("%f", &num1);
            result = fabs(num1);
            printf("\n The absolute value of %.2f is %.2f\n", num1, result);
            break;

        default:
            printf("\n Invalid choice, please select a number between 1-8. Happiness awaits! \n");
    }

    printf("\n\n Thank you for using Happy Scientific Calculator! Stay Happy! \n");
    return 0;
}