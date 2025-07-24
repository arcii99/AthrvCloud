//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX_URL_LEN 1000

bool is_valid_char(char c) {
    if (isalnum(c) || c == ':' || c == '/' || c == '.') {
        return true;
    }
    return false;
}

void url_sanitizer(char* url) {
    char sanitized[MAX_URL_LEN];
    int j = 0;
    bool colon_found = false;
    for (int i = 0; i < strlen(url); i++) {
        if (is_valid_char(url[i])) {
            sanitized[j] = url[i];
            j++;
            if (url[i] == ':' && !colon_found) {
                colon_found = true;
            }
        }
    }
    if (!colon_found) {
        printf("Error: Invalid URL - No protocol specified\n");
        return;
    }
    sanitized[j] = '\0';
    strcpy(url, sanitized);
}

int main() {
    char url[MAX_URL_LEN];
    printf("Enter a URL: ");
    scanf("%[^\n]", url);
    url_sanitizer(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}