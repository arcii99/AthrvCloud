//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: excited
#include <stdio.h>
#include <math.h>

int main() {

    printf("Welcome to the coolest scientific calculator ever! Let's get started!\n");

    float num1, num2, result;
    int choice;

    printf("\nEnter the first number: ");
    scanf("%f", &num1);
    
    printf("\nEnter the operation that you want to perform:\n1. Addition(+)\n2. Subtraction(-)\n3. Multiplication(*)\n4. Division(/)\n5. Modulus(%%)\n6. Square root\n7. Cube root\n8. Power\n9. Log base 10\n10. Log base e\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nEnter the second number: ");
            scanf("%f", &num2);
            result = num1 + num2;
            printf("\nThe sum of %.2f and %.2f is: %.2f", num1, num2, result);
            break;
        
        case 2:
            printf("\nEnter the second number: ");
            scanf("%f", &num2);
            result = num1 - num2;
            printf("\nThe difference between %.2f and %.2f is: %.2f", num1, num2, result);
            break;

        case 3:
            printf("\nEnter the second number: ");
            scanf("%f", &num2);
            result = num1 * num2;
            printf("\nThe product of %.2f and %.2f is: %.2f", num1, num2, result);
            break;

        case 4:
            printf("\nEnter the second number: ");
            scanf("%f", &num2);
            if (num2 == 0) {
                printf("Error: Cannot divide by zero");
            } else {
                result = num1 / num2;
                printf("\nThe quotient of %.2f and %.2f is: %.2f", num1, num2, result);
            }
            break;

        case 5:
            printf("\nEnter the second number: ");
            scanf("%f", &num2);
            if (num2 == 0) {
                printf("Error: Cannot divide by zero");
            } else {
                result = (int)num1 % (int)num2; // typecasting from float to int
                printf("\nThe remainder of %.2f when divided by %.2f is: %.2f", num1, num2, result);
            }
            break;

        case 6:
            result = sqrt(num1);
            printf("\nThe square root of %.2f is: %.2f", num1, result);
            break;

        case 7:
            result = cbrt(num1); // cbrt() is a function in math.h that returns cube root
            printf("\nThe cube root of %.2f is: %.2f", num1, result);
            break;

        case 8:
            printf("\nEnter the exponent: ");
            scanf("%f", &num2);
            result = pow(num1, num2);
            printf("\n%.2f raised to the power of %.2f is: %.2f", num1, num2, result);
            break;

        case 9:
            result = log10(num1);
            printf("\nThe log of %.2f to base 10 is: %.2f", num1, result);
            break;

        case 10:
            result = log(num1);
            printf("\nThe natural logarithm of %.2f is: %.2f", num1, result);
            break;

        default:
            printf("\nInvalid choice! Please choose from 1-10.");
            break;
    }
    printf("\n\nThank you for using the coolest scientific calculator ever! Have a great day! :)");

    return 0;
}