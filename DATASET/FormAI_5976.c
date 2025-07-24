//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

#define MAX_BUFFER 512

int main(void)
{
    struct sysinfo info;
    FILE *cpu_file;
    char buffer[MAX_BUFFER];

    while(1)
    {
        sysinfo(&info);
        printf("CPU Usage: %ld%%\n", (info.loads[0]+info.loads[1]+info.loads[2])/3);
        cpu_file = fopen("/proc/stat", "r");
        fgets(buffer, MAX_BUFFER, cpu_file);
        fclose(cpu_file);
        sleep(2);
    }

    return 0;
}