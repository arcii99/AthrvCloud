//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 256

void sanitize_input(char *input) {
    int i;
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == '<' || input[i] == '>') {
            input[i] = ' ';
        }
        if (!isprint(input[i])) {
            input[i] = ' ';
        }
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter User Input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    sanitize_input(input);
    printf("Sanitized User Input: %s\n", input);
    return 0;
}

/*
Sample Input: Hello! <script>alert("Hello, World!");</script> How are you today?
Sample Output: Hello!  alert("Hello, World!");  How are you today?
*/