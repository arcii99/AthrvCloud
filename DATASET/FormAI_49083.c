//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 1000

/* Function to remove whitespace characters */
void removeWhitespace(char *str) {
    char *temp = str;
    while (*str) {
        if (*str != ' ' && *str != '\t' && *str != '\r' && *str != '\n')
            *temp++ = *str;
        str++;
    }
    *temp = '\0';
}

/* Function to convert string to lowercase */
void toLowercase(char *str) {
    char *temp = str;
    while (*str) {
        *temp++ = tolower(*str);
        str++;
    }
    *temp = '\0';
}

/* Function to remove characters that are not alphanumeric or special characters in a URL */
void sanitizeURL(char *url) {
    char sanitized[MAX_URL_LENGTH] = {0};
    int i = 0, j = 0;
    while (url[i]) {
        if (isalnum(url[i]) || url[i] == ':' || url[i] == '/' || url[i] == '.' || url[i] == '-' || url[i] == '_' || url[i] == '~' || url[i] == '%' || url[i] == '?') {
            sanitized[j] = url[i];
            j++;
        }
        i++;
    }
    sanitized[j] = '\0';
    strcpy(url, sanitized);
}

/* Main function */
int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);  // Read input from user
    removeWhitespace(url);  // Remove whitespace characters
    toLowercase(url);  // Convert string to lowercase
    sanitizeURL(url);  // Remove non-alphanumeric or special characters
    printf("Sanitized URL: %s\n", url);
    return 0;
}