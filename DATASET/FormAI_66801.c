//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* This program takes a URL input from the user and
   sanitizes it by removing any potentially harmful
   characters, ensuring it is safe before passing it
   on to be used in a web application. */

int main() {
    char url[1000];
    char sanitizedUrl[1000] = "";
    
    printf("Enter a URL to sanitize: ");
    fgets(url, 1000, stdin);

    int length = strlen(url);

    for (int i = 0; i < length; i++) {
        if (isalpha(url[i]) || isdigit(url[i]) || url[i] == '.' || url[i] == '/' || url[i] == ':') {
            strncat(sanitizedUrl, &url[i], 1);
        }
    }

    printf("Sanitized URL: %s\n", sanitizedUrl);

    return 0;
}