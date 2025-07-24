//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if a given character is an alphanumeric character
bool is_alphanumeric(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
}

// Function to sanitize a given URL and return a sanitized string
char* sanitize_url(char* url) {
    int len = strlen(url);
    char* sanitized_url = (char*)malloc(len + 1); // Allocate memory to store sanitized URL
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (is_alphanumeric(url[i])) {
            sanitized_url[j++] = url[i]; // Copy alphanumeric characters as it is
        }
        else if (url[i] == '_') {
            sanitized_url[j++] = '-'; // Replace underscore with hyphen
        }
        // Ignore all other characters
    }
    sanitized_url[j] = '\0'; // Terminate the string
    return sanitized_url;
}

int main() {
    char url[] = "https://www.example.com/product_page/product_1";
    char* sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s", sanitized_url);
    free(sanitized_url);
    return 0;
}