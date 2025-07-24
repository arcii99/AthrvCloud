//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isAlphaNumeric(char c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void sanitizeURL(char *url) {
    int i = 0, j = 0;
    char temp[strlen(url) + 1];
    
    while(url[i] != '\0') {
        if(isAlphaNumeric(url[i])) {
            temp[j] = url[i];
            j++;
        }
        i++;
    }
    temp[j] = '\0';
    strcpy(url, temp);
}

int main() {
    char url[1000];
    printf("Enter the URL: ");
    fgets(url, sizeof(url), stdin);
    url[strcspn(url, "\n")] = 0; // remove newline character
    
    sanitizeURL(url);
    
    printf("Sanitized URL: %s\n", url);
    
    return 0;
}