//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 1000

int main() {
    char url[MAX_URL_LENGTH];
    char sanitized_url[MAX_URL_LENGTH];
    char *invalid_chars = " <>#%{}|\\^~[]`";

    // prompt the user to enter a URL
    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    // remove any invalid characters from the URL
    int i, j;
    for (i = 0, j = 0; i < strlen(url); i++) {
        if (strchr(invalid_chars, url[i]) == NULL) {
            sanitized_url[j++] = url[i];
        }
    }

    // add null terminator to the end of the sanitized URL
    sanitized_url[j] = '\0';

    // print the original and sanitized URLs
    printf("Original URL: %s", url);
    printf("Sanitized URL: %s", sanitized_url);

    // exit program
    return 0;
}