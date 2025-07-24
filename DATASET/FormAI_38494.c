//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 1024

void sanitize_url(char* url) {
    char *temp = (char*)malloc(MAX_URL_LENGTH);
    int j = 0;
    for (int i = 0; i < strlen(url); i++) {
        // Remove any whitespace characters
        if (url[i] == ' ' || url[i] == '\t' || url[i] == '\n' || url[i] == '\r') {
            continue;
        }
        // Only add valid characters to temp
        if (url[i] == '.' || url[i] == '-' || url[i] == '_' || url[i] == '~' || (url[i] >= 'a' && url[i] <= 'z') || 
            (url[i] >= 'A' && url[i] <= 'Z') || (url[i] >= '0' && url[i] <= '9')) {
            temp[j++] = url[i];
        }
    }
    // Add null terminator
    temp[j] = '\0';
    
    // Copy sanitized URL back to original URL string
    strcpy(url, temp);
    free(temp);
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}