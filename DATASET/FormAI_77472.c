//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char url[1000]; // Maximum URL length
    printf("Enter the URL to sanitize: ");
    fgets(url, 1000, stdin); // Read the input URL

    // Remove new line character from the end of the URL
    url[strcspn(url, "\n")] = 0;

    // Initialize the sanitized URL
    char sanitized_url[1000];
    memset(sanitized_url, 0, sizeof(sanitized_url));

    // Loop through each character of the input URL
    for (int i = 0; i < strlen(url); i++) {
        // Check if the character is a valid ASCII character (32-126)
        if (url[i] >= 32 && url[i] <= 126) {
            // Append the character to the sanitized URL
            strncat(sanitized_url, &url[i], 1);
        }
    }

    printf("Sanitized URL: %s\n", sanitized_url);

    return 0;
}