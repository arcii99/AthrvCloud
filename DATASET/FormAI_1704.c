//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    while (1) {
        FILE *fp = fopen("/proc/stat", "r");
        char buff[100];

        if (fp == NULL) {
            printf("Error opening file!\n");
            exit(1);
        }

        fgets(buff, 100, fp);

        fclose(fp);

        int user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
        sscanf(buff, "cpu %d %d %d %d %d %d %d %d %d %d", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);

        int idle_time = idle + iowait;
        int total_time = user + nice + system + idle_time + irq + softirq + steal + guest + guest_nice;

        float cpu_usage = 100 * (1 - ((float)idle_time / total_time));

        printf("CPU Usage: %.2f%%\n", cpu_usage);

        sleep(1);
    }

    return 0;
}