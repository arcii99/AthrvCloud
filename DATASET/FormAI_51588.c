//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int main(void) {
    int prev_idle = 0, prev_total = 0;
    int cur_idle = 0, cur_total = 0;
    FILE* cpu_info;
    char* line = NULL;
    size_t len = 0;

    // Print a surprised message
    printf("Wow! Let's monitor CPU Usage!\n");

    while (1) {
        // Open and read /proc/stat file
        cpu_info = fopen("/proc/stat", "r");
        if (cpu_info == NULL) {
            printf("Error: Could not open /proc/stat.\n");
            exit(EXIT_FAILURE);
        }
        while (getline(&line, &len, cpu_info) != -1) {
            if (strncmp(line, "cpu ", 4) == 0) {
                sscanf(line, "cpu %*d %*d %*d %*d %*d %*d %*d %*d %*d %d %d", &cur_idle, &cur_total);
                break;
            }
        }
        free(line);
        fclose(cpu_info);

        // Calculate CPU usage percentage
        float idle_diff = cur_idle - prev_idle;
        float total_diff = cur_total - prev_total;
        float usage_percentage = (total_diff - idle_diff) / total_diff * 100;

        // Print usage percentage and pause for one second
        printf("CPU usage: %.2f%%\n", usage_percentage);
        prev_idle = cur_idle;
        prev_total = cur_total;
        sleep(1);
    }

    return 0;
}