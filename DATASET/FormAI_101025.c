//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 100

void sanitizeUrl(char *url) {
    char sanitizedUrl[MAX_URL_LENGTH];

    int i;
    int j = 0;
    int urlLength = strlen(url);

    for (i = 0; i < urlLength; i++) {
        if (isalnum(url[i]) || url[i] == '.' || url[i] == '/' || url[i] == ':' || url[i] == '-') {
            sanitizedUrl[j] = url[i];
            j++;
        }
    }

    sanitizedUrl[j] = '\0';

    strcpy(url, sanitizedUrl);
}

int main() {
    char url[MAX_URL_LENGTH];

    printf("Enter a URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    sanitizeUrl(url);

    printf("Sanitized URL: %s", url);

    return 0;
}