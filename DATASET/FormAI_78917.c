//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a character is an alphabetic character
int isAlpha(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// Function to check if a character is a numeric character
int isNumeric(char c) {
    return (c >= '0' && c <= '9');
}

// Function to check if a character is an allowed special character
int isAllowedChar(char c) {
    char allowedChars[] = "-_.!~*'()";
    for (int i = 0; i < sizeof(allowedChars); i++) {
        if (c == allowedChars[i]) {
            return 1;
        }
    }
    return 0;
}

// Function to sanitize a URL
void sanitizeURL(char* url) {
    // Initialize sanitized URL
    char* sanitizedURL = (char*) malloc(sizeof(char) * strlen(url));
    strcpy(sanitizedURL, "");

    // Loop through characters in URL
    for (int i = 0; i < strlen(url); i++) {
        // Check if character is alphanumeric or an allowed special character
        if (isAlpha(url[i]) || isNumeric(url[i]) || isAllowedChar(url[i])) {
            // Append character to sanitized URL
            char cStr[2] = {url[i], '\0'};
            strcat(sanitizedURL, cStr);
        }
    }

    // Replace original URL with sanitized URL
    strcpy(url, sanitizedURL);

    // Free memory allocated for sanitized URL
    free(sanitizedURL);
}

int main() {
    // Initialize URL
    char url[] = "https://www.example.com/test page/1?query=test&test=true";

    // Sanitize URL
    sanitizeURL(url);

    // Print sanitized URL
    printf("Sanitized URL: %s", url);

    return 0;
}