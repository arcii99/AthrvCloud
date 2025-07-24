//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void sanitize(char * input);

int main() {
    char input[100];
    printf("Enter some input: ");
    fgets(input, sizeof(input), stdin);
    sanitize(input);
    printf("Sanitized input: %s", input);
    return 0;
}

void sanitize(char * input) {
    int length = strlen(input);
    char * new_input = (char*) malloc(length * sizeof(char));
    int new_length = 0;
    for (int i = 0; i < length; i++) {
        if (isalnum(input[i])) {
            new_input[new_length++] = input[i];
        }
    }
    new_input[new_length] = '\0';
    strcpy(input, new_input);
    free(new_input);
}