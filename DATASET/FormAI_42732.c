//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_URL_LENGTH 200

char* sanitizeUrl(char* url) {
    int len = strlen(url);
    char* sanitizedUrl = calloc(len+1, sizeof(char));
    int j = 0;

    for (int i=0; i<len; i++) {
        if (url[i] == '<' || url[i] == '>' || url[i] == '"' || url[i] == '\'' || url[i] == '(' || url[i] == ')' || url[i] == '{' || url[i] == '}' || url[i] == '|' || url[i] == '^' || url[i] == '[' || url[i] == ']' || url[i] == '`' || url[i] == ';' || url[i] == '#' || url[i] == '&' || url[i] == '?') {
            continue;
        } else if (url[i] == ' ') {
            sanitizedUrl[j] = '%';
            sanitizedUrl[j+1] = '2';
            sanitizedUrl[j+2] = '0';
            j += 3;
        } else if (url[i] == '\\') {
            sanitizedUrl[j] = '/';
            j++;
        } else {
            sanitizedUrl[j] = url[i];
            j++;
        }
    }
    return sanitizedUrl;
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    char* sanitizedUrl = sanitizeUrl(url);
    printf("Sanitized URL: %s", sanitizedUrl);
    free(sanitizedUrl);
    return 0;
}