//FormAI DATASET v1.0 Category: Text processing ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Initialize variables
    char input[100];
    char output[100];
    int index = 0;

    // Prompt user for input
    printf("Enter a string of characters: ");
    scanf("%s", input);

    // Loop through each character in the input string
    for (int i = 0; i < strlen(input); i++) {
        // Check if the character is a letter
        if (input[i] >= 'a' && input[i] <= 'z') {
            // If it is a lowercase letter, convert it to uppercase and add it to the output string
            output[index] = input[i] - 32;
            index++;
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            // If it is an uppercase letter, convert it to lowercase and add it to the output string
            output[index] = input[i] + 32;
            index++;
        } else {
            // If it is not a letter, simply add it to the output string
            output[index] = input[i];
            index++;
        }
    }

    // Add a null terminator to the end of the output string
    output[index] = '\0';

    // Print the output string
    printf("Input    : %s\n", input);
    printf("Processed: %s\n", output);

    return 0;
}