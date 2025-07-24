//FormAI DATASET v1.0 Category: Text processing ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char userInput[100];
    char *token;
    char *delimiter = " ";
    int count = 0;

    printf("Enter a sentence (maximum 100 characters): ");
    fgets(userInput, 100, stdin);
    
    // Remove trailing newline character
    if(userInput[strlen(userInput) - 1] == '\n')
        userInput[strlen(userInput) - 1] = '\0';
    
    // Calculate number of words in sentence
    for(int i = 0; i < strlen(userInput); i++)
    {
        if(userInput[i] == ' ')
            count++;
    }
    count++; // Account for last word in sentence

    printf("You entered: %s\n", userInput);
    printf("Number of words in sentence: %d\n", count);

    // Tokenize sentence and print each word
    token = strtok(userInput, delimiter);
    printf("Words in sentence: ");
    while(token != NULL)
    {
        printf("%s ", token);
        token = strtok(NULL, delimiter);
    }
    
    return 0;
}