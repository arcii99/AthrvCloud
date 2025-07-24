//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: optimized
#include <stdlib.h>
#include <stdio.h>

#define MAX_CPU_USAGE 100
#define SLEEP_TIME_MS 500

int main()
{
    float cpuUsage = 0.0;
    char cmd[100];
    FILE* fp;

    while(1)
    {
        fp = popen("top -bn1 | grep \"Cpu(s)\" | sed \"s/^.*:\\s*\\([0-9.]*\\).*$/\\1/\"", "r"); // execute command
        fgets(cmd, sizeof(cmd)-1, fp); // read command output
        pclose(fp); // close file pointer

        cpuUsage = atof(cmd); // convert string output to float

        if(cpuUsage > MAX_CPU_USAGE) // check if usage is above threshold
        {
            printf("High CPU usage detected: %.2f%%\n", cpuUsage);
        }

        usleep(SLEEP_TIME_MS * 1000); // sleep for specified time
    }

    return 0;
}