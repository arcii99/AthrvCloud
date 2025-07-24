//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: high level of detail
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 256

void sanitize_input(char* input) {
    // Remove leading and trailing white spaces
    int len = strlen(input);
    int start = 0;
    int end = len - 1;
    while (isspace(input[start])) {
        start++;
    }
    while (isspace(input[end])) {
        end--;
    }
    input[end+1] = '\0';
    memmove(input, &input[start], end-start+2);
    
    // Remove non-alphanumeric characters
    char sanitized_input[MAX_INPUT_LENGTH];
    int i = 0, j = 0;
    while (input[i]) {
        if (isalnum(input[i])) {
            sanitized_input[j] = input[i];
            j++;
        }
        i++;
    }
    sanitized_input[j] = '\0';
    strcpy(input, sanitized_input);
}

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter a string to sanitize:");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    sanitize_input(input);
    printf("Sanitized string: %s", input);
    return 0;
}