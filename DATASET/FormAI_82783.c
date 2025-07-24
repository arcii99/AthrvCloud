//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo info;
    unsigned long long total_mem, free_mem, used_mem;
    int count = 0;

    while (++count <= 10) {
        if (sysinfo(&info) == -1) {
            perror("sysinfo");
            exit(EXIT_FAILURE);
        }

        total_mem = (unsigned long long) info.totalram * info.mem_unit;
        free_mem = (unsigned long long) info.freeram * info.mem_unit;
        used_mem = total_mem - free_mem;

        printf("RAM Usage Monitor - Iteration %d:\n", count);
        printf("Total Memory: %llu bytes\n", total_mem);
        printf("Free Memory: %llu bytes\n", free_mem);
        printf("Used Memory: %llu bytes\n", used_mem);

        float usage_percentage = ((float) used_mem / (float) total_mem) * 100;
        printf("RAM Usage: %.2f%%\n", usage_percentage);

        sleep(1);
    }

    return 0;
}