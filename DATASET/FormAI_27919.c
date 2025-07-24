//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void sanitize(char *input);

int main() {
    char userInput[100];
    printf("Enter your input: ");
    fgets(userInput, sizeof(userInput), stdin);
    sanitize(userInput);
    printf("Your sanitized input is: %s", userInput);
    return 0;
}

void sanitize(char *input) {
    int len = strlen(input); // get length of input
    char *newInput = (char*) malloc(sizeof(char) * len); // allocate memory for new input
    int j = 0;

    for (int i = 0; i < len; i++) {
        if (!isspace(input[i])) { // check if character is not whitespace
            newInput[j] = input[i];
            j++;
        }
    }

    newInput[j] = '\0'; // add string termination at the end
    strcpy(input, newInput); // copy new input back to original input
    free(newInput); // free allocated memory
}