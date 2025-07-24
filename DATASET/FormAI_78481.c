//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: energetic
// Energized C URL Sanitizer Example Program
// By Codebot 9000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 200

bool is_alpha_numeric(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
}

void sanitize_url(char* url) {
    // Removing whitespace at begining and end
    int len = strlen(url);
    while (len > 0 && (url[len - 1] == '\r' || url[len - 1] == '\n' || url[len - 1] == ' ')) {
        url[len - 1] = '\0';
        len--;
    }
    while (*url == '\r' || *url == '\n' || *url == ' ') {
        url++;
        len--;
    }

    // Checking if url starts with "http://" or "https://"
    char* prefix = "http://";
    if (strncmp(url, prefix, strlen(prefix)) != 0) {
        prefix = "https://";
        if (strncmp(url, prefix, strlen(prefix)) != 0) {
            printf("ERROR: URL should start with http:// or https://\n");
            return;
        }
    }

    // Replacing all non alpha-numeric characters with '_'
    for (int i = 0; i < len; i++) {
        if (!is_alpha_numeric(url[i])) {
            url[i] = '_';
        }
    }

    // Ensuring that maximum URL length is not exceeded
    if (len > MAX_URL_LENGTH) {
        printf("ERROR: Maximum URL length exceeded\n");
        return;
    }
}

int main(int argc, char** argv) {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    fgets(url, sizeof(url), stdin);
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);

    return 0;
}