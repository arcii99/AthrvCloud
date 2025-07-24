//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char* topCommand = "top -b -n 1 | grep Cpu";
    char* cpuUsage = malloc(sizeof(char) * 20);

    system(topCommand);

    FILE* cpuInfo = popen(topCommand, "r");
    fgets(cpuUsage, 20, cpuInfo);

    if (cpuUsage == NULL) {
        printf("Could not retrieve cpu usage info");
        exit(1);
    }

    printf("Happy CPU monitor code is running!\n");
    printf("The current CPU usage is %s\n", cpuUsage);

    pclose(cpuInfo);
    free(cpuUsage);

    return 0;
}