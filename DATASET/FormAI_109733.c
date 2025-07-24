//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: configurable
//This is a Unix-like shell implementation written in C with configurable prompt and commands.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_SIZE 100 //Maximum size of a command
#define MAX_ARGS 10 //Maximum number of arguments in a command
#define MAX_PATH_SIZE 100 //Maximum size of a path

void printPrompt(char* prompt); //Function to print the shell prompt
void readCommand(char* command[], char* prompt); //Function to read the input command and separate it into arguments
void executeCommand(char* command[], char* path); //Function to execute the command
int isExecutable(char* path, char* command); //Function to check if the command is executable
char* getPath(char* paths[]); //Function to get the path from the environment variable PATH

int main(int argc, char const *argv[])
{
    char* prompt = "> ";
    char* paths[] = {"/bin"}; //Default path

    while(1) //Loop until exit command is encountered
    {
        printPrompt(prompt);
        char* command[MAX_ARGS + 1]; //Command array containing the arguments, plus one for NULL
        readCommand(command, prompt);
        if(strcmp(command[0], "exit") == 0) break; //Exit command encountered
        char* path = getPath(paths);
        executeCommand(command, path);
    }

    return 0;
}

void printPrompt(char* prompt)
{
    printf("%s", prompt);
}

void readCommand(char* command[], char* prompt)
{
    char buffer[MAX_COMMAND_SIZE];
    fgets(buffer, sizeof(buffer), stdin);
    strtok(buffer, "\n"); //Remove newline character
    char* token = strtok(buffer, " ");
    int i = 0;
    while(token != NULL && i < MAX_ARGS)
    {
        command[i++] = token;
        token = strtok(NULL, " ");
    }
    command[i] = NULL; //Last argument should be NULL to indicate end of arguments
}

void executeCommand(char* command[], char* path)
{
    char fullPath[MAX_PATH_SIZE];
    while(*command != NULL)
    {
        if(isExecutable(path, *command))
        {
            sprintf(fullPath, "%s/%s", path, *command);
            pid_t pid = fork();
            if(pid == 0)
            {
                execv(fullPath, command);
            }
            else
            {
                wait(NULL); //Wait for child process to finish
                break; //Go to next command if there are any other commands in the arguments
            }
        }
        path = strtok(NULL, ":");
        if(path == NULL) path = ""; //Path is empty string if there are no more paths in the environment variable
    }
}

int isExecutable(char* path, char* command)
{
    char fullPath[MAX_PATH_SIZE];
    sprintf(fullPath, "%s/%s", path, command);
    if(access(fullPath, X_OK) == 0) return 1;
    return 0;
}

char* getPath(char* paths[])
{
    return paths[0]; //For now, return the first path in the array
}