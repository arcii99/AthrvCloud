//FormAI DATASET v1.0 Category: Syntax parsing ; Style: artistic
// Rising Sun Syntax Parser 
// by Artistico

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char token[50]; // for storing tokens
    char input[200]; // for storing user input
    int i, j; // for iteration

    printf("Welcome to the Rising Sun Syntax Parser!\n");
    printf("Please enter your code:\n");
    fgets(input, 200, stdin); // gets input from user

    // Removing unnecessary whitespaces from input
    i = 0; // tracking current index
    j = 0; // tracking updated index
    while (input[i] != '\0') {
        if (input[i] != ' ' && input[i] != '\t' && input[i] != '\n') { // if not whitespace
            if (input[i] == ';') { // if semicolon, add space before it
                token[j++] = ' ';
            }
            token[j++] = input[i];
        }
        i++;
    }
    token[j] = '\0'; // end token string with null terminator

    printf("\n");

    // Parsing token string
    char* delimiter = " ";
    char* ptr = strtok(token, delimiter);
    printf("Parsed Tokens:\n");
    while (ptr != NULL) {
        printf("%s\n", ptr);
        ptr = strtok(NULL, delimiter);
    }

    printf("\n");
    printf("Thank you for using the Rising Sun Syntax Parser!\n");

    return 0;
}