//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void sanitize(char *input, char *output, int length) {
    int i, j;
    char c;
    for (i = 0, j = 0; i < length; i++) {
        c = input[i];
        if (isalnum(c) || c == ' ' || c == '-' || c == '.' || c == '@') {
            output[j] = c;
            j++;
        }
    }
    output[j] = '\0';
}

int main(void) {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    int length;
    printf("Enter a string with special characters: ");
    fgets(input, MAX_LENGTH, stdin);
    length = strlen(input) - 1;
    sanitize(input, output, length);
    printf("Original string: %s", input);
    printf("Sanitized string: %s", output);
    return 0;
}