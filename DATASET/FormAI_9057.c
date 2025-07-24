//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int cpu_usage; //Variable to hold the CPU usage value
    char command[50]; //Command to be executed

    while(1) //Runs infinitely
    {
        strcpy(command, "ps -eo pcpu | tail -n+2 | awk '{s+=$1} END {print s}'"); //Command to get CPU usage
        FILE* file = popen(command, "r"); //Open pipe to execute command

        if(file == NULL) //If pipe is null, exit program
        {
            printf("Error executing command.\n");
            exit(EXIT_FAILURE);
        }

        fscanf(file, "%d", &cpu_usage); //Get CPU usage value from pipe
        pclose(file); //Close pipe

        printf("Current CPU usage: %d%%\n", cpu_usage); //Print CPU usage for debugging purposes

        usleep(1000000); //Delay program for 1s
    }

    return 0;
}