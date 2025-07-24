//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: modular
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

char* sanitize_input(char* input) {
    int input_length = strlen(input);
    char* sanitized_input = (char*) malloc(input_length * sizeof(char));

    int j = 0;
    for (int i = 0; i <= input_length; i++) {
        if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= '0' && input[i] <= '9')) {
            sanitized_input[j] = input[i];
            j++;
        }
    }

    return sanitized_input;
}

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter input: ");
    scanf("%[^\n]", input);

    char* sanitized_input = sanitize_input(input);
    printf("Sanitized input: %s", sanitized_input);

    free(sanitized_input);
    return 0;
}