//FormAI DATASET v1.0 Category: Syntax parsing ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[50];
    printf("Enter a C syntax statement:\n");
    fgets(input, 50, stdin);        //Get input from user
    input[strcspn(input, "\n")] = 0;    //Remove newline character from input
    
    char* token = strtok(input, " ");   //Get first token from input
    int tokenCount = 0;         //Counter for number of tokens
    while(token != NULL)
    {
        //Code for Parsing and Validating Syntax of Tokens Goes Here
        
        token = strtok(NULL, " ");  //Get next token
        tokenCount++;
    }
    printf("Number of Tokens: %d\n", tokenCount);
    return 0;   //Exit program
}