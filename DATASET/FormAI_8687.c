//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    FILE* file = fopen("/proc/stat", "r"); // Opening /proc/stat file which contains system statistics

    char line[256];
    fgets(line, sizeof(line), file);

    fclose(file);

    char* token = strtok(line, " ");
    int sum = 0;
    int cpu_time[10];

    for (int i = 0; i < 10; ++i) {
        token = strtok(NULL, " ");
        cpu_time[i] = atoi(token);
        sum += cpu_time[i];
    }

    printf("CPU Usage: %.2f%%\n", 100.0 * ((float)(sum - cpu_time[3]) / sum)); // Subtract the idle time from total time to calculate CPU usage

    return 0;
}