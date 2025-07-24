//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: optimized
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100

char* sanitize_url(char* url);

int main() {
    char url[MAX_LENGTH];
    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_LENGTH, stdin);

    char* sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);

    return 0;
}

char* sanitize_url(char* url) {
    char* sanitized_url = malloc(MAX_LENGTH * sizeof(char)); // allocate memory for the sanitized url
    int j = 0;
    for (int i = 0; i < strlen(url); i++) {
        if ((url[i] >= 'A' && url[i] <= 'Z') || (url[i] >= 'a' && url[i] <= 'z') || (url[i] >= '0' && url[i] <= '9') 
            || url[i] == '-' || url[i] == '_' || url[i] == '.' || url[i] == '~') {
            sanitized_url[j++] = url[i];
        }
    }
    sanitized_url[j] = '\0';
    return sanitized_url;
}