//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: real-life
#include <stdio.h>
#include <string.h>

#define MAX_URL_LENGTH 200

/*
 * Function to sanitize a URL by removing any malicious or unsafe characters
 */
void sanitizeUrl(char* url) {
    int i, j = 0;
    char sanitizedUrl[MAX_URL_LENGTH];
    const char* safeCharacters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-._~:/?#[]@!$&'()*+,;=";

    for (i = 0; i < strlen(url); i++) {
        if (strchr(safeCharacters, url[i]) != NULL) {
            sanitizedUrl[j++] = url[i];
        }
    }

    sanitizedUrl[j] = '\0';
    strcpy(url, sanitizedUrl);
}

/*
 * Main function to test sanitization of a URL
 */
int main() {
    char url[MAX_URL_LENGTH];

    printf("Enter the URL to be sanitized (max %d characters): ", MAX_URL_LENGTH);
    fgets(url, MAX_URL_LENGTH, stdin);

    // Remove the trailing newline character from fgets
    url[strcspn(url, "\n")] = 0;

    printf("Sanitizing URL...\n");

    sanitizeUrl(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}