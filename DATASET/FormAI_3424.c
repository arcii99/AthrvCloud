//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <time.h>

#define MAX_SAMPLES 1000
#define SAMPLE_INTERVAL 1

int main() {
    struct sysinfo system_info;
    long long total_memory;

    sysinfo(&system_info);
    total_memory = system_info.totalram * system_info.mem_unit;

    printf("System has %lld total memory\n", total_memory);
    printf("Sampling...\n");

    time_t start_time = time(NULL);
    time_t end_time = start_time + MAX_SAMPLES * SAMPLE_INTERVAL;

    int sample_count = 0;
    long long prev_usage = 0;

    while (time(NULL) < end_time) {
        sysinfo(&system_info);
        long long used_memory = total_memory - system_info.freeram * system_info.mem_unit;
        bool usage_has_changed = (used_memory != prev_usage);

        if (sample_count == 0 || usage_has_changed) {
            printf("Sample %d: %lld bytes used\n", sample_count + 1, used_memory);
            prev_usage = used_memory;
            sample_count++;
        }

        usleep(SAMPLE_INTERVAL * 1000000);
    }

    printf("Sampling complete. %d samples taken.\n", sample_count);

    return 0;
}