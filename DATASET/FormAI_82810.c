//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo info;
    int mb = 1024 * 1024;

    while (1) {
        if (sysinfo(&info) < 0) {
            fprintf(stderr, "Failed to retrieve system information.\n");
            exit(1);
        }

        long long total_mem = info.totalram * info.mem_unit;
        long long free_mem = info.freeram * info.mem_unit;
        long long used_mem = total_mem - free_mem;

        printf("Total Memory: %lldMB\n", total_mem / mb);
        printf("Free Memory: %lldMB\n", free_mem / mb);
        printf("Used Memory: %lldMB\n", used_mem / mb);

        sleep(1);  // wait for 1 second before checking again
    }

    return 0;
}