//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    int num_of_cores = sysconf(_SC_NPROCESSORS_ONLN);
    printf("Number of cores: %d\n", num_of_cores);

    FILE *stat_file = fopen("/proc/stat", "r");
    if (!stat_file) {
        perror("Failed to open stat file");
        return EXIT_FAILURE;
    }

    long int idle_time[num_of_cores], prev_idle_time[num_of_cores];
    long int total_time[num_of_cores], prev_total_time[num_of_cores];
    memset(prev_idle_time, 0, sizeof(prev_idle_time));
    memset(prev_total_time, 0, sizeof(prev_total_time));

    while (1) {
        fseek(stat_file, 0, SEEK_SET);
        for (int i = 0; i < num_of_cores; i++) {
            char line[512];
            fgets(line, sizeof(line), stat_file);
            sscanf(line, "cpu%d %ld %ld %*d %*d %*d %*d %*d %*d %*d", 
                   &i, &total_time[i], &idle_time[i]);
        }

        putchar('\n');
        for (int i = 0; i < num_of_cores; i++) {
            long int idle = idle_time[i] - prev_idle_time[i];
            long int total = total_time[i] - prev_total_time[i];
            prev_idle_time[i] = idle_time[i];
            prev_total_time[i] = total_time[i];

            float usage = 100.0 * (1.0 - ((float)idle / (float)total));
            printf("Core %d usage: %.2f%%\t", i, usage);
        }
        sleep(1);
    }
    return EXIT_SUCCESS;
}