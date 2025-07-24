//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1000

char* sanitize_input(char *input){
    int length = strlen(input);
    char *sanitized = (char *) malloc(length);
    int i, j = 0;
    for(i = 0; i < length; i++){
        if(input[i] == '<' || input[i] == '>'){
            continue;
        }
        sanitized[j++] = input[i];
    }
    sanitized[j] = '\0';
    return sanitized;
}

char* getInput(){
    char *input = (char *) malloc(MAX_INPUT_SIZE);
    printf("Enter your input: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input[strcspn(input, "\n")] = 0;
    return input;
}

int main()
{
    char *input = getInput();
    char *sanitized_input = sanitize_input(input);
    printf("Your input after sanitization: %s\n", sanitized_input);
    free(input);
    free(sanitized_input);
    return 0;
}