//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multivariable
#include <stdio.h>
#include <math.h>

int main() {
    int choice, num1, num2; // variables to store user input and operands
    
    printf("Welcome to the scientific calculator!\n");
    printf("Please select an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Sine\n");
    printf("6. Cosine\n");
    printf("7. Tangent\n");
    printf("8. Square root\n");
    printf("Enter your choice (1-8): ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1: // addition
            printf("Please enter the first number: ");
            scanf("%d", &num1);
            printf("Please enter the second number: ");
            scanf("%d", &num2);
            printf("%d + %d = %d\n", num1, num2, num1 + num2);
            break;
        case 2: // subtraction
            printf("Please enter the first number: ");
            scanf("%d", &num1);
            printf("Please enter the second number: ");
            scanf("%d", &num2);
            printf("%d - %d = %d\n", num1, num2, num1 - num2);
            break;
        case 3: // multiplication
            printf("Please enter the first number: ");
            scanf("%d", &num1);
            printf("Please enter the second number: ");
            scanf("%d", &num2);
            printf("%d * %d = %d\n", num1, num2, num1 * num2);
            break;
        case 4: // division
            printf("Please enter the first number: ");
            scanf("%d", &num1);
            printf("Please enter the second number: ");
            scanf("%d", &num2);
            if(num2 == 0) {
                printf("Error: Cannot divide by zero\n");
            } else {
                printf("%d / %d = %d\n", num1, num2, num1 / num2);
            }
            break;
        case 5: // sine
            printf("Please enter the angle in degrees: ");
            scanf("%d", &num1);
            printf("sin(%d) = %f\n", num1, sin(num1 * M_PI / 180));
            break;
        case 6: // cosine
            printf("Please enter the angle in degrees: ");
            scanf("%d", &num1);
            printf("cos(%d) = %f\n", num1, cos(num1 * M_PI / 180));
            break;
        case 7: // tangent
            printf("Please enter the angle in degrees: ");
            scanf("%d", &num1);
            printf("tan(%d) = %f\n", num1, tan(num1 * M_PI / 180));
            break;
        case 8: // square root
            printf("Please enter a positive number: ");
            scanf("%d", &num1);
            if(num1 < 0) {
                printf("Error: Cannot find square root of a negative number\n");
            } else {
                printf("sqrt(%d) = %f\n", num1, sqrt(num1));
            }
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    
    return 0;
}