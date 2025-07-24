//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/sysinfo.h>

#define MAX_LENGTH 256

double get_cpu_percentage(unsigned long long *prev_idle, unsigned long long *prev_total);

int main() {
    unsigned long long prev_idle = 0, prev_total = 0;
    double cpu_percentage;

    while(1) {
        cpu_percentage = get_cpu_percentage(&prev_idle, &prev_total);
        printf("CPU usage: %.2f %%\n", cpu_percentage);

        sleep(1);
    }

    return 0;
}

double get_cpu_percentage(unsigned long long *prev_idle, unsigned long long *prev_total) {
    char buffer[MAX_LENGTH];
    static int num_processors = 0;

    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Error opening /proc/stat");
        return -1;
    }

    // Get the number of processors
    while (fgets(buffer, MAX_LENGTH, fp) != NULL) {
        if (strncmp(buffer, "cpu ", 4) == 0) {
            char *token = strtok(buffer, " ");
            num_processors++;

            while (token != NULL) {
                token = strtok(NULL, " ");
            }
            break;
        }
    }

    fseek(fp, 0, SEEK_SET);

    // Get the total CPU time
    unsigned long long total = 0, idle = 0;
    while (fgets(buffer, MAX_LENGTH, fp) != NULL) {
        if (strncmp(buffer, "cpu ", 4) == 0) {
            char *token = strtok(buffer, " ");

            token = strtok(NULL, " "); // Skip the "cpu" token
            for (int i = 0; i < 10; i++) {
                char *cur_token = strtok(NULL, " ");
                total += strtoul(cur_token, NULL, 10);

                if (i == 3) idle = strtoul(cur_token, NULL, 10);
            }
            break;
        }
    }
    fclose(fp);

    // Calculate CPU percentage
    double percentage = 0;
    unsigned long long total_diff = total - *prev_total;
    unsigned long long idle_diff = idle - *prev_idle;

    if (total_diff > 0) {
        percentage = 100.0 * (total_diff - idle_diff) / total_diff;
    }

    // Update prev values
    *prev_idle = idle;
    *prev_total = total;

    return percentage;
}