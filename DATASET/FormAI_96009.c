//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* function to check if a character is a valid URL character */
int is_valid_char(char c) {
    if (c >= 'a' && c <= 'z') return 1;
    if (c >= 'A' && c <= 'Z') return 1;
    if (c >= '0' && c <= '9') return 1;
    if (c == '.' || c == '-' || c == '_' || c == '~') return 1;
    return 0;
}

/* function to sanitize a URL */
char* sanitize_url(char* url) {
    int i, j;
    char* sanitized_url = malloc(strlen(url) + 1);
    for (i = 0, j = 0; url[i] != '\0'; i++) {
        if (is_valid_char(url[i])) {
            sanitized_url[j++] = url[i];
        } else if (url[i] == ' ') {
            sanitized_url[j++] = '+';
        } else {
            sprintf(&sanitized_url[j], "%%%02X", (unsigned char) url[i]);
            j += 3;
        }
    }
    sanitized_url[j] = '\0';
    return sanitized_url;
}

/* main function */
int main() {
    char url[1024];
    printf("Enter a URL: ");
    fgets(url, 1024, stdin);
    url[strcspn(url, "\n")] = '\0';  // strip newline
    char* sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}