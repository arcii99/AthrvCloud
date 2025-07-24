//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

int main() {

    char input[MAX_INPUT_LENGTH];
    printf("Enter some text: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    for(int i = 0; i < strlen(input); i++) {

        // Convert to lowercase
        input[i] = tolower(input[i]);

        // Remove non-alphabetic characters
        if(!isalpha(input[i])) {

            // Shift all characters to the left
            for(int j = i; j < strlen(input); j++) {
                input[j] = input[j+1];
            }

            i--; // Stay at same position to check new character
        }
    }

    printf("Sanitized input: %s\n", input);
    return 0;
}