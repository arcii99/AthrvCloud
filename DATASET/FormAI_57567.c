//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int total_cpu_time = 0, idle_cpu_time = 0;
    double cpu_usage = 0.0;
    FILE *stat_file;
    char cpu_stat[100];

    printf("CPU Usage Monitor started...\n");

    while(1)
    {
        stat_file = fopen("/proc/stat", "r"); //Open the /proc/stat file

        if(stat_file == NULL)
        {
            printf("Error opening file.\n");
            exit(1);
        }

        fgets(cpu_stat, sizeof(cpu_stat), stat_file); //Read the first line

        sscanf(cpu_stat, "cpu %*d %*d %*d %*d %*d %*d %*d %*d %*d %d", &idle_cpu_time);

        total_cpu_time = 0;

        while(fgets(cpu_stat, sizeof(cpu_stat), stat_file)) //Read all the other lines
        {
            if(sscanf(cpu_stat, "cpu%*d %d", &total_cpu_time) == 1) //Check if the line starts with "cpu"
            {
                break; //Exit the loop once the desired line has been read
            }
        }

        fclose(stat_file); //Close the file

        cpu_usage = ((double)(total_cpu_time - idle_cpu_time) / total_cpu_time) * 100.0; //Calculate the CPU usage

        printf("Current CPU usage: %.2lf%%\n", cpu_usage);

        sleep(1); //Wait for 1 second before checking again
    }

    return 0;
}