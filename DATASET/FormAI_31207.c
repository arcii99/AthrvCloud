//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    printf("Welcome to the CPU monitor program!\n\n");
    printf("Press Ctrl+C to terminate the program.\n\n");

    FILE* cpu_file = fopen("/proc/stat", "r");

    if (cpu_file == NULL)
    {
        printf("Error: cannot find /proc/stat file.\n");
        return -1;
    }

    char cpu_line[128];
    unsigned long cpu_user, cpu_nice, cpu_system, cpu_idle, cpu_iowait, cpu_irq, cpu_softirq, cpu_steal, cpu_guest, cpu_guest_nice;

    while (1)
    {
        unsigned long prev_cpu_user = cpu_user;
        unsigned long prev_cpu_nice = cpu_nice;
        unsigned long prev_cpu_system = cpu_system;
        unsigned long prev_cpu_idle = cpu_idle;
        unsigned long prev_cpu_iowait = cpu_iowait;
        unsigned long prev_cpu_irq = cpu_irq;
        unsigned long prev_cpu_softirq = cpu_softirq;
        unsigned long prev_cpu_steal = cpu_steal;
        unsigned long prev_cpu_guest = cpu_guest;
        unsigned long prev_cpu_guest_nice = cpu_guest_nice;

        rewind(cpu_file);
        fgets(cpu_line, sizeof(cpu_line), cpu_file); // Read the first line (which contains CPU statistics)

        sscanf(cpu_line, "cpu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu", &cpu_user, &cpu_nice, &cpu_system, &cpu_idle, &cpu_iowait, &cpu_irq, &cpu_softirq, &cpu_steal, &cpu_guest, &cpu_guest_nice);

        printf("CPU usage: %.2f%%\n", (float)(cpu_user + cpu_nice + cpu_system - prev_cpu_user - prev_cpu_nice - prev_cpu_system) / (float)(cpu_user + cpu_nice + cpu_system + cpu_idle + cpu_iowait + cpu_irq + cpu_softirq + cpu_steal + cpu_guest + cpu_guest_nice - prev_cpu_user - prev_cpu_nice - prev_cpu_system - prev_cpu_idle - prev_cpu_iowait - prev_cpu_irq - prev_cpu_softirq - prev_cpu_steal - prev_cpu_guest - prev_cpu_guest_nice) * 100.0);

        usleep(500000); // Sleep for 500 milliseconds before checking the CPU usage again
    }

    fclose(cpu_file);

    return 0;
}