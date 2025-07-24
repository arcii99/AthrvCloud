//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: optimized
#include <stdio.h>
#include <math.h>

int main() {
    int option;
    double num1, num2, result;
    
    printf("Welcome to Scientific Calculator\n");
    printf("Please select an option from the following:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square root\n");
    printf("7. Logarithmic\n");
    printf("8. Trigonometric\n");
    printf("9. Exit\n");
    
    do {
        printf("\nEnter your option: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                printf("Enter two numbers to add: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 + num2;
                printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 2:
                printf("Enter two numbers to subtract: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 - num2;
                printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 3:
                printf("Enter two numbers to multiply: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 * num2;
                printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 4:
                printf("Enter two numbers to divide: ");
                scanf("%lf %lf", &num1, &num2);
                if(num2 == 0) {
                    printf("Error! Division by zero.\n");
                    break;
                }
                result = num1 / num2;
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 5:
                printf("Enter the number and its power: ");
                scanf("%lf %lf", &num1, &num2);
                result = pow(num1, num2);
                printf("%.2lf ^ %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 6:
                printf("Enter a number to find its square root: ");
                scanf("%lf", &num1);
                if(num1 < 0) {
                    printf("Error! Square root of negative number.\n");
                    break;
                }
                result = sqrt(num1);
                printf("Square root of %.2lf is %.2lf\n", num1, result);
                break;
            case 7:
                printf("Enter a number to find its logarithm to base 10: ");
                scanf("%lf", &num1);
                if(num1 <= 0) {
                    printf("Error! Logarithm of non-positive number.\n");
                    break;
                }
                result = log10(num1);
                printf("Logarithm of %.2lf to base 10 is %.2lf\n", num1, result);
                break;
            case 8:
                printf("Enter the angle in degrees: ");
                scanf("%lf", &num1);
                result = sin(num1 * M_PI / 180);
                printf("Sine of %.2lf degrees is %.2lf\n", num1, result);
                result = cos(num1 * M_PI / 180);
                printf("Cosine of %.2lf degrees is %.2lf\n", num1, result);
                break;
            case 9:
                printf("Thank you for using Scientific Calculator.\n");
                break;
            default:
                printf("Error! Invalid option selected.\n");
                break;
        }
    } while(option != 9);
    
    return 0;
}