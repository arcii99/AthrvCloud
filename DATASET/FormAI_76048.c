//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PROC_PATH "/proc/stat"

int main() {
    const int NUM_CPUS = sysconf(_SC_NPROCESSORS_ONLN); // get number of CPUs
    printf("Number of CPUs: %d\n", NUM_CPUS);

    long long prev_idle_times[NUM_CPUS], prev_total_times[NUM_CPUS];
    memset(prev_idle_times, 0, sizeof(prev_idle_times));
    memset(prev_total_times, 0, sizeof(prev_total_times));

    while (1) {
        FILE* file = fopen(PROC_PATH, "r");
        if (!file) {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }

        char line[128];
        long long idle_time, total_time;

        for (int i = 0; i <= NUM_CPUS; i++) {
            if (!fgets(line, sizeof(line), file)) {
                perror("Error reading file");
                exit(EXIT_FAILURE);
            }

            if (strstr(line, "cpu") == line) { // only parse CPU lines
                char* tok = strtok(line, " "); // ignore first token 
                long long vals[7];
                for (int j = 0; j < 7; j++) {
                    tok = strtok(NULL, " ");
                    vals[j] = atoll(tok); // convert to long long
                }

                idle_time = vals[3];
                total_time = 0;
                for (int j = 0; j < 7; j++) {
                    total_time += vals[j];
                }

                long long idle_time_diff = idle_time - prev_idle_times[i];
                long long total_time_diff = total_time - prev_total_times[i];

                float cpu_usage = 100.0 * (1 - ((float)idle_time_diff) / total_time_diff);

                printf("CPU %d usage: %.2f%%\n", i, cpu_usage);

                prev_idle_times[i] = idle_time;
                prev_total_times[i] = total_time;
            }
        }

        fclose(file);

        sleep(1); // sleep for 1 second
    }

    return 0;
}