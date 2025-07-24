//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: shape shifting
#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    float num1, num2, result, temp;
    
    printf("Welcome to the Shape-Shifting Scientific Calculator!\n");
    printf("Select an option:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Square Root\n");
    printf("6. Power\n");
    printf("7. Logarithm\n");
    printf("8. Trigonometry (Sine)\n");
    printf("9. Trigonometry (Cosine)\n");
    printf("10. Trigonometry (Tangent)\n");
    
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("Enter two numbers to add: ");
            scanf("%f %f", &num1, &num2);
            result = num1 + num2;
            printf("The sum is: %f\n", result);
            break;
        case 2:
            printf("Enter two numbers to subtract: ");
            scanf("%f %f", &num1, &num2);
            result = num1 - num2;
            printf("The difference is: %f\n", result);
            break;
        case 3:
            printf("Enter two numbers to multiply: ");
            scanf("%f %f", &num1, &num2);
            result = num1 * num2;
            printf("The product is: %f\n", result);
            break;
        case 4:
            printf("Enter two numbers to divide: ");
            scanf("%f %f", &num1, &num2);
            result = num1 / num2;
            printf("The quotient is: %f\n", result);
            break;
        case 5:
            printf("Enter a number to find its square root: ");
            scanf("%f", &num1);
            result = sqrt(num1);
            printf("The square root is: %f\n", result);
            break;
        case 6:
            printf("Enter a number and its power: ");
            scanf("%f %f", &num1, &num2);
            result = pow(num1, num2);
            printf("%f raised to %f is equal to: %f\n", num1, num2, result);
            break;
        case 7:
            printf("Enter a number: ");
            scanf("%f", &num1);
            result = log(num1);
            printf("The natural logarithm is: %f\n", result);
            break;
        case 8:
            printf("Enter an angle in degrees to find its sine: ");
            scanf("%f", &num1);
            temp = num1 * M_PI / 180;
            result = sin(temp);
            printf("The sine of %f degrees is: %f\n", num1, result);
            break;
        case 9:
            printf("Enter an angle in degrees to find its cosine: ");
            scanf("%f", &num1);
            temp = num1 * M_PI / 180;
            result = cos(temp);
            printf("The cosine of %f degrees is: %f\n", num1, result);
            break;
        case 10:
            printf("Enter an angle in degrees to find its tangent: ");
            scanf("%f", &num1);
            temp = num1 * M_PI / 180;
            result = tan(temp);
            printf("The tangent of %f degrees is: %f\n", num1, result);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}