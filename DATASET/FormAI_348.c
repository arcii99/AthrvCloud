//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is a letter or a digit.
int isAlnum(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
        return 1;
    }
    return 0;
}

// URL sanitizer function
void sanitizeURL(char *url) {
    char temp[strlen(url) + 1];
    int index = 0;

    // Loop through every character in the original URL
    for (int i = 0; i < strlen(url); i++) {
        char c = url[i];

        // If it's a valid character, add it to the sanitized URL
        if (isAlnum(c) || c == '/' || c == '.' || c == '-' || c == '_' || c == ':') {
            temp[index++] = c;
        }
    }
    // Null terminate the temp string
    temp[index] = '\0';

    // Copy the sanitized URL back into the original URL string
    strcpy(url, temp);
}

int main() {
    char url[1000];
    printf("Enter a URL to sanitize: ");
    fgets(url, sizeof(url), stdin);
    url[strcspn(url, "\n")] = 0;

    // Sanitize the URL
    sanitizeURL(url);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", url);

    return 0;
}