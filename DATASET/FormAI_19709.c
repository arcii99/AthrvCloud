//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    char operation; // variable to hold user's chosen operation
    double num1, num2, result;

    printf("Welcome to My Scientific Calculator!\n\n");
    printf("Available operations are: \n");
    printf(" + (Addition), - (Subtraction), x (Multiplication), / (Division) \n");
    printf(" s (Sin), c (Cos), t (Tan), r (Square Root), ^ (Power) \n\n");

    printf("Enter the first number: ");
    scanf("%lf", &num1);

    printf("Enter the operation you wish to perform: ");
    scanf(" %c", &operation);

    // perform appropriate operation based on user input
    switch (operation) {
        case '+':
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            result = num1 + num2;
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '-':
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            result = num1 - num2;
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;
        case 'x':
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            result = num1 * num2;
            printf("%.2lf x %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '/':
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            if(num2 == 0) {
                printf("Error: Division by zero\n");
            }
            else {
                result = num1 / num2;
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
            }
            break;
        case 's':
            result = sin(num1 * PI / 180.0); // convert degrees to radians
            printf("Sin(%.2lf) = %.2lf\n", num1, result);
            break;
        case 'c':
            result = cos(num1 * PI / 180.0); // convert degrees to radians
            printf("Cos(%.2lf) = %.2lf\n", num1, result);
            break;
        case 't':
            result = tan(num1 * PI / 180.0); // convert degrees to radians
            printf("Tan(%.2lf) = %.2lf\n", num1, result);
            break;
        case 'r':
            if(num1 < 0) {
                printf("Error: Square Root of a negative number\n");
            }
            else {
                result = sqrt(num1);
                printf("Sqrt(%.2lf) = %.2lf\n", num1, result);
            }
            break;
        case '^':
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            result = pow(num1, num2);
            printf("%.2lf to the power of %.2lf = %.2lf\n", num1, num2, result);
            break;
        default:
            printf("Error: Invalid operation\n");
    }

    return 0;
}