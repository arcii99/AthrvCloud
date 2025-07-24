//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter a C syntax statement:\n");
    fgets(input, 100, stdin); //Read statement from user input

    //Remove new line character from input
    if (input[strlen(input)-1] == '\n') {
        input[strlen(input)-1] = '\0';
    }

    int numTokens = 1; //Number of tokens in the statement (initially 1)
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ' || input[i] == '\t') {
            numTokens++; //Count the number of spaces/tabs to determine number of tokens
        }
    }

    char **tokens = (char **)malloc(numTokens * sizeof(char *)); //Dynamically allocate memory for tokens
    char *token = strtok(input, " \t"); //Tokenize statement by spaces and tabs

    int i = 0;
    while (token != NULL) {
        tokens[i] = token; //Add token to array
        token = strtok(NULL, " \t");
        i++;
    }

    printf("Your statement contains %d tokens:\n", numTokens);
    for (int j = 0; j < numTokens; j++) {
        printf("%d. %s\n", j+1, tokens[j]); //Print each token and its position
    }

    //Free memory allocated for tokens
    for (int k = 0; k < numTokens; k++) {
        free(tokens[k]);
    }
    free(tokens);

    return 0;
}