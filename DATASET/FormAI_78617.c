//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sanitize_input(char *input) {
    char *p = input;
    while (*input) {
        if (isalnum(*input)) {
            *p++ = *input;
        }
        input++;
    }
    *p = '\0';
}

int main() {
    char input[100];
    printf("Enter input:\n");
    fgets(input, 100, stdin);
    
    printf("Your original input was: %s\n", input);
    sanitize_input(input);
    printf("Your sanitized input is: %s\n", input);
    
    return 0;
}