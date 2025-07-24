//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* Function Prototype */
bool is_valid_char(char c);
char* sanitize_url(char* url);

/* Main Function */
int main() {
    char url[1000];
    printf("Enter a URL to sanitize: ");
    scanf("%s", url);

    printf("Sanitized URL: %s", sanitize_url(url));
    return 0;
}

/* Function Implementation */
bool is_valid_char(char c) {
    // Check if the character is valid
    if ((c >= '0' && c <= '9') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z') ||
        c == ':' || c == '/' ||
        c == '.' || c == '-') {
        return true;
    }
    return false;
}

char* sanitize_url(char* url) {
    // Sanitize the URL
    int len = strlen(url);
    char* sanitized_url = (char*)malloc(len * sizeof(char));
    int i, j = 0;
    for (i = 0; i < len; i++) {
        if (is_valid_char(url[i])) {
            sanitized_url[j] = url[i];
            j++;
        }
    }
    sanitized_url[j] = '\0';
    return sanitized_url;
}