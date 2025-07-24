//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_URL_LENGTH 1000

/* function declaration */
char *sanitize_url(char *url);

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    char *sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}

/* URL sanitizer function */
char *sanitize_url(char *url) {
    int length = strlen(url);
    char *sanitized_url = (char*) calloc(MAX_URL_LENGTH, sizeof(char));
    int i, j;
    for (i = 0, j = 0; i < length; i++) {
        if (isalnum(url[i]) || url[i] == '.' || url[i] == '-' || url[i] == '_' || url[i] == '/') {
            sanitized_url[j++] = url[i];
        }
        if (url[i] == ' ') {
            sanitized_url[j++] = '+';
        }
    }
    return sanitized_url;
}