//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CPU_USAGE 100.0

int main()
{
    float current_cpu_usage = 0.0;
    char command[200];
    char result[200];

    printf("Welcome to the CPU usage monitor!\n");

    while(1)
    {
        // Clear the command and result arrays
        memset(command, 0, sizeof(command));
        memset(result, 0, sizeof(result));

        // Create the command to get the current CPU usage
        snprintf(command, sizeof(command), "ps -A -o %%cpu | awk '{s+=$1} END {printf \"%.2f\",s}'",
                 current_cpu_usage);

        // Run the command and get the result
        FILE *cmd = popen(command, "r");
        if(cmd)
        {
            fgets(result, sizeof(result), cmd);
            pclose(cmd);
        }

        // Convert the result to a float 
        float cpu_usage = atof(result);

        // Print the current CPU usage
        printf("Current CPU usage: %.2f%%\n", cpu_usage);

        // Check if the current CPU usage is above the maximum
        if(cpu_usage > MAX_CPU_USAGE)
        {
            printf("WARNING: CPU usage is above %.2f%%!\n", MAX_CPU_USAGE);
            printf("Closing all non-essential processes...\n");

            // Create the command to close non-essential processes
            snprintf(command, sizeof(command), "ps -A -o pid,pcpu,comm | awk '$2 > %.2f && $3 != \"monitor\" {print $1}' | xargs kill -9",
                     MAX_CPU_USAGE);

            // Run the command to close non-essential processes
            system(command);

            printf("All non-essential processes closed.\n");
        }

        // Sleep for 1 second before checking CPU usage again
        sleep(1);
    }

    return 0;
}