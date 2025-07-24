//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
    char command[100];
    pid_t pid;

    printf("My love, what do you want me to do?\n");
    while(1)
    {
        printf("My love> ");
        fgets(command, 100, stdin);
        command[strcspn(command, "\n")] = 0; // remove the newline character from input

        if(strcmp(command, "exit") == 0) // if the user enters "exit", exit the while loop
        {
            break;
        }

        pid = fork(); // create child process
        if(pid == 0) // if the child process was successfully created
        {
            if(system(command) == -1) // execute the command entered by the user
            {
                printf("My love, there was an error executing the command.\n");
            }
            exit(EXIT_SUCCESS);
        }
        else if(pid < 0) // if the child process creation failed
        {
            printf("My love, there was an error creating a child process.\n");
        }
        else // if the parent process was successfully created
        {
            wait(NULL); // wait for child process to complete
        }
    }

    printf("My love, I am going to miss you...\n");
    return 0;
}