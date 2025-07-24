//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: post-apocalyptic
// Post-Apocalyptic Unique User Input Sanitizer

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char input[50];
    char sanitizedInput[50];
    int isValid = 0;
    
    printf("Enter your input: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // remove newline character
    
    while (!isValid) {
        int isUnique = 1;
        for (int i = 0; i < strlen(input); i++) {
            if (!isalnum(input[i])) { // Only accept alphanumeric characters
                printf("Invalid input. Please enter alphanumeric characters only: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;
                isUnique = 0;
                break;
            }
        }
        if (isUnique) {
            char tempChar;
            for (int i = 0, j = 0; i < strlen(input); i++) {
                tempChar = input[i];
                tempChar = toupper(tempChar); // Convert all characters to uppercase
                if (!strchr(sanitizedInput, tempChar)) { // Check if character exists in sanitized input
                    sanitizedInput[j++] = tempChar;
                }
            }
            sanitizedInput[strlen(sanitizedInput)] = '\0'; // Add null terminator
            printf("Sanitized input: %s\n", sanitizedInput);
            isValid = 1;
        }
    }
    
    return 0;
}