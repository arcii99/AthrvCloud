//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Claude Shannon
/* 
* C User Input Sanitizer Example Program
* by Claude Shannon
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

void sanitizeInput(char *input) {
    char sanitized_input[MAX_INPUT_LENGTH] = {0};
    int index = 0;

    for(int i = 0; i < strlen(input); i++) {
        if(isalnum(input[i])) {
            sanitized_input[index] = input[i];
            index++;
        }
    }

    strcpy(input, sanitized_input);
}

int main() {
    char user_input[MAX_INPUT_LENGTH];
    printf("Enter some text with unwanted characters: ");
    fgets(user_input, MAX_INPUT_LENGTH, stdin);

    if(user_input[strlen(user_input) - 1] == '\n') {
        user_input[strlen(user_input) - 1] = '\0';
    }

    sanitizeInput(user_input);
    printf("Sanitized input: %s\n", user_input);

    return 0;
}