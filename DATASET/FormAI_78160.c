//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* sanitizeURL(char* url) {
    char* sanitizedURL = (char*) malloc(strlen(url) + 1);
    int i;
    for (i = 0; url[i]; ++i) {
        if (url[i] == '\'' || url[i] == '\"' || url[i] == '(' || url[i] == ')' || url[i] == '<' || url[i] == '>' || url[i] == ';' || url[i] == '&' || url[i] == '$' || url[i] == '|' || url[i] == '`' || url[i] == '\\') {
            sanitizedURL[i] = '_';
        } else {
            sanitizedURL[i] = url[i];
        }
    }
    sanitizedURL[i] = '\0';
    return sanitizedURL;
}

int main() {
    char url[100], *sanitizedURL;
    printf("Enter a URL: ");
    scanf("%s", url);
    sanitizedURL = sanitizeURL(url);
    printf("Sanitized URL: %s\n", sanitizedURL);
    free(sanitizedURL);
    return 0;
}