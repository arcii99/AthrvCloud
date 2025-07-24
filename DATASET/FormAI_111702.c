//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

void sanitizeInput(char *input);

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Please enter your input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    sanitizeInput(input);
    printf("Your sanitized input is: %s", input);
    return 0;
}

void sanitizeInput(char *input) {
    int length = strlen(input);
    char *temp = (char*)malloc( sizeof(char)*(length+1) );
    int index = 0;

    for (int i = 0; i < length; i++) {
        if (isalnum(input[i]) || isspace(input[i])) {
            temp[index] = input[i];
            index++;
        } else if (input[i] == '\n') {
            break;
        }
    }
    temp[index] = '\0';
    strcpy(input, temp);
    free(temp);
}