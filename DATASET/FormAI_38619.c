//FormAI DATASET v1.0 Category: Data validation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int userInput, minValue = 1, maxValue = 100;
    bool validInput = false;
    
    while (!validInput) {
        printf("Please enter an integer between %d and %d: ", minValue, maxValue);
        if (scanf("%d", &userInput) == 1) {
            if (userInput >= minValue && userInput <= maxValue) {
                validInput = true;
                printf("You entered a valid number: %d\n", userInput);
            } else {
                printf("Invalid input! Please try again.\n");
            }
        } else {
            printf("Invalid input! Please enter an integer.\n");
            fflush(stdin); // clear input buffer
        }
    }
    
    return 0;
}