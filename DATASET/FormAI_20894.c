//FormAI DATASET v1.0 Category: Syntax parsing ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter a C syntax statement: ");
    fgets(input, sizeof(input), stdin); // get user input and store in input array

    // check if input is a variable declaration statement
    char delimiters[] = " "; // split input using spaces
    char* token = strtok(input, delimiters); // get first token
    int count = 0; // count number of tokens

    while (token != NULL) {
        if (count == 0 && strcmp(token, "int") != 0 && strcmp(token, "float") != 0 && strcmp(token, "double") != 0 && strcmp(token, "char") != 0) {
            // first token is not a valid data type
            printf("Invalid variable declaration syntax\n");
            return 0; // exit program
        }
        if (count == 1 && (strlen(token) < 2 || strncmp(token, "_", 1) == 0)) {
            // second token is not a valid variable name
            printf("Invalid variable name syntax\n");
            return 0; // exit program
        }
        if (count == 2 && strcmp(token, ";") != 0) {
            // third token is not a semicolon
            printf("Invalid variable declaration syntax\n");
            return 0; // exit program
        }
        token = strtok(NULL, delimiters); // get next token
        count++; // increment token count
    }

    // input is a valid variable declaration
    printf("Input is a valid variable declaration\n");
    return 0;
}