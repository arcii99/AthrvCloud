//FormAI DATASET v1.0 Category: Error handling ; Style: Romeo and Juliet
// A Romeo and Juliet-inspired C Error Handling Program

#include <stdio.h>
#include <stdlib.h>

// Function to check if the input number is valid
int validateNumber(int num) {
    if (num <= 0) {
        printf("Oh cruel fate! Your number must be positive and nonzero. \n");
        return -1; // Error code -1 for invalid number
    }
    else if (num >= 100) {
        printf("Alas! Your number must be less than 100. \n");
        return -2; // Error code -2 for number too big
    }
    else {
        return 0; // Number is valid
    }
}

// Main function
int main() {
    int romanticNumber;

    printf("My love, please enter a number for us: ");
    scanf("%d", &romanticNumber);

    // Check if input is valid, otherwise exit program with error message
    int validationStatus = validateNumber(romanticNumber);
    if (validationStatus == -1) {
        printf("Goodbye dear, my heart is heavy. \n");
        exit(1); // Exit program with error code 1 for invalid input
    }
    else if (validationStatus == -2) {
        printf("This love is not meant to be, farewell. \n");
        exit(2); // Exit program with error code 2 for number too big
    }

    // All validation checks passed, continue with program
    printf("Oh joyous news, our number %d is perfect! \n", romanticNumber);
    return 0;
}