//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: immersive
#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    double num1, num2, result;
    
    printf("Welcome to the scientific calculator!\n");
    printf("Please select an operation:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Power\n6. Square Root\n7. Sine\n8. Cosine\n9. Tangent\n10. Logarithm\n");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("Enter two numbers to add:\n");
            scanf("%lf %lf", &num1, &num2);
            result = num1 + num2;
            printf("Result: %lf", result);
            break;
        case 2:
            printf("Enter two numbers to subtract (subtract the second from the first):\n");
            scanf("%lf %lf", &num1, &num2);
            result = num1 - num2;
            printf("Result: %lf", result);
            break;
        case 3:
            printf("Enter two numbers to multiply:\n");
            scanf("%lf %lf", &num1, &num2);
            result = num1 * num2;
            printf("Result: %lf", result);
            break;
        case 4:
            printf("Enter two numbers to divide (divide the first by the second):\n");
            scanf("%lf %lf", &num1, &num2);
            if(num2 == 0) {
                printf("Error: Cannot divide by zero");
            }else {
                result = num1 / num2;
                printf("Result: %lf", result);
            }
            break;
        case 5:
            printf("Enter the base and the exponent:\n");
            scanf("%lf %lf", &num1, &num2);
            result = pow(num1, num2);
            printf("Result: %lf", result);
            break;
        case 6:
            printf("Enter a number to find the square root of:\n");
            scanf("%lf", &num1);
            if(num1 < 0) {
                printf("Error: Cannot find the square root of a negative number");
            }else {
                result = sqrt(num1);
                printf("Result: %lf", result);
            }
            break;
        case 7:
            printf("Enter an angle (in radians) to find the sine of:\n");
            scanf("%lf", &num1);
            result = sin(num1);
            printf("Result: %lf", result);
            break;
        case 8:
            printf("Enter an angle (in radians) to find the cosine of:\n");
            scanf("%lf", &num1);
            result = cos(num1);
            printf("Result: %lf", result);
            break;
        case 9:
            printf("Enter an angle (in radians) to find the tangent of:\n");
            scanf("%lf", &num1);
            result = tan(num1);
            printf("Result: %lf", result);
            break;
        case 10:
            printf("Enter a number to find the natural logarithm of:\n");
            scanf("%lf", &num1);
            if(num1 <= 0) {
                printf("Error: Cannot find the natural logarithm of a non-positive number");
            }else {
                result = log(num1);
                printf("Result: %lf", result);
            }
            break;
        default:
            printf("Invalid choice");
    }
    
    return 0;
}