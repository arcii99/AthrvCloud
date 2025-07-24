//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

int main(int argc, char const *argv[]) {
    struct sysinfo info;
    long total_mem;
    long free_mem;
    double usage;
    int i = 0;

    while (1) {
        i++;
        sleep(1);

        sysinfo(&info);
        total_mem = info.totalram * info.mem_unit;
        free_mem = info.freeram * info.mem_unit;
        usage = ((double)(total_mem - free_mem) / (double)total_mem) * 100.0;

        printf("[%d] Memory usage: %.2f%%\n", i, usage);
    }

    return 0;
}