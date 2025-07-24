//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 1000

int main(void) {
    // Input URL
    char url[MAX_URL_LENGTH];
    printf("Enter URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    // Remove trailing newline character
    url[strcspn(url, "\n")] = 0;

    // Convert to lowercase
    for (int i = 0; i < strlen(url); i++) {
        url[i] = tolower(url[i]);
    }

    // Check for protocol
    if (strncmp(url, "http://", 7) != 0 && strncmp(url, "https://", 8) != 0) {
        printf("Invalid URL - missing protocol\n");
        return 0;
    }

    // Check for valid characters
    for (int i = 0; i < strlen(url); i++) {
        if (isalnum(url[i]) || url[i] == '.' || url[i] == '/' || url[i] == ':' || url[i] == '-') {
            continue;
        }
        printf("Invalid character in URL: %c\n", url[i]);
        return 0;
    }

    // Check for correct format
    int slash_count = 0;
    int colon_count = 0;
    for (int i = 0; i < strlen(url); i++) {
        if (url[i] == '/') {
            slash_count++;
        } else if (url[i] == ':') {
            colon_count++;
        }
    }
    if (colon_count > 1) {
        printf("Invalid URL - too many colons\n");
        return 0;
    }
    if (slash_count < 2) {
        printf("Invalid URL - too few slashes\n");
        return 0;
    }

    // Output sanitized URL
    printf("Sanitized URL: %s\n", url);

    return 0;
}