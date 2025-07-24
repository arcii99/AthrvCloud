//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* Function declarations */
bool checkForIllegalChars(char c);
char* sanitizeURL(char* url);

/* Main function */
int main() {
    char url[100] = "https://www.example.com/search?q=c++";
    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitizeURL(url));
    return 0;
}

/* Function to check for illegal characters */
bool checkForIllegalChars(char c) {
    if (c == '<' || c == '>' || c == '\"' ||
        c == '#' || c == '%' || c == '{' ||
        c == '}' || c == '|' || c == '\\' ||
        c == '^' || c == '~' || c == '[' ||
        c == ']' || c == '`' || c == ';' ||
        c == '/' || c == '?') {
        return true;
    }
    return false;
}

/* Function to sanitize a URL */
char* sanitizeURL(char* url) {
    int i, j = 0;
    int len = strlen(url);
    char* sanitizedURL = (char*)malloc(len * sizeof(char));
    for (i = 0; i < len; i++) {
        if (!checkForIllegalChars(url[i])) {
            sanitizedURL[j] = url[i];
            j++;
        }
    }
    sanitizedURL[j] = '\0';
    return sanitizedURL;
}