//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 256

void sanitize_input(char *input);

int main() {
    char input[MAX_LENGTH];
    printf("Enter your input: ");
    fgets(input, sizeof(input), stdin);

    sanitize_input(input);

    printf("Your sanitized input is: %s\n", input);

    return 0;
}

void sanitize_input(char *input) {
    int i = 0;
    int j = 0;
    while (input[i] != '\0') {
        if (input[i] == '\n') {
            input[i] = '\0';
            break;
        }
        else if (input[i] >= 32 && input[i] <= 126) {
            input[j] = input[i];
            j++;
        }
        i++;
    }
    input[j] = '\0';
}