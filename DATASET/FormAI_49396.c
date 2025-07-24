//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char url[100];
    printf("Enter a URL: ");
    fgets(url, 100, stdin);

    // Removing new line character from input
    url[strcspn(url, "\n")] = 0;

    int len = strlen(url);

    // Converting all characters to lowercase
    for(int i = 0; i < len; i++) {
        url[i] = tolower(url[i]);
    }

    char sanitized[100];
    int j = 0;

    // Looping through input and copying valid characters to sanitized string
    for(int i = 0; i < len; i++) {
        char c = url[i];

        if((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '.' || c == '/' || c == ':' || c == '-') {
            sanitized[j] = c;
            j++;
        } else if(c == ' ') {
            sanitized[j] = '-';
            j++;
        }
    }

    sanitized[j] = '\0';

    printf("\nSanitized URL: %s\n", sanitized);

    return 0;
}