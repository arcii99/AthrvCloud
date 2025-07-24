//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_CPUS 64

int main() {
    int num_cpus = 0;
    char *cpu_state = NULL, *cpu_prev = NULL;
    double total_usage = 0.0;

    // Get number of CPUs
    FILE *cpu_info_file = fopen("/proc/cpuinfo", "r");
    if (cpu_info_file == NULL) {
        printf("ERROR: Failed to open file /proc/cpuinfo\n");
        return 1;
    }
    char line[256];
    while (fgets(line, sizeof(line), cpu_info_file)) {
        if (strncmp(line, "processor", 9) == 0) {
            num_cpus++;
        }
    }
    fclose(cpu_info_file);

    printf("Number of CPUs: %d\n", num_cpus);

    // Allocate memory for cpu_state and cpu_prev
    cpu_state = (char *)malloc(num_cpus * 4 * sizeof(char));
    if (cpu_state == NULL) {
        printf("ERROR: Memory allocation failed\n");
        return 1;
    }
    cpu_prev = (char *)malloc(num_cpus * 4 * sizeof(char));
    if (cpu_prev == NULL) {
        printf("ERROR: Memory allocation failed\n");
        free(cpu_state);
        return 1;
    }

    // Start monitoring CPU usage
    while (1) {
        FILE *stat_file = fopen("/proc/stat", "r");
        if (stat_file == NULL) {
            printf("ERROR: Failed to open file /proc/stat\n");
            free(cpu_state);
            free(cpu_prev);
            return 1;
        }

        // Read first line from /proc/stat
        fgets(line, sizeof(line), stat_file);
        char *token = strtok(line, " ");
        double tot_user = 0.0, tot_nice = 0.0, tot_sys = 0.0, tot_idle = 0.0;
        token = strtok(NULL, " ");
        tot_user = atof(token);
        token = strtok(NULL, " ");
        tot_nice = atof(token);
        token = strtok(NULL, " ");
        tot_sys = atof(token);
        token = strtok(NULL, " ");
        tot_idle = atof(token);
        double tot_time = tot_user + tot_nice + tot_sys + tot_idle;

        // Read per CPU data from /proc/stat
        for (int i = 0; i < num_cpus; i++) {
            fgets(line, sizeof(line), stat_file);
            token = strtok(line, " ");
            double user = 0.0, nice = 0.0, sys = 0.0, idle = 0.0;
            token = strtok(NULL, " ");
            user = atof(token);
            token = strtok(NULL, " ");
            nice = atof(token);
            token = strtok(NULL, " ");
            sys = atof(token);
            token = strtok(NULL, " ");
            idle = atof(token);
            double time = user + nice + sys + idle;

            // Compute CPU usage percentage
            double usage = ((time - idle) / (tot_time - tot_idle)) * 100.0;
            total_usage += usage;
            snprintf(cpu_state + (i * 4), 4, "%.0f", usage);
        }
        fclose(stat_file);

        // Display results
        snprintf(line, sizeof(line), "%.1f", (total_usage / num_cpus));
        printf("CPU usage: %s%%\n", line);
        printf("Per CPU usage: ");
        for (int i = 0; i < num_cpus; i++) {
            snprintf(line, sizeof(line), "%.0f", atof(cpu_state + (i * 4)));
            printf("%s%% ", line);
        }
        printf("\n");

        memcpy(cpu_prev, cpu_state, num_cpus * 4 * sizeof(char));
        total_usage = 0.0;
        sleep(1);
    }

    free(cpu_state);
    free(cpu_prev);
    return 0;
}