//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_URL_LENGTH 2048

char* sanitize_url(char* url);

int main(void) {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    char* sanitized_url = sanitize_url(url);
    if (sanitized_url == NULL) {
        printf("Invalid URL");
        return -1;
    }
    printf("Sanitized URL: %s", sanitized_url);
    free(sanitized_url);
    return 0;
}

char* sanitize_url(char* url) {
    char* sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));
    if (sanitized_url == NULL) {
        return NULL;
    }
    int sanitized_index = 0;
    int url_length = strlen(url);
    for (int i = 0; i < url_length; i++) {
        if (isalnum(url[i]) || url[i] == '.' || url[i] == '/' || url[i] == ':' || url[i] == '-') {
            sanitized_url[sanitized_index++] = url[i];
        }
    }
    sanitized_url[sanitized_index] = '\0';
    if (sanitized_index == 0) {
        free(sanitized_url);
        return NULL;
    }
    return sanitized_url;
}