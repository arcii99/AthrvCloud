//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: portable
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void sanitize_input(char *input) {
    // Remove leading and trailing whitespaces
    int i;
    int len = strlen(input);
    while (isspace(input[0])) {
        for (i = 0; i < len; i++) {
            input[i] = input[i + 1];
        }
        len--;
    }
    while (isspace(input[len - 1]) && len>0) {
        input[len - 1] = '\0';
        len--;
    }
    
    // Replace multiple spaces with a single space
    int j;
    for (i = 0, j = 0; input[i]; i++) {
        if (!isspace(input[i]) || (i > 0 && !isspace(input[i - 1]))) {
            input[j++] = input[i];
        }
    }
    input[j] = '\0';
    
    // Convert all characters to lowercase
    for (i = 0; input[i]; i++) {
        input[i] = tolower(input[i]);
    }
}

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    sanitize_input(input);
    printf("Sanitized input: %s\n", input);

    return 0;
}