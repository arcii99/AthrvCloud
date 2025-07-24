//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: realistic
#include <stdio.h>
#include <math.h>

int main() {
    int choice, a, b;
    float result;

    printf("Welcome to My Calculator!\n\n");

    do {
        printf("Choose an operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("6. Square root\n");
        printf("7. Power\n");
        printf("8. Absolute value\n");
        printf("9. Trigonometric functions\n");
        printf("10. Logarithmic functions\n");
        printf("0. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter two numbers to add: ");
                scanf("%d%d", &a, &b);
                result = a + b;
                printf("Result: %.2f\n\n", result);
                break;
            case 2:
                printf("Enter two numbers to subtract (first - second): ");
                scanf("%d%d", &a, &b);
                result = a - b;
                printf("Result: %.2f\n\n", result);
                break;
            case 3:
                printf("Enter two numbers to multiply: ");
                scanf("%d%d", &a, &b);
                result = a * b;
                printf("Result: %.2f\n\n", result);
                break;
            case 4:
                printf("Enter two numbers to divide (numerator/denominator): ");
                scanf("%d%d", &a, &b);
                if(b == 0) {
                    printf("Error: division by zero!\n\n");
                    break;
                }
                result = (float)a / b;
                printf("Result: %.2f\n\n", result);
                break;
            case 5:
                printf("Enter two numbers to find modulus (numerator%denominator): ");
                scanf("%d%d", &a, &b);
                if(b == 0) {
                    printf("Error: division by zero!\n\n");
                    break;
                }
                result = a % b;
                printf("Result: %.2f\n\n", result);
                break;
            case 6:
                printf("Enter a number to find its square root: ");
                scanf("%d", &a);
                if(a < 0) {
                    printf("Error: cannot find square root of negative number!\n\n");
                    break;
                }
                result = sqrt(a);
                printf("Result: %.2f\n\n", result);
                break;
            case 7:
                printf("Enter a number and its exponent: ");
                scanf("%d%d", &a, &b);
                result = pow(a, b);
                printf("Result: %.2f\n\n", result);
                break;
            case 8:
                printf("Enter a number to find its absolute value: ");
                scanf("%d", &a);
                result = abs(a);
                printf("Result: %.2f\n\n", result);
                break;
            case 9:
                printf("Choose the trigonometric function:\n");
                printf("1. Sine\n");
                printf("2. Cosine\n");
                printf("3. Tangent\n");
                printf("4. Cosecant\n");
                printf("5. Secant\n");
                printf("6. Cotangent\n\n");

                printf("Enter your choice: ");
                scanf("%d", &choice);

                printf("Enter the angle in degrees: ");
                scanf("%d", &a);
                if(choice == 1) {
                    result = sin((a * 3.14159) / 180.0);
                } else if(choice == 2) {
                    result = cos((a * 3.14159) / 180.0);
                } else if(choice == 3) {
                    result = tan((a * 3.14159) / 180.0);
                } else if(choice == 4) {
                    result = 1 / sin((a * 3.14159) / 180.0);
                } else if(choice == 5) {
                    result = 1 / cos((a * 3.14159) / 180.0);
                } else if(choice == 6) {
                    result = 1 / tan((a * 3.14159) / 180.0);
                } else {
                    printf("Error: invalid choice!\n\n");
                    break;
                }

                printf("Result: %.2f\n\n", result);
                break;
            case 10:
                printf("Choose the logarithmic function:\n");
                printf("1. Natural logarithm\n");
                printf("2. Logarithm base 10\n");
                printf("3. Logarithm base b\n\n");

                printf("Enter your choice: ");
                scanf("%d", &choice);

                printf("Enter the number: ");
                scanf("%d", &a);
                if(a <= 0) {
                    printf("Error: cannot find logarithm of non-positive number!\n\n");
                    break;
                }

                if(choice == 1) {
                    result = log(a);
                } else if(choice == 2) {
                    result = log10(a);
                } else if(choice == 3) {
                    printf("Enter the base: ");
                    scanf("%d", &b);
                    if(b <= 0 || b == 1) {
                        printf("Error: invalid base!\n\n");
                        break;
                    }
                    result = log(a) / log(b);
                } else {
                    printf("Error: invalid choice!\n\n");
                    break;
                }

                printf("Result: %.2f\n\n", result);
                break;
            case 0:
                printf("Thank you for using My Calculator!\n");
                break;
            default:
                printf("Error: invalid choice!\n\n");
                break;
        }
    } while(choice != 0);

    return 0;
}