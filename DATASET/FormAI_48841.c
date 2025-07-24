//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: peaceful
#include <stdio.h>
#include <ctype.h>

void sanitize_input(char* str);

int main() {
    char input[100];
    printf("Enter input: ");
    fgets(input, 100, stdin);
    sanitize_input(input);
    printf("Sanitized input: %s\n", input);
    return 0;
}

void sanitize_input(char* str) {
    char* original = str;
    while (*str) {
        if (isalnum(*str) || *str == ' ') {
            *original++ = *str;
        }
        str++;
    }
    *original = '\0';
}