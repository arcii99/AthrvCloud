//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to sanitize URL
char *sanitize_url(char *url) {
    char *sanitized_url = malloc(strlen(url) + 1);
    int i, j;
    for (i = 0, j = 0; i < strlen(url); i++, j++) {
        // Check if character is alphanumeric or a valid URL character
        if (isalnum(url[i]) || url[i] == '/' || url[i] == '.' || url[i] == '-' || url[i] == '_') {
            sanitized_url[j] = url[i];
        // Replace invalid characters with hyphen
        } else {
            sanitized_url[j] = '-';
        }
    }
    sanitized_url[j] = '\0';
    return sanitized_url;
}

// Function to test the program
int main() {
    char url[] = "https://www.example.com/SomeInvalid/URL?with=some&invalid*characters";
    char *sanitized_url = sanitize_url(url);
    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}