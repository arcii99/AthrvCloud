//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

// Function to sanitize a URL string
void sanitizeUrl(char *url) {
    char temp[1024];
    int i, j;

    // Loop through string character by character
    for(i = 0, j = 0; i < strlen(url); i++) {
        // Check for forbidden characters
        if(url[i] != '<' && url[i] != '>' && url[i] != '\'' && url[i] != '\"' && url[i] != '\\' && url[i] != '%') {
            // If character is not forbidden, add it to temp string
            temp[j++] = url[i];
        }
    }
    temp[j] = '\0';
    // Copy sanitized string back to original input
    strcpy(url, temp);
}

int main() {
    char url[1024];

    printf("Welcome to Sherlock Holmes' C URL Sanitizer!\n");
    printf("Please enter a URL: ");
    gets(url);

    // Call sanitizeUrl function on input string
    sanitizeUrl(url);

    printf("Your sanitized URL is: %s\n", url);

    return 0;
}