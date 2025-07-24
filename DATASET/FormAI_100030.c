//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to replace characters with underscores
void sanitize(char* url) {
    int i, len = strlen(url);
    for(i = 0; i < len; i++) {
        if(!isalnum(url[i]) && url[i] != '.' && url[i] != '/' && url[i] != '-' && url[i] != '_') {
            url[i] = '_';
        }
    }
}

int main() {
    printf("Enter a URL:\n");

    // Allocate memory for URL string
    char* url = (char*) malloc(sizeof(char) * MAX_URL_LENGTH);

    // Get URL input from user
    fgets(url, MAX_URL_LENGTH, stdin);
    url[strcspn(url, "\n")] = 0;

    // Sanitize URL
    sanitize(url);

    // Print sanitized URL
    printf("Sanitized URL: %s\n", url);

    free(url);
    return 0;
}