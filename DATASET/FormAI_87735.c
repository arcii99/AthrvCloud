//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LEN 256

char input[MAX_INPUT_LEN];

void sanitize_input(char *input)
{
    size_t len = strlen(input);
    char sanitized_input[MAX_INPUT_LEN];
 
    for (size_t i = 0; i < len; i++) {
        if (isalnum(input[i]) || input[i] == '_' || input[i] == '-') {
            sanitized_input[i] = input[i];
        } else {
            sanitized_input[i] = '_';
        }
    }
    sanitized_input[len] = '\0';
    strcpy(input, sanitized_input);
}

int main(int argc, char *argv[])
{
    printf("Enter username: ");
    fgets(input, MAX_INPUT_LEN, stdin);

    sanitize_input(input);

    printf("Sanitized username: %s\n", input);

    return 0;
}