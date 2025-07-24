//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//function to sanitize urls
void sanitizeURL(char *url) {
    //removing trailing slashes if present
    int len = strlen(url);
    while (len > 0 && url[len-1] == '/') {
        url[len-1] = '\0';
        len--;
    }

    //converting all characters to lowercase
    int i;
    for (i = 0; url[i]; i++) {
        url[i] = tolower(url[i]);
    }
}

int main() {
    char url[100];

    //taking input from user
    printf("Enter URL to be sanitized: ");
    scanf("%s", url);

    sanitizeURL(url);

    //printing sanitized url
    printf("Sanitized URL: %s", url);

    return 0;
}