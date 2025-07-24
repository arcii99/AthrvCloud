//FormAI DATASET v1.0 Category: System administration ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char command[100];
    printf("Enter a command: ");
    scanf("%s", command);

    if(strcmp(command, "shutdown") == 0)
    {
        system("shutdown -P now");
    }
    else if(strcmp(command, "reboot") == 0)
    {
        system("reboot");
    }
    else if(strcmp(command, "diskusage") == 0)
    {
        system("df -h");
    }
    else if(strcmp(command, "processlist") == 0)
    {
        system("ps -A");
    }
    else if(strcmp(command, "networkinfo") == 0)
    {
        system("ifconfig");
    }
    else if(strcmp(command, "users") == 0)
    {
        system("who");
    }
    else
    {
        printf("Invalid command\n");
    }

    return 0;
}