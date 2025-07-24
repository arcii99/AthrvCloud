//FormAI DATASET v1.0 Category: Calculator ; Style: peaceful
#include <stdio.h>

// Function to add two numbers
int add(int num1, int num2) {
    return num1 + num2;
}

// Function to subtract two numbers
int subtract(int num1, int num2) {
    return num1 - num2;
}

// Function to multiply two numbers
int multiply(int num1, int num2) {
    return num1 * num2;
}

// Function to divide two numbers
int divide(int num1, int num2) {
    return num1 / num2;
}

// Main function
int main() {
    int num1, num2, choice, result;
    
    printf("Welcome to the peaceful calculator program!\n");
    
    while(1) {
        // Display the menu
        printf("\n------MENU------\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        // Get the user's choice
        scanf("%d", &choice);
        
        if(choice == 5) {
            printf("Thanks for using the peaceful calculator program!\n");
            return 0;
        }
        
        // Get the two numbers from the user
        printf("Enter the first number: ");
        scanf("%d", &num1);
        
        printf("Enter the second number: ");
        scanf("%d", &num2);
        
        // Calculate the result based on the user's choice
        switch(choice) {
            case 1:
                result = add(num1, num2);
                printf("The sum of %d and %d is %d\n", num1, num2, result);
                break;
            case 2:
                result = subtract(num1, num2);
                printf("The difference between %d and %d is %d\n", num1, num2, result);
                break;
            case 3:
                result = multiply(num1, num2);
                printf("The product of %d and %d is %d\n", num1, num2, result);
                break;
            case 4:
                result = divide(num1, num2);
                printf("The quotient of %d and %d is %d\n", num1, num2, result);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}