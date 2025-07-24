//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_URL_LENGTH 1000
#define MAX_SANITIZED_LENGTH 5000

char* sanitize_url(char* url) {
    char* sanitized_url = (char*) malloc(MAX_SANITIZED_LENGTH * sizeof(char));
    char* src = url;
    char* dst = sanitized_url;

    while (*src != '\0') {
        if (dst - sanitized_url >= MAX_SANITIZED_LENGTH - 1) break;

        if (isalpha(*src) || isdigit(*src)) {
            *dst++ = *src++;
        } else if (*src == '/' && *(dst - 1) == '/') {
            src++;
        } else if (*src == '?' && *(dst - 1) == '/') {
            *dst++ = *src++;
        } else if (*src == '&' || *src == '=' || *src == '%') {
            *dst++ = *src++;
        } else {
            src++;
        }
    }

    *dst = '\0';

    return sanitized_url;
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    char* sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);
    return 0;
}