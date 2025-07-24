//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

void sanitizeInput(char input[]) {
    int length = strlen(input);
    int i;
    for(i = 0; i < length; i++) {
        if(isalpha(input[i]) || isdigit(input[i])) {
            input[i] = tolower(input[i]);
        } else {
            input[i] = ' ';
        }
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    sanitizeInput(input);
    printf("Sanitized input: %s", input);
    return 0;
}