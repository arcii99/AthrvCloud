//FormAI DATASET v1.0 Category: Math exercise ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int num1 = rand() % 100; // generate random number between 0-99
    int num2 = rand() % 100; // generate random number between 0-99
    
    int sum, prod, diff, quotient, modulus;
    printf("Welcome to the math game!\n");
    printf("Find the following of the two numbers: %d and %d\n", num1, num2);
    printf("1. Sum\n2. Product\n3. Difference\n4. Quotient\n5. Modulus\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    printf("\n");

    switch (choice) {
        case 1:
            sum = num1 + num2;
            printf("Sum of %d and %d is: %d\n", num1, num2, sum);
            break;
        case 2:
            prod = num1 * num2;
            printf("Product of %d and %d is: %d\n", num1, num2, prod);
            break;
        case 3:
            diff = num1 - num2;
            printf("Difference of %d and %d is: %d\n", num1, num2, diff);
            break;
        case 4:
            quotient = num1 / num2;
            printf("Quotient of %d and %d is: %d\n", num1, num2, quotient);
            break;
        case 5:
            modulus = num1 % num2;
            printf("Modulus of %d and %d is: %d\n", num1, num2, modulus);
            break;
        default:
            printf("Invalid choice!\n");
    }

    printf("Thank you for playing!\n");

    return 0;
}