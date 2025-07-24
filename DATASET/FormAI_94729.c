//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <unistd.h>

const int CPU_UPDATE_INTERVAL = 1; // in seconds

int main()
{
    printf("\n");
    printf("=========================================\n");
    printf("Welcome to the Unique CPU Usage Monitor!\n");
    printf("=========================================\n\n");

    printf("Press Ctrl+C to stop the program.\n\n");

    struct sysinfo info;
    unsigned long long last_total_time = 0;
    unsigned long long last_idle_time = 0;

    while (1)
    {
        sysinfo(&info);

        unsigned long long total_time = info.loads[0];
        unsigned long long idle_time = info.loads[3];

        unsigned long long total_delta = total_time - last_total_time;
        unsigned long long idle_delta = idle_time - last_idle_time;

        double usage = 100.0 * (1.0 - ((double)idle_delta / total_delta));

        printf("\rCPU Usage: %.2f %%", usage);

        last_total_time = total_time;
        last_idle_time = idle_time;

        sleep(CPU_UPDATE_INTERVAL);
    }

    return 0;
}