//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1024

// Checks if the given character is an alphanumeric character or a valid URL character, returns 1 if true, 0 otherwise
int is_valid_char(char c) {
    if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
        return 1;
    }
    return 0;
}

// Takes a string URL and sanitizes it by removing any characters that are not valid in a URL
void sanitize_url(char *url) {
    char *result = (char *)malloc(sizeof(char) * MAX_LENGTH);
    int i, j;
    for (i = 0, j = 0; i < strlen(url); i++) {
        if (is_valid_char(url[i])) {
            result[j] = url[i];
            j++;
        }
    }
    result[j] = '\0';
    strcpy(url, result);
    free(result);
}

int main() {
    char url[MAX_LENGTH];
    printf("Enter a URL: ");
    fgets(url, MAX_LENGTH, stdin);
    url[strcspn(url, "\n")] = '\0'; // Remove the newline character from the input string
    
    printf("Sanitizing the URL...\n");
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);
    
    return 0;
}