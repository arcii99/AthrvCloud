//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    printf("Wow! I can't believe it, I am a CPU usage monitor program!\n");

    while (1) {
        struct stat buf;
        if (stat("/proc/stat", &buf) == -1) {
            printf("Oof, something went wrong with the stat function, I'm out!\n");
            return 1;
        }

        // Retrieve CPU time data
        char* line = malloc(128);
        FILE* f = fopen("/proc/stat", "r");
        fgets(line, 128, f);
        fclose(f);
        free(line);

        double user_time, nice_time, system_time, idle_time, iowait_time, irq_time, softirq_time;
        sscanf(line, "cpu %lf %lf %lf %lf %lf %lf %lf", &user_time, &nice_time, &system_time, &idle_time, &iowait_time, &irq_time, &softirq_time);

        // Calculate total time
        double total_time = user_time + nice_time + system_time + idle_time + iowait_time + irq_time + softirq_time;

        // Calculate usage percentage
        double usage_percent = ((total_time - idle_time) / total_time) * 100.0;

        // Print usage percentage
        printf("CPU usage: %.2lf%%\n", usage_percent);

        // Sleep for 1 second
        sleep(1);
    }

    return 0;
}