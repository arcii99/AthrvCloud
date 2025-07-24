//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: optimized
#include <stdio.h>
#include <string.h>

/* Function to check if the character is valid */
int isValid(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')
        || c == '.' || c == '_' || c == '~' || c == '-' || c == '/')
        return 1;

    return 0;
}

/* Function to sanitize the URL */
char* sanitizeURL(char* url) {
    char* sanitizedURL = (char*)malloc(strlen(url) + 1);
    int i, j = 0;

    for (i = 0; url[i] != '\0'; i++) {
        if (isValid(url[i]))
            sanitizedURL[j++] = url[i];

        if (url[i] == ' ')
            sanitizedURL[j++] = '+';
    }

    sanitizedURL[j] = '\0';
    return sanitizedURL;
}

/* Main function to execute the program */
int main() {
    char url[500], *sanitizedURL;

    printf("Enter the URL to be sanitized: ");
    fgets(url, sizeof(url), stdin);

    sanitizedURL = sanitizeURL(url);

    printf("The sanitized URL is: %s\n", sanitizedURL);

    free(sanitizedURL);
    return 0;
}