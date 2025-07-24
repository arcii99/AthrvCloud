//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[100];
    printf("Enter your input: ");
    fgets(input, sizeof(input), stdin); // gets user input
    int len = strlen(input);
    if (input[len-1] == '\n') {
        input[len-1] = '\0'; // remove newline character from input
    }
    char sanitized[100];
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (isalnum(input[i])) {
            sanitized[j++] = input[i]; // copy alphanumeric characters to sanitized string
        }
    }
    sanitized[j] = '\0'; // add null terminator to sanitized string
    printf("Sanitized input: %s\n", sanitized); // print sanitized input
    return 0;
}