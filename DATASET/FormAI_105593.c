//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: romantic
#include <stdio.h>
#include <string.h>

void sanitize_url(char* url) {
    char* prefix = "http://";
    char* secure_prefix = "https://";
    int prefix_len = strlen(prefix);
    int secure_prefix_len = strlen(secure_prefix);
    if (strncmp(url, prefix, prefix_len) != 0 && strncmp(url, secure_prefix, secure_prefix_len) != 0) {
        // Add "http://" prefix to the URL
        char* new_url = malloc(strlen(url) + prefix_len + 1);
        strcpy(new_url, prefix);
        strcat(new_url, url);
        url = new_url;
    }
}

int main() {
    char* url = "google.com";
    printf("Before sanitization: %s\n", url);
    sanitize_url(url);
    printf("After sanitization: %s\n", url);
    free(url);
    return 0;
}