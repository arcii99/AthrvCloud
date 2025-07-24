//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_URL_LENGTH 256

int contains(char* str, char c) {
    if (str == NULL) {
        return 0;
    }
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == c) {
            return 1;
        }
    }
    return 0;
}

void sanitize(char* url, char* sanitized, int sanitized_length) {
    if (contains(url, '<') || contains(url, '>')) {
        printf("The URL contains an invalid character!");
        return;
    }

    if (strlen(url) + 1 > sanitized_length) {
        printf("The URL is too long!");
        return;
    }

    int current_position = 0;
    for (int i = 0; i < strlen(url); i++) {
        char current_char = url[i];

        if (contains(url, '%')) {
            if (i + 2 >= strlen(url)) {
                printf("Malformed encoded character!");
                return;
            }

            char code[MAX_URL_LENGTH];
            code[0] = current_char;
            code[1] = url[i + 1];
            code[2] = url[i + 2];
            code[3] = '\0';

            int code_value = strtol(code + 1, NULL, 16);
            if (code_value <= 32 || code_value > 126) {
                printf("The URL contains encoded invalid characters!");
                return;
            }
            sanitized[current_position] = code_value;
            i += 2;
            current_position++;
            continue;
        }

        if (current_char == '+') {
            sanitized[current_position] = ' ';
        } else {
            sanitized[current_position] = current_char;
        }
        current_position++;
    }
    sanitized[current_position] = '\0';
}

int main() {
    char url[MAX_URL_LENGTH];
    fgets(url, MAX_URL_LENGTH, stdin);
    url[strcspn(url, "\n")] = '\0';

    char sanitized[MAX_URL_LENGTH];
    sanitize(url, sanitized, MAX_URL_LENGTH);

    printf("Sanitized URL: %s", sanitized);

    return 0;
}