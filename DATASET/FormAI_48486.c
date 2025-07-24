//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 1000

// Function to check if a character is a special character or not
int is_special_char(char c) {
    if (c >= '!' && c <= '/') { // ASCII values for special characters
        return 1;
    } else if (c >= ':' && c <= '@') {
        return 1;
    } else if (c >= '[' && c <= '`') {
        return 1;
    } else if (c >= '{' && c <= '~') {
        return 1;
    } else {
        return 0;
    }
}

// Function to remove special characters from the URL
void sanitize_url(char *url) {
    int i, j;
    for (i = 0, j = 0; url[i]; i++) {
        if (!is_special_char(url[i])) {
            url[j++] = url[i];
        }
    }
    url[j] = '\0';
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    url[strcspn(url, "\n")] = '\0'; // remove the newline character from fgets
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}