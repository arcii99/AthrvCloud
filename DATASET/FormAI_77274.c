//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sanitizeUrl(char* url) {
    char* validCharacters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-._~:/?#[]@!$&'()*+,;=%";
    char* sanitizedUrl = (char*) malloc(strlen(url) + 1);
    int sanitizedUrlIndex = 0;

    for (int i = 0; i < strlen(url); i++) {
        char currentChar = url[i];
        if (strchr(validCharacters, currentChar) != NULL) {
            sanitizedUrl[sanitizedUrlIndex++] = currentChar;
        }
        else {
            char* hexString = (char*) malloc(3);
            sprintf(hexString, "%02X", currentChar);
            sanitizedUrl[sanitizedUrlIndex++] = '%';
            sanitizedUrl[sanitizedUrlIndex++] = hexString[0];
            sanitizedUrl[sanitizedUrlIndex++] = hexString[1];
            free(hexString);
        }
    }

    sanitizedUrl[sanitizedUrlIndex] = '\0';
    strcpy(url, sanitizedUrl);
    free(sanitizedUrl);
}

int main() {
    char url[] = "https://www.example.com/abc 123.html?param=value&param2=v@lue";
    printf("Original URL: %s\n", url);
    sanitizeUrl(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}