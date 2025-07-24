//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    int pid = fork();

    if(pid == -1)
    {
        //if the fork() system call fails
        printf("Error: Failed to fork.\n");
        exit(1);
    }
    else if(pid == 0)
    {
        //this is the child process
        while(1)
        {
            //print the current CPU usage of the process
            system("top -bn1 | grep \"Cpu(s)\" >> cpu_usage.txt");
            //wait for 1 second
            sleep(1);
        }
    }
    else
    {
        //this is the parent process
        pid_t child_pid;
        int status;

        //wait for the child process to terminate
        child_pid = wait(&status);
        //display the contents of the file
        printf("CPU usage:\n");
        system("cat cpu_usage.txt");
        //delete the file
        system("rm cpu_usage.txt");
    }

    return 0;
}