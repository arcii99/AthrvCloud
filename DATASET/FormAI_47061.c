//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Macros to define our maximum allowed input length and buffer size
#define MAX_INPUT_LENGTH 100
#define BUFFER_SIZE 200

int main() {
    char input[MAX_INPUT_LENGTH]; // Array to store user input
    char buffer[BUFFER_SIZE]; // Array to store sanitized input
    int index = 0; // Index to keep track of position in buffer array

    printf("Enter your input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin); // Use fgets to get user input

    // Loop through each character of user input
    for (int i = 0; i < strlen(input); i++) {
        char c = input[i];

        // If character is not alphanumeric, ignore it
        if (!isalnum(c)) {
            continue;
        }

        // If character is alphanumeric, convert to lowercase and add to buffer array
        buffer[index++] = tolower(c);

        // If buffer array is full, break out of loop
        if (index >= BUFFER_SIZE) {
            break;
        }
    }

    // Add terminating null character to buffer array
    buffer[index] = '\0';

    printf("Sanitized input: %s\n", buffer);

    return 0;
}