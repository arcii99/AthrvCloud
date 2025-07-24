//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_LENGTH 256

int main()
{
    int i;
    char cpu[BUFFER_LENGTH], command[BUFFER_LENGTH], state[BUFFER_LENGTH], user[BUFFER_LENGTH];

    printf("CPU Monitor\n\n");

    while (1)
    {
        FILE *fp = fopen("/proc/stat", "r");

        if (fp == NULL)
        {
            printf("Error opening file\n");
            exit(1);
        }

        fgets(cpu, BUFFER_LENGTH, fp);

        fclose(fp);

        printf("Total CPU usage: %s\n", cpu);

        printf("Processes:\n");

        // Get the list of all processes
        system("ps -eo pid,%cpu,command,state,user > processes.txt");

        FILE *fptr = fopen("processes.txt", "r");

        if (fptr == NULL)
        {
            printf("Error opening file\n");
            exit(1);
        }

        while (fgets(command, BUFFER_LENGTH, fptr))
        {
            sscanf(command, "%d %*f %s %s %s", &i, state, user, command);
            printf("%d %s %s %s\n", i, state, user, command);
        }

        fclose(fptr);

        sleep(3);
        system("clear");
    }

    return 0;
}