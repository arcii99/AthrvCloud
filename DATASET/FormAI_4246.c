//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: curious
#include <stdio.h>
#include <string.h>

/* This program filters out any malformed URL characters from a input string */

int main() {
    char url[100];
    printf("Please enter a URL to sanitize: ");
    fgets(url, 100, stdin);

    int length = strlen(url);
    int sanitizedLength = 0;
    char sanitizedUrl[100];

    for (int i = 0; i < length; i++) {
        char currentChar = url[i];

        if (currentChar == ':') {
            if (url[i + 1] == '/') {
                if (url[i + 2] == '/') {
                    sanitizedUrl[sanitizedLength] = currentChar;
                    sanitizedLength++;
                    sanitizedUrl[sanitizedLength] = url[i + 1];
                    sanitizedLength++;
                    sanitizedUrl[sanitizedLength] = url[i + 2];
                    sanitizedLength++;
                    i += 2;
                }
            }
        } else if (currentChar == '/') {
            if (url[i + 1] == '/') {
                i++;
            } else {
                sanitizedUrl[sanitizedLength] = currentChar;
                sanitizedLength++;
            }
        } else if (isalnum(currentChar)) {
            sanitizedUrl[sanitizedLength] = currentChar;
            sanitizedLength++;
        }
    }

    printf("Sanitized URL: %s\n", sanitizedUrl);
    return 0;
}