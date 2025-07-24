//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
    printf("Enter a string to sanitize: \n");
    char input[100];
    fgets(input, 100, stdin);

    for(int i = 0; i < strlen(input); i++) {
        if(ispunct(input[i])) {
            input[i] = ' ';
        }
    }
    for(int i = 0; i < strlen(input); i++) {
        if(!isalnum(input[i])) {
            input[i] = ' ';
        }
    }

    char *tokens[100];
    char *ptr = strtok(input, " ");

    int token_count = 0;
    while(ptr != NULL) {
        tokens[token_count] = ptr;
        token_count++;
        ptr = strtok(NULL, " ");
    }

    printf("Cleaned string: ");
    for (int i = 0; i < token_count; i++) {
        printf("%s ", tokens[i]);
    }
    printf("\n");

    return 0;
}