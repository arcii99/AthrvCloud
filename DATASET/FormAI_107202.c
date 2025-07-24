//FormAI DATASET v1.0 Category: System administration ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    printf("Welcome to the System Administration Example Program!\n");
    printf("------------------------\n");

    //User Input
    char command[100];
    printf("Enter the command to be executed: ");
    fgets(command,100,stdin);
    
    //Executing System Command
    printf("\nExecuting System Command...\n");
    system(command);
    
    printf("\n------------------------");
    printf("\nSystem Command Successfully Executed!\n");

    //System Status Information
    printf("\n------------------------\n");
    printf("System Status Information\n");
    printf("------------------------\n");

    //Current User
    char* user = getenv("USER");
    printf("Current User: %s\n",user);

    //Current Working Directory
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
        printf("Current Working Directory: %s\n",cwd);

    //System Uptime
    printf("System Uptime: ");
    fflush(stdout);
    system("uptime");

    //Memory Usage
    printf("Memory Usage: ");
    fflush(stdout);
    system("free -m");

    //CPU Information
    printf("CPU Information: ");
    fflush(stdout);
    system("cat /proc/cpuinfo");

    //Disk Usage
    printf("Disk Usage: ");
    fflush(stdout);
    system("df -h");

    //Network Information
    printf("Network Information: ");
    fflush(stdout);
    system("ifconfig");

    printf("\n------------------------");
    printf("\nEnd of System Status Information\n");

    return 0;
}