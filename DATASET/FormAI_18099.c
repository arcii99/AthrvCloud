//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char userInput[50];
    printf("Please enter your name: ");
    fgets(userInput, 50, stdin);        // Reads user input into the userInput variable
    fflush(stdin);

    // Initial prompt to the user
    printf("Hi %s, please enter your age: ", userInput);
    fgets((char *)calloc(50, sizeof(char)), 50, stdin);

    // Re-prompt the user with an error message if any unrecognized characters were entered
    while ((sscanf(userInput, "%[^\n]", userInput) != 1) || (atoi(userInput) <= 0) || (atoi(userInput) > 120)) {
        printf("Error! Please enter a valid age (must be a positive integer between 1 and 120 inclusive): ");
        fgets(userInput, 50, stdin);
    }

    int age = atoi(userInput);      // Store the valid age value in an integer variable

    // Display the sanitized user input
    printf("Thank you for entering your age as %d.\n", age);
    return 0;
}