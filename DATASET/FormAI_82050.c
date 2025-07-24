//FormAI DATASET v1.0 Category: Arithmetic ; Style: high level of detail
#include <stdio.h>

int main() {
    float num1, num2, result;
    int choice;

    printf("Enter the first number: ");
    scanf("%f", &num1);

    printf("Enter the second number: ");
    scanf("%f", &num2);

    printf("\nSelect the operation you want to perform:");
    printf("\n1. Addition (+)");
    printf("\n2. Subtraction (-)");
    printf("\n3. Multiplication (*)");
    printf("\n4. Division (/)");
    printf("\nEnter your choice (1-4): ");
    scanf("%d", &choice);

    if (choice == 1) {
        result = num1 + num2;
        printf("%.2f + %.2f = %.2f\n", num1, num2, result); 
    }
    else if (choice == 2) {
        result = num1 - num2;
        printf("%.2f - %.2f = %.2f\n", num1, num2, result); 
    }
    else if (choice == 3) {
        result = num1 * num2;
        printf("%.2f * %.2f = %.2f\n", num1, num2, result); 
    }
    else if (choice == 4) {
        if (num2 == 0) {
            printf("Error: Division by zero\n");
        }
        else {
            result = num1 / num2;
            printf("%.2f / %.2f = %.2f\n", num1, num2, result); 
        }
    }
    else {
        printf("Invalid choice\n");
    }

    return 0;
}