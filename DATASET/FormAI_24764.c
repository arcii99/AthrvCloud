//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Romeo and Juliet
/*
 * Romeo and Juliet Scientific Calculator
 * By: [Your Name]
 */

#include <stdio.h>
#include <math.h>

int main() {
    int choice, num1, num2, i;
    float fnum1, fnum2, result;
    
    printf("O Romeo, my dear Romeo, please select an operation:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Square\n");
    printf("6. Square Root\n");
    printf("7. Exponentiation\n");
    printf("8. Logarithm\n");
    printf("9. Exit\n");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("O Romeo, please enter two integers to be added: ");
            scanf("%d %d", &num1, &num2);
            result = num1 + num2;
            printf("The sum is: %f", result);
            break;
        case 2:
            printf("O Romeo, please enter two integers to be subtracted: ");
            scanf("%d %d", &num1, &num2);
            result = num1 - num2;
            printf("The difference is: %f", result);
            break;
        case 3:
            printf("O Romeo, please enter two integers to be multiplied: ");
            scanf("%d %d", &num1, &num2);
            result = num1 * num2;
            printf("The product is: %f", result);
            break;
        case 4:
            printf("O Romeo, please enter two integers to be divided: ");
            scanf("%d %d", &num1, &num2);
            while(num2 == 0) {
                printf("O unhappy dagger, division by zero is not allowed.\n");
                printf("Please enter a different divisor: ");
                scanf("%d", &num2);
            }
            result = (float)num1 / num2;
            printf("The quotient is: %f", result);
            break;
        case 5:
            printf("O Romeo, please enter an integer to be squared: ");
            scanf("%d", &num1);
            result = pow(num1, 2);
            printf("The square is: %f", result);
            break;
        case 6:
            printf("O Romeo, please enter a positive integer to find its square root: ");
            scanf("%f", &fnum1);
            while(fnum1 < 0) {
                printf("O unhappy dagger, square root of a negative number is not allowed.\n");
                printf("Please enter a positive number: ");
                scanf("%f", &fnum1);
            }
            result = sqrt(fnum1);
            printf("The square root is: %f", result);
            break;
        case 7:
            printf("O Romeo, please enter two integers to find their exponentiation: ");
            scanf("%d %d", &num1, &num2);
            result = pow(num1, num2);
            printf("The exponentiation is: %f", result);
            break;
        case 8:
            printf("O Romeo, please enter a positive integer to find its logarithm: ");
            scanf("%f", &fnum1);
            while(fnum1 <= 0) {
                printf("O unhappy dagger, logarithm of a non-positive number is not allowed.\n");
                printf("Please enter a positive number: ");
                scanf("%f", &fnum1);
            }
            result = log10(fnum1);
            printf("The logarithm is: %f", result);
            break;
        case 9:
            printf("O happy dagger, parting is such sweet sorrow.\n");
            break;
        default:
            printf("O unhappy dagger, that is not an option.\n");
    }
    
    return 0;
}