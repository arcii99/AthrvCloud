//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#define MAX_URL_LENGTH 100

int main() {

    char url[MAX_URL_LENGTH];
    printf("Enter a URL to be sanitized: ");
    scanf("%s", url);

    // Check if URL starts with "http://" or "https://"
    if (strncmp(url, "http://", 7) != 0 && strncmp(url, "https://", 8) != 0) {
        printf("Invalid URL format. URL must start with \"http://\" or \"https://\"\n");
        return 0;
    }

    // Remove trailing whitespace and newline character
    url[strcspn(url, "\r\n")] = 0;

    // Remove any characters that are not allowed in URLs
    const char *allowed_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789/:.?=&";
    char sanitized_url[MAX_URL_LENGTH];
    int len = strlen(url);
    int j = 0;

    for (int i = 0; i < len; i++) {
        if (strchr(allowed_chars, url[i]) != NULL) {
            sanitized_url[j++] = url[i];
        }
    }

    sanitized_url[j] = '\0';
    printf("Sanitized URL: %s\n", sanitized_url);

    return 0;
}