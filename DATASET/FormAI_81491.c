//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Sherlock Holmes
/* The Case of The Mysterious URL Sanitizer */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 1000

// Detects if a character is a part of the URL scheme
int is_scheme_char(char c) {
    return isalpha(c) || c == '+' || c == '-' || c == '.';
}

// Converts a string to lowercase
void to_lower(char *str) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}

// Removes any trailing whitespace from a string
void strip_trailing_whitespace(char *str) {
    int end = strlen(str) - 1;
    while (end >= 0 && isspace(str[end]))
        end--;
    str[end + 1] = '\0';
}

// Sanitizes a given URL
void sanitize_url(char *url) {
    // First, we remove any leading or trailing whitespace
    strip_trailing_whitespace(url);

    // Next, we check if the URL scheme is present and make it lowercase
    char *scheme_end = strchr(url, ':');
    if (scheme_end != NULL && scheme_end - url < MAX_URL_LENGTH) {
        for (char *c = url; c < scheme_end; c++)
            if (!is_scheme_char(*c)) {
                *scheme_end = '\0';
                break;
            }
        to_lower(url);
    }

    // Finally, we remove any invalid characters from the URL
    char *p = url;
    while (*p) {
        if (isalnum(*p) || *p == '-' || *p == '_' || *p == '.' || *p == '/' || *p == '=' || *p == '&' || *p == '?')
            p++;
        else
            memmove(p, p+1, strlen(p));
    }
}

int main() {
    printf("Welcome to The Case of The Mysterious URL Sanitizer...\n\n");

    // Ask for user input
    char url[MAX_URL_LENGTH];
    printf("Please enter a URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    // Sanitize the URL
    sanitize_url(url);

    // Print the result
    printf("\nThe sanitized URL is: %s\n", url);

    // Return success status
    return 0;
}