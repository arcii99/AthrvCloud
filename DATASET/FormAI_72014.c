//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

void sanitize_input(char input[], char sanitized_input[]) {
    int input_length = strlen(input);
    int j = 0;
    for(int i = 0; i < input_length; i++) {
        if((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= '0' && input[i] <= '9')) {
            sanitized_input[j] = input[i];
            j++;
        }
    }
    sanitized_input[j] = '\0';
}

int main() {
    char input[100];
    char sanitized_input[100];
    printf("Enter your input:\n");
    fgets(input, 100, stdin);
    sanitize_input(input, sanitized_input);
    printf("Sanitized input: %s\n", sanitized_input);
    return 0;
}