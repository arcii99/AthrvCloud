//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LEN 1000

int main() {

    char input[MAX_INPUT_LEN], sanitized[MAX_INPUT_LEN];
    int i, j, len;

    printf("Enter URL: ");
    fgets(input, sizeof(input), stdin);
    len = strlen(input);

    printf("Original URL: %s", input);

    // Remove whitespace from the beginning and end of the input
    while(input[0] == ' ') {
        len--;
        for(i = 0; i < len; i++) {
            input[i] = input[i+1];
        }
    }

    while(input[len-1] == ' ') {
        len--;
        input[len] = '\0';
    }

    // Sanitize the URL
    j = 0;
    for(i = 0; i < len; i++) {
        if(input[i] == '<' || input[i] == '>' || input[i] == '\'' || input[i] == '\"' || input[i] == '(' || input[i] == ')' || input[i] == '{' || input[i] == '}' || input[i] == '[' || input[i] == ']' || input[i] == '|' || input[i] == '`' || input[i] == '&' || input[i] == ' ' || input[i] == '\\') {
            continue;
        } else {
            sanitized[j] = input[i];
            j++;
        }
    }

    sanitized[j] = '\0';

    printf("Sanitized URL: %s", sanitized);

    return 0;
}