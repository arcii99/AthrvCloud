//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

// Function to sanitize a given URL
void sanitize_url(char *url) {
    char sanitized_url[MAX_LENGTH];
    int i, j = 0;

    // Iterate through the URL
    for (i = 0; url[i]; i++) {
        // Remove all characters that are not alphanumeric or a forward slash
        if (isalnum(url[i]) || url[i] == '/') {
            sanitized_url[j++] = url[i];
        }
    }

    // Null-terminate the new string
    sanitized_url[j] = '\0';

    // Copy the sanitized URL back over the original string
    strcpy(url, sanitized_url);
}

int main() {
    char url[MAX_LENGTH];

    // Prompt the user for a URL to sanitize
    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_LENGTH, stdin);

    // Call the sanitize function on the URL
    sanitize_url(url);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", url);

    return 0;
}