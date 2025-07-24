//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_SIZE 1024

int main()
{
    char command[MAX_SIZE];
    char buf[MAX_SIZE];
    int ram_usage = 0;
    int count = 0;

    while(1)
    {
        sprintf(command,"ps aux | grep $(whoami) | grep -v grep | awk '{print $4}'");

        FILE *fp = popen(command, "r");

        if (fp == NULL)
        {
            printf("Failed to run command\n" );
            exit(1);
        }

        while (fgets(buf, MAX_SIZE, fp) != NULL)
        {
            count++;
            if(count > 1)
            {
                ram_usage = atoi(buf);
                printf("Current RAM usage: %d%%\n", ram_usage);
            }
        }

        pclose(fp);

        memset(buf, 0, MAX_SIZE);

        sleep(1);
    }

    return 0;
}