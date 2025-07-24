//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program sanitizes a URL to ensure that it does not contain any malicious or unsafe characters.

// Function to check if a character is alphanumeric or not
int isAlphanumeric(char c) {
    if (((int)c >= 65 && (int)c <= 90) || ((int)c >= 97 && (int)c <= 122) || ((int)c >= 48 && (int)c <= 57)) {
        return 1;
    }
    return 0;
}

// Function to sanitize the URL
void sanitizeURL(char* url) {
    char* newUrl = (char*)malloc(sizeof(char) * strlen(url));
    int j = 0;
    for (int i = 0; i < strlen(url); i++) {
        if (isAlphanumeric(url[i])) {
            newUrl[j++] = url[i];
        } else if (url[i] == ':') {
            newUrl[j++] = url[i];
        } else if (url[i] == '/') {
            newUrl[j++] = url[i];
        } else if (url[i] == '.') {
            newUrl[j++] = url[i];
        }
    }
    newUrl[j] = '\0';
    strcpy(url, newUrl);
    free(newUrl);
}

int main() {
    char* url = (char*)malloc(sizeof(char) * 100);
    printf("Enter a URL: ");
    scanf("%s", url);
    sanitizeURL(url);
    printf("Sanitized URL: %s\n", url);
    free(url);
    return 0;
}