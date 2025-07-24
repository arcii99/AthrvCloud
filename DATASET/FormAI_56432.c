//FormAI DATASET v1.0 Category: Error handling ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Initialize random seed
    srand(time(NULL));

    // Generate a random number between 0 and 9
    int randomNumber = rand() % 10;

    // Simulate an error occurring
    if (randomNumber > 5) {
        char* errorMessage = "Error: Could not open file.";
        printf("%s\n", errorMessage);
        exit(1);
    }

    // If no error occurs, continue executing program
    int numerator = 10;
    int denominator, result;

    // Prompt user for input
    printf("Enter a denominator: ");
    scanf("%d", &denominator);

    // Handle divide by zero error
    if (denominator == 0) {
        char* errorMessage = "Error: Divide by zero.";
        printf("%s\n", errorMessage);
        exit(1);
    }

    // Perform division
    result = numerator / denominator;

    // Print result
    printf("Result: %d\n", result);

    // Success!
    printf("Program executed successfully.\n");

    return 0;
}