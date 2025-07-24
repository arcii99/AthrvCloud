//FormAI DATASET v1.0 Category: Syntax parsing ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

char* removeWhitespace(char* str) {
    int i, j;
    char* output = malloc(sizeof(char) * MAX_LENGTH);

    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
            output[j] = str[i];
            j++;
        }
    }

    output[j] = '\0';
    return output;  
}

int main() {
    char input[MAX_LENGTH];
    char* noWhitespace;
    int i;

    printf("Enter C syntax: ");
    fgets(input, MAX_LENGTH, stdin);

    noWhitespace = removeWhitespace(input);

    printf("The syntax without whitespace: %s\n", noWhitespace);
    free(noWhitespace);

    return 0;
}