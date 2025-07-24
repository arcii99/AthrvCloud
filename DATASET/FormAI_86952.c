//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 1000

// This function checks if a given character is alpha-numeric
bool isAlphaNumeric(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
        return true;
    }
    return false;
}

// This function checks if a given character is a special character that can be part of a URL
bool isSpecialCharacter(char c) {
    if (c == '.' || c == ':' || c == '/' || c == '-' || c == '_' || c == '~' || c == '?' || c == '#' || c == '&' || c == '=' || c == '%' || c == '+' || c == '@') {
        return true;
    }
    return false;
}

// This function takes an input URL in string form and sanitizes it by removing any possibly malicious input
void sanitizeURL(char *url) {
    int i, j;
    char temp[MAX_URL_LENGTH + 1];

    // Copy all alpha-numeric and some special characters into the temp string
    for (i = j = 0; url[i]; i++) {
        if (isAlphaNumeric(url[i]) || isSpecialCharacter(url[i])) {
            temp[j++] = url[i];
        }
    }
    temp[j] = '\0';

    // Check if we need to add "http://" to the beginning of the URL
    if (strncmp(temp, "http://", 7) != 0) {
        char newTemp[MAX_URL_LENGTH + 1];
        strncpy(newTemp, "http://", 7);
        strncpy(&newTemp[7], temp, MAX_URL_LENGTH);
        strncpy(url, newTemp, MAX_URL_LENGTH);
    } else {
        strncpy(url, temp, MAX_URL_LENGTH);
    }
}

int main() {
    char url[MAX_URL_LENGTH + 1];

    // Get URL input from user
    printf("Enter a URL: ");
    fgets(url, MAX_URL_LENGTH + 1, stdin);

    // Sanitize the input URL
    sanitizeURL(url);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", url);

    return 0;
}