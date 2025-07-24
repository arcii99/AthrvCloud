//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: secure
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_CPU_COUNT 64

struct cpu_data {
    unsigned long long user;
    unsigned long long nice;
    unsigned long long system;
    unsigned long long idle;
};

/* Function that reads and returns CPU usage data for all available cores */
int read_cpu_data(struct cpu_data *cpu_data_arr) {
    FILE *fp;
    char buf[1024];
    char *token;
    int cpu_count = -1;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Error opening /proc/stat file");
        exit(EXIT_FAILURE);
    }

    while (fgets(buf, sizeof(buf), fp)) {
        if (strncmp(buf, "cpu", 3) != 0) {
            break;
        }
        cpu_count++;

        token = strtok(buf, " ");
        if (token == NULL) {
            goto parse_error;
        }
        token = strtok(NULL, " ");
        if (token == NULL) {
            goto parse_error;
        }
        cpu_data_arr[cpu_count].user = strtoull(token, NULL, 10);
        token = strtok(NULL, " ");
        if (token == NULL) {
            goto parse_error;
        }
        cpu_data_arr[cpu_count].nice = strtoull(token, NULL, 10);
        token = strtok(NULL, " ");
        if (token == NULL) {
            goto parse_error;
        }
        cpu_data_arr[cpu_count].system = strtoull(token, NULL, 10);
        token = strtok(NULL, " ");
        if (token == NULL) {
            goto parse_error;
        }
        cpu_data_arr[cpu_count].idle = strtoull(token, NULL, 10);
    }

    fclose(fp);
    return cpu_count;

parse_error:
    fclose(fp);
    fprintf(stderr, "Error parsing /proc/stat file\n");
    exit(EXIT_FAILURE);
}

int main() {
    struct cpu_data prev_cpu_data[MAX_CPU_COUNT];
    struct cpu_data curr_cpu_data[MAX_CPU_COUNT];
    int cpu_count;
    int i;
    double cpu_usage[MAX_CPU_COUNT]; // Array to store CPU usage %
    double total_cpu_usage = 0.0;

    // Read CPU usage data for the first time
    cpu_count = read_cpu_data(prev_cpu_data);

    while (1) {
        usleep(500000); // Sleep for 500ms

        // Read CPU usage data for the second time
        cpu_count = read_cpu_data(curr_cpu_data);

        // Calculate CPU usage % for each core
        for (i = 0; i <= cpu_count; i++) {
            unsigned long long prev_total = prev_cpu_data[i].user + prev_cpu_data[i].nice +
                                             prev_cpu_data[i].system + prev_cpu_data[i].idle;
            unsigned long long curr_total = curr_cpu_data[i].user + curr_cpu_data[i].nice +
                                             curr_cpu_data[i].system + curr_cpu_data[i].idle;

            unsigned long long total_diff = curr_total - prev_total;
            unsigned long long idle_diff = curr_cpu_data[i].idle - prev_cpu_data[i].idle;

            double usage = (total_diff - idle_diff) * 100.0 / total_diff;
            cpu_usage[i] = usage;
            total_cpu_usage += usage;
        }

        // Print CPU usage % for each core and total
        printf("CPU Usage:\n");
        for (i = 0; i <= cpu_count; i++) {
            printf("core %d: %.2f%%\n", i, cpu_usage[i]);
        }
        printf("total: %.2f%%\n\n", total_cpu_usage);

        total_cpu_usage = 0.0;
        memcpy(prev_cpu_data, curr_cpu_data, sizeof(curr_cpu_data)); // Copy current data to previous data
    }

    return 0;
}