//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to check if a character is valid in a URL
int is_valid_char(char c) {
    if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
        return 1;
    } else {
        return 0;
    }
}

// Function to sanitize a URL
char* sanitize_url(char* url) {
    int i, j = 0;
    int len = strlen(url);
    char* sanitized_url = (char*) malloc(len * sizeof(char));
    
    for (i = 0; i < len; i++) {
        if (is_valid_char(url[i])) {
            sanitized_url[j] = url[i];
            j++;
        } else {
            char encoded_char[4];
            sprintf(encoded_char, "%%%02X", url[i]);
            strcat(sanitized_url, encoded_char);
            j += 3;
        }
    }
    
    return sanitized_url;
}

int main() {
    char url[100];
    printf("Enter a URL: ");
    scanf("%s", url);
    
    char* sanitized_url = sanitize_url(url);
    
    printf("Sanitized URL: %s\n", sanitized_url);
    
    free(sanitized_url);
    return 0;
}