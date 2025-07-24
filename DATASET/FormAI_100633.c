//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: surprised
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 256

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter your input: ");

    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Sanitize input to remove unsafe characters
    for(int i = 0; i < strlen(input); i++) {
        if(!isalnum(input[i])) {
            input[i] = '_'; // Replace non-alphanumeric characters with underscore
        }
    }
    
    printf("Your sanitized input: %s", input);

    return 0;
}