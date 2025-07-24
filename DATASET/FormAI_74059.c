//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: ephemeral
#include <stdio.h>
#include <string.h>

#define INPUT_SIZE 100

char* sanitize_input(char* input) {
    int i, j;
    const char* chars_to_remove = "!@#$%^&*()_+-={}[]|\\:;\"'<>,.?/~`";
    int chars_to_remove_len = strlen(chars_to_remove);

    int input_len = strlen(input);

    // Replace all non-alpha numeric characters with a space
    for (i = 0; i < input_len; i++) {
        if (!isalnum(input[i])) {
            input[i] = ' ';
        }
    }

    // Remove any extra spaces
    for (i = 0, j = 0; input[i];) {
        while (input[i] == ' ' && input[i + 1] == ' ')
            i++;
        input[j++] = input[i++];
    }
    input[j] = '\0';

    // Remove any characters that are in chars_to_remove
    for (i = 0; i < input_len; i++) {
        for (j = 0; j < chars_to_remove_len; j++) {
            if (input[i] == chars_to_remove[j]) {
                strcpy(&input[i], &input[i + 1]);
                i--;
                input_len--;
                break;
            }
        }
    }

    // Convert the input to lowercase
    for (i = 0; i < input_len; i++) {
        input[i] = tolower(input[i]);
    }

    return input;
}

int main() {
    char input[INPUT_SIZE];
    printf("Enter your input: ");
    fgets(input, INPUT_SIZE, stdin);
    printf("Your input is: %s\n", input);
    printf("Your sanitized input is: %s\n", sanitize_input(input));
    return 0;
}