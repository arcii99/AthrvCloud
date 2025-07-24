//FormAI DATASET v1.0 Category: Word Count Tool ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void countWords(char *str)
{
    int count = 0;
    char *token = strtok(str, " ");
    
    while (token != NULL)
    {
        count++;
        token = strtok(NULL, " ");
    }
    
    printf("Total words in the input string: %d\n", count);
}

int main()
{
    char input[MAX_SIZE];
    
    printf("Enter a string (max 1000 characters): \n");
    fgets(input, MAX_SIZE, stdin);
    
    if (strlen(input) > 1)
    {
        if (input[strlen(input) - 1] == '\n')
        {
            input[strlen(input) - 1] = '\0';
        }
    }
    
    countWords(input);
    
    return 0;
}