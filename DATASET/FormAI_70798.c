//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: decentralized
#include <stdio.h>
#include <string.h>

// function to sanitize URL
char* sanitize_url(char* url) {
    // check if url is empty
    if (strlen(url) == 0) {
        return url;
    }

    // check for any spaces in the URL
    char* p = strchr(url, ' ');
    if (p != NULL) {
        *p = '+';
    }

    // check for any special characters in the URL
    char special_chars[13] = { '%', '&', '?', '#', '@', '~', '[', ']', '{', '}', '|', '\\' };
    for (int i = 0; i < strlen(url); i++) {
        for (int j = 0; j < 13; j++) {
            if (url[i] == special_chars[j]) {
                url[i] = '_';
            }
        }
    }

    // check if url ends with '/'
    int last_char = strlen(url) - 1;
    if (url[last_char] == '/') {
        url[last_char] = '\0';
    }

    return url;
}

// main function
int main() {
    char url[500] = "https://example[dot]com?param=1&data=hello world#fragment";
    printf("Original URL: %s\n", url);

    // sanitize URL
    char* sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);

    return 0;
}