//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

#define MAX_URL_LENGTH 100

char sanitizeUrl(char *url) {
    int i, j;
    int length = strlen(url);
    char sanitizedUrl[MAX_URL_LENGTH];
    
    j = 0;
    for (i = 0; i < length; i++) {
        if ((url[i] >= 'a' && url[i] <= 'z') || (url[i] >= 'A' && url[i] <= 'Z') || (url[i] >= '0' && url[i] <= '9')) {
            sanitizedUrl[j++] = url[i];
        }
    }

    sanitizedUrl[j] = '\0';
    strcpy(url, sanitizedUrl);

    return *url;
}

int main() {
    char inputUrl[MAX_URL_LENGTH];
    char *url = inputUrl;

    while (1) {
        printf("Enter a URL to sanitize: ");
        scanf("%s", inputUrl);

        sanitizeUrl(url);

        printf("Sanitized URL: %s\n", inputUrl);
    }

    return 0;
}