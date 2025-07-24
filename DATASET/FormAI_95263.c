//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: creative
#include <stdio.h>
#include <string.h>

int main() {
    char url[100];
    printf("Enter URL to sanitize: ");
    scanf("%s", url);
    
    // Remove any leading or trailing whitespace characters
    char* sanitizedUrl = url;
    while (sanitizedUrl[0] == ' ') {
        sanitizedUrl++;
    }
    int length = strlen(sanitizedUrl);
    while (sanitizedUrl[length - 1] == ' ') {
        sanitizedUrl[length - 1] = '\0';
        length--;
    }
    
    // Check for any suspicious characters
    for (int i = 0; i < strlen(sanitizedUrl); i++) {
        if (sanitizedUrl[i] == '(' || sanitizedUrl[i] == ')' || sanitizedUrl[i] == '{' || sanitizedUrl[i] == '}' || sanitizedUrl[i] == '<' || sanitizedUrl[i] == '>' || sanitizedUrl[i] == '"' || sanitizedUrl[i] == '\'') {
            sanitizedUrl[i] = '-';
        }
    }
    
    printf("Sanitized URL: %s\n", sanitizedUrl);
    
    return 0;
}