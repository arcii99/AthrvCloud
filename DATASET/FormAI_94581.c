//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
Function to remove any non-alphanumeric characters from the input string and convert it to lowercase
*/
char *sanitizeInput(char *input) {
    char *sanitizedInput = (char*)malloc(strlen(input) * sizeof(char));
    memset(sanitizedInput, '\0', strlen(input));
    int j = 0;
    for(int i = 0; i < strlen(input); i++) {
        if(isalnum(input[i])) {
            sanitizedInput[j++] = tolower(input[i]);
        }
    }
    return sanitizedInput;
}

int main() {
    char input[100];
    printf("Enter the input string: ");
    scanf("%[^\n]", input);
    char *sanitizedInput = sanitizeInput(input);
    printf("Sanitized Input: %s\n", sanitizedInput);
    free(sanitizedInput);
    return 0;
}