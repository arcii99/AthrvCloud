//FormAI DATASET v1.0 Category: Math exercise ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to generate random numbers
int random_number(int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main() {
    int num1, num2, choice, ans;
    
    // Seed for random number generation
    srand(time(0));
    
    // Loop to keep the program running
    while(1) {
        printf("\nChoose a math operation from the following:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Square Root\n");
        printf("6. Power\n");
        printf("7. Exit\n");
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        // Exit if user chooses 7
        if (choice == 7) {
            break;
        }
        
        // Generate random numbers for addition, subtraction and multiplication
        num1 = random_number(1, 100);
        num2 = random_number(1, 100);
        
        switch(choice) {
            case 1: // Addition
                printf("\n%d + %d = ", num1, num2);
                scanf("%d", &ans);
                if (ans == num1 + num2) {
                    printf("Correct!\n");
                } else {
                    printf("Incorrect, the answer is %d\n", num1 + num2);
                }
                break;
                
            case 2: // Subtraction
                printf("\n%d - %d = ", num1, num2);
                scanf("%d", &ans);
                if (ans == num1 - num2) {
                    printf("Correct!\n");
                } else {
                    printf("Incorrect, the answer is %d\n", num1 - num2);
                }
                break;
                
            case 3: // Multiplication
                printf("\n%d * %d = ", num1, num2);
                scanf("%d", &ans);
                if (ans == num1 * num2) {
                    printf("Correct!\n");
                } else {
                    printf("Incorrect, the answer is %d\n", num1 * num2);
                }
                break;
                
            case 4: // Division
                printf("\n%d / %d = ", num1 * num2, num2);
                scanf("%d", &ans);
                if (ans == num1) {
                    printf("Correct!\n");
                } else {
                    printf("Incorrect, the answer is %d\n", num1);
                }
                break;
                
            case 5: // Square Root
                printf("\nSquare root of %d = ", num1 * num2);
                scanf("%d", &ans);
                if (ans == sqrt(num1 * num2)) {
                    printf("Correct!\n");
                } else {
                    printf("Incorrect, the answer is %f\n", sqrt(num1 * num2));
                }
                break;
                
            case 6: // Power
                printf("\n%d raised to the power of %d = ", num1, num2);
                scanf("%d", &ans);
                if (ans == pow(num1, num2)) {
                    printf("Correct!\n");
                } else {
                    printf("Incorrect, the answer is %f\n", pow(num1, num2));
                }
                break;
                
            default: // Invalid choice
                printf("\nPlease enter a valid choice.\n");
        }
    }
    
    return 0;
}