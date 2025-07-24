//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

// Function to check if a character is a valid URL character
int valid_char(char c) {
    return isalnum(c) || c == '.' || c == '/' || c == ':' || c == '?' || c == '&' || c == '=' || c == '-' || c == '_';
}

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];
    int index = 0;

    printf("Enter a URL to sanitize: ");

    // Get the input from the user
    fgets(buffer, BUFFER_SIZE, stdin);

    // Loop through each character of the input string
    for (int i = 0; i < strlen(buffer); i++) {
        if (valid_char(buffer[i])) {
            // If the character is valid, add it to the output string
            buffer[index++] = buffer[i];
        } else if (buffer[i] == ' ') {
            // If the character is a space, replace it with a '%20'
            buffer[index++] = '%';
            buffer[index++] = '2';
            buffer[index++] = '0';
        }
    }

    // Null-terminate the output string
    buffer[index] = '\0';

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", buffer);

    return 0;
}