//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: energetic
#include <stdio.h>
#include <ctype.h>

void sanitizeInput(char* inputString) {

    // Take a copy of the input string
    char* sanitizedString = inputString;

    // Declare and initialize counters
    int i = 0;
    int j = 0;

    // Loop through each character of the input string
    while (inputString[i] != '\0') {

        // If the character is an uppercase letter
        if (isupper(inputString[i])) {

            // Convert it to lowercase
            sanitizedString[j] = tolower(inputString[i]);
            j++; // Increment the sanitized string counter

        // If the character is a lowercase letter or a space
        } else if (islower(inputString[i]) || isspace(inputString[i])) {
            
            // Copy it as is to the sanitized string
            sanitizedString[j] = inputString[i];
            j++; // Increment the sanitized string counter

        // If the character is anything else
        } else {
            
            // Do nothing (i.e. discard the character)

        }

        i++; // Increment the input string counter
    }

    // Null-terminate the sanitized string
    sanitizedString[j] = '\0';

    // Print the sanitized string
    printf("Sanitized input: %s\n", sanitizedString);

}

int main() {

    // Declare and initialize the input buffer
    char inputBuffer[100] = {0};

    // Prompt the user for input
    printf("Enter some text: ");

    // Read in the user input
    fgets(inputBuffer, 100, stdin);

    // Call the sanitizer function
    sanitizeInput(inputBuffer);

    return 0;
}