//FormAI DATASET v1.0 Category: System administration ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the System Administration Program!\n\n");

    // Get the system time
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    printf("The current system time is: %s", asctime(timeinfo));

    // Check system load
    FILE *loadavg = fopen("/proc/loadavg", "r");
    if (loadavg == NULL)
    {
        printf("Error: Could not read system load.\n");
        exit(1);
    }
    char load_str[10];
    fgets(load_str, 10, loadavg);
    float load = atof(load_str);
    printf("The current system load is: %.2f\n", load);
    fclose(loadavg);

    // Check available disk space
    FILE *diskspace = popen("df -h /", "r");
    if (diskspace == NULL)
    {
        printf("Error: Could not check disk space.\n");
        exit(1);
    }
    char disk_str[256];
    fgets(disk_str, 256, diskspace);
    fgets(disk_str, 256, diskspace);
    fgets(disk_str, 256, diskspace);
    fgets(disk_str, 256, diskspace);
    char *disk_tokens[6];
    int i = 0;
    char *token = strtok(disk_str, " ");
    while (token != NULL)
    {
        disk_tokens[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    printf("The available disk space is: %s\n", disk_tokens[3]);
    pclose(diskspace);

    // Check system memory usage
    FILE *meminfo = fopen("/proc/meminfo", "r");
    if (meminfo == NULL)
    {
        printf("Error: Could not read memory usage.\n");
        exit(1);
    }
    char mem_str[256];
    fgets(mem_str, 256, meminfo);
    fclose(meminfo);
    char *mem_tokens[6];
    i = 0;
    token = strtok(mem_str, " ");
    while (token != NULL)
    {
        mem_tokens[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    printf("The current system memory usage is: %s %s\n", mem_tokens[1], mem_tokens[2]);

    printf("\nThanks for using the System Administration Program!\n");

    return 0;
}