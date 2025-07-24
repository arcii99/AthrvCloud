//FormAI DATASET v1.0 Category: Syntax parsing ; Style: all-encompassing
#include<stdio.h>
#include<ctype.h>
#include<string.h>

void parse(char *str) {
    char *token;
    int i=1;

    token = strtok(str, " "); // tokenize the string by spaces

    while (token != NULL) {
        printf("Token %d: %s\n", i, token); // print the token and its index
        if (isdigit(token[0])) {
            printf("  Type: Number\n"); // if the token starts with a digit, it's a number
        } else {
            printf("  Type: Identifier\n"); // otherwise, it's an identifier
        }
        token = strtok(NULL, " "); // set token to the next token in the string
        i++;
    }
}

int main() {
    char str[100];
    printf("Enter a string to parse: ");
    fgets(str, sizeof(str), stdin); // read the string from user input
    str[strcspn(str, "\n")] = 0; // remove trailing newline character from input

    parse(str); // call the parse function on the input string

    return 0;
}