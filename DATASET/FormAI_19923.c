//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Declare function to sanitize URL
char* sanitizeURL(char* url);

// Main function
int main() {
    char url[1000];
    printf("Enter a URL to sanitize: ");
    scanf("%s", url);
    
    // Call sanitizeURL function and print sanitized URL
    char* sanitizedURL = sanitizeURL(url);
    printf("Sanitized URL: %s\n", sanitizedURL);

    // Free memory allocated for sanitizedURL using the free() function
    free(sanitizedURL);

    return 0;
}

// Function to sanitize URL
char* sanitizeURL(char* url) {
    int i = 0;
    int j = 0;
    char* sanitizedURL = (char*) malloc(strlen(url) + 1); // Allocate memory for sanitizedURL using malloc() function

    // Loop through characters of the input URL
    while (url[i]) {
        if (url[i] == ' ') {
            sanitizedURL[j] = '+'; // Replace spaces with '+'
        }
        else if (isalnum(url[i])) {
            sanitizedURL[j] = url[i]; // Copy alphanumeric characters
        }
        else {
            sprintf(&sanitizedURL[j], "%%%02X", (unsigned char) url[i]); // Encode special characters in URL using percent-encoding
            j += 2; // Increment j by 2 to account for two hexadecimal characters
        }
        i++;
        j++;
    }
    sanitizedURL[j] = '\0'; // Add null terminator at the end of the sanitizedURL string

    return sanitizedURL; // Return sanitizedURL
}