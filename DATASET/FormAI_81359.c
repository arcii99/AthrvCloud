//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: scientific
/* This is a scientific calculator implementation program written in C.
 * It can perform various mathematical operations like addition, subtraction,
 * multiplication, division, power, square root, logarithm etc.
 * This program uses switch-case statements and various functions to 
 * perform the desired operation.
 * This program also has proper error handling to avoid program crashes
 * and prevent undefined behavior.
 */

#include <stdio.h>
#include <math.h>

int main () {
    int choice;
    float num1, num2;

    printf("Welcome to the C Scientific Calculator!\n\n");
    
    // Display the menu options
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("7. Natural Logarithm\n");
    printf("8. Logarithm Base 10\n");
    printf("9. Exit\n\n");
    
    // Get the user's choice
    printf("Please enter your choice: ");
    scanf("%d", &choice);

    // Switch case statement to perform the desired operation
    switch (choice) {
        case 1:
            printf("Enter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);
            printf("%.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
            break;
            
        case 2:
            printf("Enter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);
            printf("%.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
            break;
            
        case 3:
            printf("Enter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);
            printf("%.2f x %.2f = %.2f\n", num1, num2, num1 * num2);
            break;
            
        case 4:
            printf("Enter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);
            if (num2 == 0) {
                printf("Error: Division by zero!\n");
            } else {
                printf("%.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
            }
            break;
            
        case 5:
            printf("Enter the base number: ");
            scanf("%f", &num1);
            printf("Enter the power: ");
            scanf("%f", &num2);
            printf("%.2f ^ %.2f = %.2f\n", num1, num2, pow(num1, num2));
            break;
            
        case 6:
            printf("Enter the number: ");
            scanf("%f", &num1);
            if (num1 < 0) {
                printf("Error: Cannot calculate square root of a negative number!\n");
            } else {
                printf("The square root of %.2f is %.2f\n", num1, sqrt(num1));
            }
            break;
            
        case 7:
            printf("Enter the number: ");
            scanf("%f", &num1);
            if (num1 <= 0) {
                printf("Error: Cannot calculate natural logarithm of a non-positive number!\n");
            } else {
                printf("The natural logarithm of %.2f is %.2f\n", num1, log(num1));
            }
            break;
            
        case 8:
            printf("Enter the number: ");
            scanf("%f", &num1);
            if (num1 <= 0) {
                printf("Error: Cannot calculate logarithm base 10 of a non-positive number!\n");
            } else {
                printf("The logarithm base 10 of %.2f is %.2f\n", num1, log10(num1));
            }
            break;
            
        case 9:
            printf("Thank you for using the C Scientific Calculator!\n");
            break;
            
        default:
            printf("Error: Invalid choice!\n");
            break;
    }

    return 0;
}