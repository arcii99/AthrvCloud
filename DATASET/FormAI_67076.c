//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: thoughtful
#include <stdio.h>
#include <string.h>

#define MAX_INPUT 256

void sanitize_input(char* input) {
    int input_length = strlen(input);

    for(int i = 0; i < input_length; i++) {
        if(input[i] == '<') {
            input[i] = '(';
        } else if (input[i] == '>') {
            input[i] = ')';
        } else if (input[i] == '\"') {
            input[i] = '\'';
        } else if (input[i] == '/') {
            input[i] = '\\';
        }
    }
}

int main(void) {
    char user_input[MAX_INPUT];
    printf("Enter some input: ");
    fgets(user_input, MAX_INPUT, stdin);
    sanitize_input(user_input);
    printf("The sanitized input is: %s", user_input);
    return 0;
}