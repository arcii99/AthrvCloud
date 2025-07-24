//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKENS 100

void tokenize(char *line, char **argv)
{
    while (*line != '\0') 
    {       
        while (*line == ' ' || *line == '\t' || *line == '\n')
        {
            *line++ = '\0';
        }       

        *argv++ = line;         

        while (*line != '\0' && *line != ' ' && *line != '\t' && *line != '\n') 
        {
            line++;
        }       
    }
    *argv = '\0';                 
}

int main() 
{
    char input[MAX_INPUT_SIZE];
    char *tokens[MAX_TOKENS];

    while (1) 
    {
        printf("$ ");
        fgets(input, MAX_INPUT_SIZE, stdin);
        if (strlen(input) == 1) 
        {
            continue;
        }
        tokenize(input, tokens);
        
        int pid = fork();
        if (pid == 0) 
        {
            execvp(tokens[0], tokens);
            printf("%s: command not found\n", tokens[0]);
            exit(0);
        }
        else 
        {
            wait(NULL);
        }
    }
    return 0;
}