//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: happy
#include<stdio.h>
#include<math.h>

// This program is a happy implementation of a scientific calculator in C

int main() {

    // Declare variables
    int choice;
    float num1, num2, result;

    // Display a welcome message
    printf("Welcome to my happy scientific calculator! Let's crunch some numbers!\n");

    do {
        // Display options to the user
        printf("\n\n1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Square root\n");
        printf("6. Cube root\n");
        printf("7. Power\n");
        printf("8. Modulus\n");
        printf("9. Exit\n\n");

        // Ask the user to select an option
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the selected operation
        switch(choice) {
            case 1:
                printf("\nEnter two numbers to add: ");
                scanf("%f %f", &num1, &num2);
                result = num1 + num2;
                printf("\n%.2f + %.2f = %.2f\n", num1, num2, result);
                break;
            case 2:
                printf("\nEnter two numbers to subtract: ");
                scanf("%f %f", &num1, &num2);
                result = num1 - num2;
                printf("\n%.2f - %.2f = %.2f\n", num1, num2, result);
                break;
            case 3:
                printf("\nEnter two numbers to multiply: ");
                scanf("%f %f", &num1, &num2);
                result = num1 * num2;
                printf("\n%.2f * %.2f = %.2f\n", num1, num2, result);
                break;
            case 4:
                printf("\nEnter two numbers to divide: ");
                scanf("%f %f", &num1, &num2);
                if(num2 == 0) {
                    printf("\nError! Cannot divide by zero!\n");
                } else {
                    result = num1 / num2;
                    printf("\n%.2f / %.2f = %.2f\n", num1, num2, result);
                }
                break;
            case 5:
                printf("\nEnter a number to find its square root: ");
                scanf("%f", &num1);
                result = sqrt(num1);
                printf("\nSquare root of %.2f = %.2f\n", num1, result);
                break;
            case 6:
                printf("\nEnter a number to find its cube root: ");
                scanf("%f", &num1);
                result = cbrt(num1);
                printf("\nCube root of %.2f = %.2f\n", num1, result);
                break;
            case 7:
                printf("\nEnter base and exponent: ");
                scanf("%f %f", &num1, &num2);
                result = pow(num1, num2);
                printf("\n%.2f ^ %.2f = %.2f\n", num1, num2, result);
                break;
            case 8:
                printf("\nEnter two numbers to find modulus: ");
                scanf("%f %f", &num1, &num2);
                result = fmod(num1, num2);
                printf("\n%.2f %% %.2f = %.2f\n", num1, num2, result);
                break;
            case 9:
                printf("\nThank you for using my happy scientific calculator!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    } while(choice != 9);

    return 0;
}