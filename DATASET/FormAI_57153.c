//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 200

char* sanitize_url(char* url);

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter the URL you want to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    char* sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s", sanitized_url);
    free(sanitized_url);
    return 0;
}

/**
 * Sanitizes a given URL by removing any characters that could potentially 
 * be used for a security exploit. This function returns a newly allocated 
 * string that must be freed after use.
 */
char* sanitize_url(char* url) {
    // Create a new string to store the sanitized URL
    char* sanitized = malloc(sizeof(char) * MAX_URL_LENGTH);
    int sanitized_index = 0;
    int length = strlen(url);

    for(int i=0; i<length; i++) {
        char character = url[i];
        // Check if the character is a valid ASCII character
        if(character >= 32 && character <= 126) {
            // Check if the character is a valid URL character
            if(character == '/' || character == '.' || character == ':' || character == '-' || character == '_'
                    || (character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z')
                    || (character >= '0' && character <= '9')) {
                sanitized[sanitized_index] = character;
                sanitized_index++;
            }
        }
    }
    sanitized[sanitized_index] = '\0';
    return sanitized;
}