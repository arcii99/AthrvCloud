//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void sanitize(char *url);

int main() {
    char url[100];

    printf("Enter a URL: ");
    fgets(url, 100, stdin);

    sanitize(url);

    printf("Sanitized URL: %s", url);

    return 0;
}

void sanitize(char *url) {
    char temp[100];
    int i, j;

    for (i = j = 0; url[i] != '\0'; ++i) {
        if (isalnum(url[i])) {
            temp[j++] = url[i];
        } else if (url[i] == '/') {
            temp[j++] = '/';
        } else if (url[i] == '.') {
            temp[j++] = '.';
        }
    }

    temp[j] = '\0';

    strcpy(url, temp);
}