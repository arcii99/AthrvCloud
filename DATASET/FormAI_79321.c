//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

char* sanitize(char* url) {
    char* newUrl = (char*) malloc(strlen(url) + 1);
    for (int i = 0; i < strlen(url); i++) {
        if ((url[i] >= 'a' && url[i] <= 'z') || (url[i] >= 'A' && url[i] <= 'Z') || (url[i] >= '0' && url[i] <= '9') || url[i] == '.' || url[i] == ':' || url[i] == '/' || url[i] == '-') {
            newUrl[i] = url[i];
        } else {
            newUrl[i] = '_';
        }
    }
    newUrl[strlen(url)] = '\0';
    return newUrl;
}

int main() {
    char url[100];
    printf("Enter URL: ");
    scanf("%s", url);
    char* sanitized = sanitize(url);
    printf("Sanitized URL: %s\n", sanitized);
    free(sanitized);
    return 0;
}