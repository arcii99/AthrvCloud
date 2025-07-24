//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

char sanitize_input(char* input) {
    char sanitized_input[MAX_SIZE];
    int i = 0;
    int j = 0;

    while (input[i]) {
        if ((input[i] >= 'A' && input[i] <= 'Z') || 
            (input[i] >= 'a' && input[i] <= 'z') || 
            (input[i] >= '0' && input[i] <= '9')) {
            sanitized_input[j++] = input[i];
        }
        i++;
    }

    sanitized_input[j] = '\0';
    strcpy(input, sanitized_input);
    return *input;
}

int main() {
    char user_input[MAX_SIZE];

    printf("Enter string: ");
    fgets(user_input, MAX_SIZE, stdin);
    user_input[strlen(user_input) - 1] = '\0';

    sanitize_input(user_input);

    printf("Sanitized Input: %s\n", user_input);

    return 0;
}