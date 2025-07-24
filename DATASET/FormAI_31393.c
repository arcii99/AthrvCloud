//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: scalable
#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    float num1, num2, result, angle;
    
    printf("Welcome to the Scientific Calculator!\n");
    
    while(1) {
        printf("Select an operation:\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Sine (sin)\n");
        printf("6. Cosine (cos)\n");
        printf("7. Tangent (tan)\n");
        printf("8. Square root (sqrt)\n");
        printf("9. Exponent (pow)\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        
        if(choice == 10) {
            printf("Thank you for using the Scientific Calculator!\n");
            break;
        }
        
        switch(choice) {
            case 1:
                printf("Enter the first number: ");
                scanf("%f", &num1);
                printf("Enter the second number: ");
                scanf("%f", &num2);
                result = num1 + num2;
                printf("Result: %.2f\n", result);
                break;
            case 2:
                printf("Enter the first number: ");
                scanf("%f", &num1);
                printf("Enter the second number: ");
                scanf("%f", &num2);
                result = num1 - num2;
                printf("Result: %.2f\n", result);
                break;
            case 3:
                printf("Enter the first number: ");
                scanf("%f", &num1);
                printf("Enter the second number: ");
                scanf("%f", &num2);
                result = num1 * num2;
                printf("Result: %.2f\n", result);
                break;
            case 4:
                printf("Enter the first number: ");
                scanf("%f", &num1);
                printf("Enter the second number: ");
                scanf("%f", &num2);
                result = num1 / num2;
                printf("Result: %.2f\n", result);
                break;
            case 5:
                printf("Enter the angle in degrees: ");
                scanf("%f", &angle);
                result = sin(angle * M_PI / 180.0);
                printf("Result: %.2f\n", result);
                break;
            case 6:
                printf("Enter the angle in degrees: ");
                scanf("%f", &angle);
                result = cos(angle * M_PI / 180.0);
                printf("Result: %.2f\n", result);
                break;
            case 7:
                printf("Enter the angle in degrees: ");
                scanf("%f", &angle);
                result = tan(angle * M_PI / 180.0);
                printf("Result: %.2f\n", result);
                break;
            case 8:
                printf("Enter the number: ");
                scanf("%f", &num1);
                result = sqrt(num1);
                printf("Result: %.2f\n", result);
                break;
            case 9:
                printf("Enter the base: ");
                scanf("%f", &num1);
                printf("Enter the exponent: ");
                scanf("%f", &num2);
                result = pow(num1, num2);
                printf("Result: %.2f\n", result);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}