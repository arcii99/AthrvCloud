//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_URL_LENGTH 1000 // set a maximum URL length

void urlSanitizer(char url[]) {
    int i, j;
    char sanitizedUrl[MAX_URL_LENGTH];

    // Iterate through the URL characters
    for(i = 0, j = 0; url[i]; ++i, ++j) {
        if(url[i] == '\n') { // Skip newlines
            --j;
            continue;
        }
        else if(!strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-.~_:/?#[]@!$&'()*+,;=", url[i])) {
            // If character is not allowed according to RFCs, replace it with '_'
            sanitizedUrl[j] = '_';
        } 
        else { // Keep allowed characters
            sanitizedUrl[j] = url[i];
        }
    }

    // Add null terminator at the end
    sanitizedUrl[j] = '\0';

    // Print sanitized URL
    printf("Sanitized URL: %s\n", sanitizedUrl);
}

int main() {
    char url[MAX_URL_LENGTH];

    // Prompt user for URL input
    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    // Remove newline character from input
    url[strcspn(url, "\n")] = '\0';

    // Call urlSanitizer function to sanitize the URL
    urlSanitizer(url);

    return 0;
}