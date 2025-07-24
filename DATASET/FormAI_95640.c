//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* sanitizeURL(char *url);

int main() {
    char url[100];

    printf("Enter the URL to sanitize: ");
    scanf("%s", url);

    char *sanitizedURL = sanitizeURL(url);

    printf("Sanitized URL: %s\n", sanitizedURL);

    free(sanitizedURL);

    return 0;
}

char* sanitizeURL(char *url) {
    char reservedChars[] = {'&', '\'', '<', '>', '\"', '\n', '%', '\\'};
    int urlLength = strlen(url);
    char *sanitizedURL = (char*)malloc((urlLength + 1) * sizeof(char));

    int i, j;
    for (i = 0, j = 0; i < urlLength; i++) {
        if (strchr(reservedChars, url[i]) == NULL) {
            sanitizedURL[j++] = url[i];
        } else {
            sanitizedURL[j++] = '%';
            sprintf(&sanitizedURL[j], "%02X", url[i]);
            j += 2;
        }
    }

    sanitizedURL[j] = '\0';

    return sanitizedURL;
}