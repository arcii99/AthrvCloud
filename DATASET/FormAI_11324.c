//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Linus Torvalds
/*
 * URL Sanitizer
 *
 * This program takes a URL as input and removes any potentially malicious code from it.
 * It does so by removing any characters that are not alphanumeric or part of the URL's allowed
 * characters set (such as '-' and '_').
 * 
 * By [your name here]
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Define the characters that are allowed in a URL
const char allowed_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_.";

// Sanitize function to remove any non-allowed characters from a string
void sanitize(char* str) {
    char* dest = str;
    while (*str) {
        if (isalnum(*str) || strchr(allowed_chars, *str) != NULL) {
            *(dest++) = *str;
        }
        str++;
    }
    *dest = '\0';
}

int main() {
    char url[1024];

    // Get input from user
    printf("Enter a URL to sanitize (max 1023 characters):\n");
    fgets(url, 1024, stdin);

    sanitize(url);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", url);

    return 0;
}