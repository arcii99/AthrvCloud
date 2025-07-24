//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void sanitize_input(char *);

int main() {
    char input[100];

    printf("Enter your input: ");
    fgets(input, 100, stdin);

    sanitize_input(input);

    printf("Sanitized input: %s\n", input);

    return 0;
}

void sanitize_input(char *str) {
    int i, j;

    // Remove leading and trailing whitespaces
    while (isspace((unsigned char)*str)) {
        str++;
    }

    if (*str == 0) {
        return;
    }

    j = strlen(str) - 1;

    while (j >= 0 && isspace((unsigned char)str[j])) {
        j--;
    }

    str[j+1] = '\0';

    // Remove non-alphanumeric characters
    for (i = 0; str[i]; i++) {
        if (isalnum(str[i]) == 0) {
            memmove(&str[i], &str[i+1], strlen(str)-i);
            i--;
        }
    }

    // Convert input to lowercase
    for (i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}