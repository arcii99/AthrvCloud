//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove invalid characters from URL
void sanitizeURL(char* url) {
    char invalidChars[] = "<>*%\\^`{|}\"<>\';()[]";
    int i, j, k;
    int urlLength = strlen(url);
    int invalidCharLength = strlen(invalidChars);

    // Loop through each invalid character
    for (i = 0; i < invalidCharLength; i++) {

        // Loop through the URL
        for (j = 0, k = 0; j < urlLength; j++) {

            // If the invalid character is found
            if (url[j] == invalidChars[i]) {
                k++;
            }
            else {
                url[j-k] = url[j];
            }
        }

        // Set the null terminator
        url[j-k] = '\0';
        urlLength = strlen(url);
    }
}

int main() {
    char url[1000];

    // Get URL input from user
    printf("Enter a URL to sanitize: ");
    fgets(url, 1000, stdin);

    // Remove extra newline character from input
    url[strcspn(url, "\n")] = 0;

    // Sanitize the URL
    sanitizeURL(url);

    // Print the sanitized URL
    printf("The sanitized URL is: %s\n", url);

    return 0;
}