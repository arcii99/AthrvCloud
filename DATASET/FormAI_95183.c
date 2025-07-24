//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: mind-bending
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT 100

void sanitize_input(char *input);

int main() {
    char input[MAX_INPUT];

    printf("Enter your input: ");
    fgets(input, MAX_INPUT, stdin);
    
    sanitize_input(input);

    printf("Your sanitized input is: %s", input);

    return 0;
}

void sanitize_input(char *input) {
    char temp[MAX_INPUT];
    int i, j = 0;

    for (i = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            temp[j] = input[i];
            j++;
        }
    }

    strncpy(input, temp, j);
    input[j] = '\0';
    return;
}