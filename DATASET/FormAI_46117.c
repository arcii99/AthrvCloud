//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to sanitize a URL
char* sanitizeURL(char* url) {
    int i, j = 0;
    char sanitizedURL[256];

    // Check each character in the URL string
    for (i = 0; i < strlen(url); i++) {
        // Check if the character is a valid URL character
        if (isalnum(url[i]) || url[i] == '.' || url[i] == '/' || url[i] == '-' || url[i] == '_' || url[i] == '?' || url[i] == '=') {
            // If it is valid, add it to the sanitized URL string
            sanitizedURL[j] = url[i];
            j++;
        }
    }

    // Terminate the sanitized URL string
    sanitizedURL[j] = '\0';

    // Copy the sanitized URL string to the original URL string
    strcpy(url, sanitizedURL);

    // Return the sanitized URL string
    return url;
}

// Main function
int main() {
    char url[256];

    // Get input from the user
    printf("Enter a URL to sanitize: ");
    scanf("%s", url);

    // Sanitize the URL
    sanitizeURL(url);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", url);

    return 0;
}