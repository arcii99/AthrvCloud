//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define a helper function to check if a character is a valid URL character
bool isValidChar(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '-' || c == '_' || c == '.' || c == '~';
}

// Define the URL sanitizer function
char *sanitizeUrl(char *url) {
    char *result = calloc(strlen(url) + 1, sizeof(char)); // Allocate memory for the result
    char *currentChar = url;
    int resultIndex = 0;

    while (*currentChar != '\0') { // Loop through the input URL
        if (isValidChar(*currentChar)) { // If the character is valid, copy it to the result
            result[resultIndex] = *currentChar;
            resultIndex++;
        } else if (*currentChar == ' ') { // If the character is a space, replace it with '%20'
            strcat(result, "%20");
            resultIndex += 3;
        } else { // If the character is invalid, replace it with its percent-encoded representation
            char *encodedString = calloc(4, sizeof(char));
            sprintf(encodedString, "%%%X", *currentChar);
            strcat(result, encodedString);
            resultIndex += 3;
            free(encodedString);
        }
        currentChar++;
    }

    return result;
}

int main() {
    char *url = "https://www.google.com/search?q=cute+puppies";
    char *sanitizedUrl = sanitizeUrl(url);
    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitizedUrl);
    free(sanitizedUrl);
    return 0;
}