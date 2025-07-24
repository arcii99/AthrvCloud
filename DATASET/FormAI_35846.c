//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

void sanitize_input(char *input) {
    int i, j = 0;
    char temp[MAX_INPUT_LENGTH];

    for (i = 0; input[i] != '\0'; i++) {
        if ((input[i] >= 'A' && input[i] <= 'Z') ||
            (input[i] >= 'a' && input[i] <= 'z') ||
            (input[i] >= '0' && input[i] <= '9')) {
            temp[j++] = input[i];
        }
    }

    temp[j] = '\0';

    strcpy(input, temp);
}

int main() {
    char input[MAX_INPUT_LENGTH] = {'\0'};

    printf("Enter your input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    sanitize_input(input);

    printf("Your sanitized input is: %s\n", input);

    return 0;
}