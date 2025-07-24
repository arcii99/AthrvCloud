//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Alan Touring
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void removeTrailingSlash(char* str) {
    int len = strlen(str);
    if (str[len-1] == '/') 
        str[len-1] = '\0';
}

void sanitizeUrl(char* url) {
    // Convert to lower case
    for (int i = 0; i < strlen(url); ++i) {
        url[i] = tolower(url[i]);
    }
    
    removeTrailingSlash(url);
}

int main() {
    char url[1000];
    printf("Enter URL to sanitize: ");
    scanf("%s", url);
    sanitizeUrl(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}