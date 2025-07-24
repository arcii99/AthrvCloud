//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main()
{
    int duration, num_readings;
    float cpu_usage = 0, total_cpu_usage = 0;
    printf("Enter the duration (in seconds) to monitor CPU usage: ");
    scanf("%d", &duration);
    printf("Enter the number of readings to take: ");
    scanf("%d", &num_readings);

    int i;
    for (i = 0; i < num_readings; i++)
    {
        FILE *fptr;
        char *command = "ps -e -o pcpu --noheader | awk '{sum+=$1} END {print sum}'";
        char output[1024];

        // Executes system command and reads the output
        fptr = popen(command, "r");
        if (fptr == NULL)
        {
            printf("Error executing command\n");
            exit(1);
        }

        fgets(output, sizeof(output), fptr);
        cpu_usage = strtof(output, NULL);

        // Calculates average cpu usage
        total_cpu_usage += cpu_usage;
        float avg_cpu_usage = total_cpu_usage / (i + 1);

        printf("Reading %d: CPU usage - %.2f%%, Average CPU Usage - %.2f%%\n", i+1, cpu_usage, avg_cpu_usage);
        pclose(fptr);
        sleep(duration/num_readings);
    }

    return 0;
}