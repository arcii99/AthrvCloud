//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: thoughtful
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

// function to check if a character is alphanumeric
int isAlphanumeric(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

// function to check if a character is a hex digit
int isHexDigit(char c) {
    return ((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F') || (c >= '0' && c <= '9'));
}

// function to sanitize a URL
void sanitize(char *url) {
    int len = strlen(url);
    char newUrl[MAX_LEN + 1];
    int j = 0;

    for (int i = 0; i < len; i++) {
        char c = url[i];

        if (c == '%') {
            // check for percentage encoding
            if (i + 2 < len && isHexDigit(url[i+1]) && isHexDigit(url[i+2])) {
                // if valid hex number, add corresponding character to new url
                int num = 0;
                sscanf(&url[i+1], "%2x", &num);
                newUrl[j++] = (char)num;
                i += 2;
            } else {
                // invalid encoding, add % character to new url
                newUrl[j++] = c;
            }
        } else if (isAlphanumeric(c) || c == '-' || c == '_' || c == '.' || c == '/') {
            // allowed characters, add to new url
            newUrl[j++] = c;
        } else {
            // invalid character, do not add to new url
            continue;
        }

        // check if new url has exceeded the max length
        if (j >= MAX_LEN) {
            // if so, add null terminator and break
            newUrl[MAX_LEN] = '\0';
            break;
        }
    }

    // copy sanitized url back to original url string
    strcpy(url, newUrl);
}

int main() {
    char url[MAX_LEN + 1];
    printf("Enter URL:\n");
    scanf("%100s", url);

    sanitize(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}