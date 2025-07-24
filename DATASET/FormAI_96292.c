//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

// Max length of command
#define MAX_LEN 1024

// Max length of arguments
#define MAX_ARGS 64

void grateful_prompt()
{
    printf("\nThank you for using Grateful shell!\n");
    printf("Enter your command: ");
}

int grateful_getargs(char* line, char** argv)
{
    int argc = 0;
    char* token;

    token = strtok(line, " ");
    while(token != NULL && argc < MAX_ARGS) {
        argv[argc++] = token;
        token = strtok(NULL, " ");
    }
    argv[argc] = NULL;
    return argc;
}

void grateful_execute(char** argv)
{
    pid_t pid;

    pid = fork();

    if (pid == 0) 
    { 
        if (execvp(argv[0], argv) < 0) 
        {
            printf("\nGrateful: Command not found.\n");
            exit(0);
        }
    }
    else 
    { 
        wait(NULL); 
    } 
}

int main()
{
    char line[MAX_LEN];     // line of input
    char* argv[MAX_ARGS];   // pointers to arguments
    int argc;               // number of arguments entered
    int status;

    printf("Welcome to Grateful shell!\n");

    do
    {
        grateful_prompt();
        fflush(stdout);
        fgets(line, MAX_LEN, stdin);
        argc = grateful_getargs(line, argv);

        if (argc == 0)
        {
            printf("\nPlease enter a valid command. Thank you!\n");
            continue;
        }
        else if (strcmp(argv[0], "exit") == 0)
        {
            printf("\nThank you for using Grateful shell! Goodbye :)\n");
            break;
        }
        else if (strcmp(argv[0], "grateful") == 0)
        {
            printf("\nThank you for using Grateful shell! You're welcome :)\n");
            continue;
        }
        else
        {
            grateful_execute(argv);
        }

    } while (status);

    return 0;
}