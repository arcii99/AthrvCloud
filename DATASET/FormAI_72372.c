//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 256

int main() {
    char cpu[BUFFER_SIZE];
    char user[BUFFER_SIZE];
    char nice[BUFFER_SIZE];
    char system[BUFFER_SIZE];
    char idle[BUFFER_SIZE];
    char iowait[BUFFER_SIZE];
    char irq[BUFFER_SIZE];
    char softirq[BUFFER_SIZE];
    char steal[BUFFER_SIZE];
    char guest[BUFFER_SIZE];
    char guest_nice[BUFFER_SIZE];
    FILE* fp;
    double total_time, idle_time, cpu_usage;
    int i;

    while(1) {
        fp = fopen("/proc/stat", "r");
        if(fp == NULL) {
            perror("fopen");
            exit(EXIT_FAILURE);
        }

        fgets(cpu, sizeof(cpu), fp);
        fclose(fp);

        sscanf(cpu, "%*s %s %s %s %s %s %s %s %s %s %s", user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice);
        total_time = strtod(user, NULL) + strtod(nice, NULL) + strtod(system, NULL) + strtod(idle, NULL) + strtod(iowait, NULL) + strtod(irq, NULL) + strtod(softirq, NULL) + strtod(steal, NULL) + strtod(guest, NULL) + strtod(guest_nice, NULL);
        idle_time = strtod(idle, NULL);

        cpu_usage = (total_time - idle_time) / total_time;

        printf("Current CPU Usage: %.2f%%\n", cpu_usage*100);

        sleep(1);
    }

    return 0;
}