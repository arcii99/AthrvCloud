//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float a, b, c, result;
    int choice;

    printf("Welcome to the Scientific Calculator\n");
    printf("----------------------------------\n");

    while(1) {
        printf("\nPlease select an operation:\n");
        printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Square\n6. Square Root\n7. Power\n8. Sine\n9. Cosine\n10. Tangent\n11. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%f %f", &a, &b);
                result = a + b;
                printf("%.2f + %.2f = %.2f\n", a, b, result);
                break;

            case 2:
                printf("Enter two numbers: ");
                scanf("%f %f", &a, &b);
                result = a - b;
                printf("%.2f - %.2f = %.2f\n", a, b, result);
                break;

            case 3:
                printf("Enter two numbers: ");
                scanf("%f %f", &a, &b);
                result = a * b;
                printf("%.2f * %.2f = %.2f\n", a, b, result);
                break;

            case 4:
                printf("Enter two numbers: ");
                scanf("%f %f", &a, &b);
                if(b == 0) {
                    printf("Error: Division by zero not possible\n");
                    break;
                }
                result = a / b;
                printf("%.2f / %.2f = %.2f\n", a, b, result);
                break;

            case 5:
                printf("Enter a number: ");
                scanf("%f", &a);
                result = pow(a, 2);
                printf("%.2f^2 = %.2f\n", a, result);
                break;

            case 6:
                printf("Enter a number: ");
                scanf("%f", &a);
                result = sqrt(a);
                printf("Square root of %.2f = %.2f\n", a, result);
                break;

            case 7:
                printf("Enter two numbers: ");
                scanf("%f %f", &a, &b);
                result = pow(a, b);
                printf("%.2f^%.2f = %.2f\n", a, b, result);
                break;

            case 8:
                printf("Enter a number in radians: ");
                scanf("%f", &a);
                result = sin(a);
                printf("sin(%.2f) = %.2f\n", a, result);
                break;

            case 9:
                printf("Enter a number in radians: ");
                scanf("%f", &a);
                result = cos(a);
                printf("cos(%.2f) = %.2f\n", a, result);
                break;

            case 10:
                printf("Enter a number in radians: ");
                scanf("%f", &a);
                result = tan(a);
                printf("tan(%.2f) = %.2f\n", a, result);
                break;

            case 11:
                printf("Thank you for using the Scientific Calculator\n");
                exit(0);

            default:
                printf("Error: Invalid choice\n");
        }
    }

    return 0;
}