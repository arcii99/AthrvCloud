//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sanitize(char *url) {
    int length = strlen(url);
    for (int i = 0; i < length; i++) {
        if (!isalpha(url[i]) && !isdigit(url[i]) && url[i] != '.' && url[i] != '/') {
            url[i] = '_';
        }
    }
}

int main() {

    char url[100];
    printf("Enter a URL to sanitize: ");
    fgets(url, 100, stdin);
    sanitize(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}