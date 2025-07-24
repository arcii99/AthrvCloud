//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: sophisticated
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Please enter your input:\n");
    fgets(input, 100, stdin);
    // Scan for any malicious or unwanted characters
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == '<' || input[i] == '>' || input[i] == '&' || input[i] == '$') {
            // Remove the char if it is malicious
            memmove(&input[i], &input[i+1], strlen(input) - i);
            i--;
        }
    }
    printf("The sanitized input is:\n%s", input);
    return 0;
}