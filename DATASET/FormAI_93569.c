//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: interoperable
#include <stdio.h>
#include <string.h>

// A function to check if a given character is a valid URL character
int isValidURLChar(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')
        || c == '.' || c == '-' || c == '_' || c == '~')
        return 1;
    return 0;
}

// A function to sanitize the given URL by removing any invalid characters
void sanitizeURL(char *url) {
    int i, j;
    for (i = 0, j = 0; i < strlen(url); i++) {
        if (isValidURLChar(url[i])) {
            url[j++] = url[i];
        }
    }
    url[j] = '\0';
}

int main() {
    char url[100];
    printf("Enter the URL to sanitize: ");
    scanf("%s", url);
    sanitizeURL(url);
    printf("Sanitized URL: %s", url);
    return 0;
}