//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 256 // maximum length of a URL

bool is_valid_char(char c) {
    // check if character is a valid URL character
    if (c >= 'a' && c <= 'z') {
        return true;
    } else if (c >= 'A' && c <= 'Z') {
        return true;
    } else if (c >= '0' && c <= '9') {
        return true;
    } else if (c == ':') {
        return true;
    } else if (c == '/') {
        return true;
    } else if (c == '.') {
        return true;
    } else if (c == '-') {
        return true;
    } else if (c == '_') {
        return true;
    } else {
        return false;
    }
}

void sanitize_url(char *url) {
    char sanitized_url[MAX_URL_LENGTH] = "";
    int sanitized_url_length = 0;

    for (int i = 0; i < strlen(url); i++) {
        if (is_valid_char(url[i])) {
            // if character is valid, add to sanitized URL
            sanitized_url[sanitized_url_length++] = url[i];
        }
    }

    // set sanitized URL
    strcpy(url, sanitized_url);
}

int main() {
    char url[MAX_URL_LENGTH] = "https://www.example.com/ <p>test</p> ?q=123"; // sample URL with HTML tags and query string

    printf("Original URL: %s\n", url);
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);

    return 0;
}