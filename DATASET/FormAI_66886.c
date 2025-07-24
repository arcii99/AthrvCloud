//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

char* sanitize_input(char* str);

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter a string: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    char* sanitized_str = sanitize_input(input);
    printf("The sanitized string is: %s\n", sanitized_str);
    free(sanitized_str);
    return 0;
}

char* sanitize_input(char* str) {
    int length = strlen(str);
    char* sanitized_str = (char*)malloc(sizeof(char)*(length+1));

    int i, j;
    for (i = 0, j = 0; i < length; i++) {
        char c = str[i];
        if (isalnum(c) || isspace(c)) {
            sanitized_str[j] = c;
            j++;
        }
    }

    sanitized_str[j] = '\0';
    return sanitized_str;
}