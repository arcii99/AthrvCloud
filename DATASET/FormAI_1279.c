//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: ephemeral
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* url_sanitize(char* input) {
    char* sanitized = malloc(sizeof(char) * strlen(input) + 1);
    int sanitized_idx = 0;

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == '/') {
            sanitized[sanitized_idx] = input[i];
            sanitized_idx++;
        } else if (input[i] == '.') {
            if (i < strlen(input) - 1 && input[i+1] == '.') {
                // Parent directory, remove previous directory from sanitized
                sanitized_idx--;
                while (sanitized_idx > 0 && sanitized[sanitized_idx-1] != '/') {
                    sanitized_idx--;
                }
                i++;
            }
        } else {
            sanitized[sanitized_idx] = input[i];
            sanitized_idx++;
        }
    }

    sanitized[sanitized_idx] = '\0';
    return sanitized;
}

int main() {
    char input[100];
    printf("Please enter your URL: ");
    scanf("%s", input);
    char* sanitized = url_sanitize(input);
    printf("Sanitized URL: %s\n", sanitized);
    free(sanitized);
    return 0;
}