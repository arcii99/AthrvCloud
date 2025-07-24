//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double num_1, num_2, result;
    int choice, rad_or_deg;
    
    printf("Welcome to my Scientific Calculator Program\n\n");
    
    printf("Please select an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exponentiation\n");
    printf("6. Square Root\n");
    printf("7. Sine Function\n");
    printf("8. Cosine Function\n");
    printf("9. Tangent Function\n");
    printf("10. Inverse Sine Function\n");
    printf("11. Inverse Cosine Function\n");
    printf("12. Inverse Tangent Function\n");
    
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("\nEnter two numbers to add: ");
            scanf("%lf %lf", &num_1, &num_2);
            result = num_1 + num_2;
            printf("%.2lf + %.2lf = %.2lf\n", num_1, num_2, result);
            break;
        case 2:
            printf("\nEnter two numbers to subtract: ");
            scanf("%lf %lf", &num_1, &num_2);
            result = num_1 - num_2;
            printf("%.2lf - %.2lf = %.2lf\n", num_1, num_2, result);
            break;
        case 3:
            printf("\nEnter two numbers to multiply: ");
            scanf("%lf %lf", &num_1, &num_2);
            result = num_1 * num_2;
            printf("%.2lf * %.2lf = %.2lf\n", num_1, num_2, result);
            break;
        case 4:
            printf("\nEnter two numbers to divide: ");
            scanf("%lf %lf", &num_1, &num_2);
            if(num_2 == 0) {
                printf("Error: cannot divide by zero\n");
                return 1;
            }
            result = num_1 / num_2;
            printf("%.2lf / %.2lf = %.2lf\n", num_1, num_2, result);
            break;
        case 5:
            printf("\nEnter two numbers to calculate exponentiation: ");
            scanf("%lf %lf", &num_1, &num_2);
            result = pow(num_1, num_2);
            printf("%.2lf ^ %.2lf = %.2lf\n", num_1, num_2, result);
            break;
        case 6:
            printf("\nEnter a number to calculate the square root: ");
            scanf("%lf", &num_1);
            if(num_1 < 0) {
                printf("Error: cannot take square root of a negative number\n");
                return 1;
            }
            result = sqrt(num_1);
            printf("sqrt(%.2lf) = %.2lf\n", num_1, result);
            break;
        case 7:
            printf("\nEnter an angle in degrees/radians to calculate sin: ");
            scanf("%lf", &num_1);
            printf("\nDo you want the result in radians or degrees?\n");
            printf("1. Radians\n");
            printf("2. Degrees\n");
            printf("\nEnter your choice: ");
            scanf("%d", &rad_or_deg);
            if(rad_or_deg == 1) {
                result = sin(num_1);
                 printf("sin(%.2lf) = %.2lf rad\n", num_1, result);
            }
            else if(rad_or_deg == 2) {
                result = sin(num_1 * (M_PI / 180));
                printf("sin(%.2lf) = %.2lf deg\n", num_1, result);
            }
            else {
                printf("Error: invalid input\n");
                return 1;
            }
            break;
        case 8:
            printf("\nEnter an angle in degrees/radians to calculate cos: ");
            scanf("%lf", &num_1);
            printf("\nDo you want the result in radians or degrees?\n");
            printf("1. Radians\n");
            printf("2. Degrees\n");
            printf("\nEnter your choice: ");
            scanf("%d", &rad_or_deg);
            if(rad_or_deg == 1) {
                result = cos(num_1);
                printf("cos(%.2lf) = %.2lf rad\n", num_1, result);
            }
            else if(rad_or_deg == 2) {
                result = cos(num_1 * (M_PI / 180));
                printf("cos(%.2lf) = %.2lf deg\n", num_1, result);
            }
            else {
                printf("Error: invalid input\n");
                return 1;
            }
            break;
        case 9:
            printf("\nEnter an angle in degrees/radians to calculate tan: ");
            scanf("%lf", &num_1);
            printf("\nDo you want the result in radians or degrees?\n");
            printf("1. Radians\n");
            printf("2. Degrees\n");
            printf("\nEnter your choice: ");
            scanf("%d", &rad_or_deg);
            if(rad_or_deg == 1) {
                result = tan(num_1);
                printf("tan(%.2lf) = %.2lf rad\n", num_1, result);
            }
            else if(rad_or_deg == 2) {
                result = tan(num_1 * (M_PI / 180));
                printf("tan(%.2lf) = %.2lf deg\n", num_1, result);
            }
            else {
                printf("Error: invalid input\n");
                return 1;
            }
            break;
        case 10:
            printf("\nEnter a ratio value to calculate inverse sin: ");
            scanf("%lf", &num_1);
            if(num_1 < -1 || num_1 > 1) {
                printf("Error: invalid input. Value must be between -1 and 1\n");
                return 1;
            }
            result = asin(num_1);
            printf("sin^-1(%.2lf) = %.2lf rad\n", num_1, result);
            break;
        case 11:
            printf("\nEnter a ratio value to calculate inverse cos: ");
            scanf("%lf", &num_1);
            if(num_1 < -1 || num_1 > 1) {
                printf("Error: invalid input. Value must be between -1 and 1\n");
                return 1;
            }
            result = acos(num_1);
            printf("cos^-1(%.2lf) = %.2lf rad\n", num_1, result);
            break;
        case 12:
            printf("\nEnter a ratio value to calculate inverse tan: ");
            scanf("%lf", &num_1);
            result = atan(num_1);
            printf("tan^-1(%.2lf) = %.2lf rad\n", num_1, result);
            break;
        default:
            printf("Error: invalid input\n");
            break;
    }
    
    return 0;
}