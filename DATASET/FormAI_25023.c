//FormAI DATASET v1.0 Category: System administration ; Style: creative
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
    printf("***** SYSTEM ADMINISTRATION EXAMPLE PROGRAM *****\n");
    printf("\n");

    pid_t pid;
    char *args[] = {"touch", "newfile.txt", NULL}; //creating a new file

    pid = fork(); //creating child process

    if(pid == -1) //if child process creation fails
    {
        printf("Error creating child process!\n");
        exit(EXIT_FAILURE);
    }
    else if(pid == 0) //if child process is executed successfully
    {
        execvp("touch", args); //executes the command in args array
        printf("Error executing command!\n"); //if the above command fails
        exit(EXIT_FAILURE);
    }
    else //parent process
    {
        wait(NULL); //waits for child process to terminate
        printf("New file created successfully!\n\n");
    }

    char *args2[] = {"ls", "-l", NULL}; //listing files in directory

    pid = fork(); //creating another child process

    if(pid == -1) //if child process creation fails
    {
        printf("Error creating child process!\n");
        exit(EXIT_FAILURE);
    }
    else if(pid == 0) //if child process is executed successfully
    {
        execvp("ls", args2); //executes the command in args2 array
        printf("Error executing command!\n"); //if the above command fails
        exit(EXIT_FAILURE);
    }
    else //parent process
    {
        wait(NULL); //waits for child process to terminate
        printf("\nFiles in directory listed successfully!\n\n");
    }

    char *args3[] = {"rm", "newfile.txt", NULL}; //deleting the new file created earlier

    pid = fork(); //creating another child process

    if(pid == -1) //if child process creation fails
    {
        printf("Error creating child process!\n");
        exit(EXIT_FAILURE);
    }
    else if(pid == 0) //if child process is executed successfully
    {
        execvp("rm", args3); //executes the command in args3 array
        printf("Error executing command!\n"); //if the above command fails
        exit(EXIT_FAILURE);
    }
    else //parent process
    {
        wait(NULL); //waits for child process to terminate
        printf("New file deleted successfully!\n\n");
    }

    printf("***** EXAMPLE PROGRAM ENDS HERE *****\n");

    return 0;
}