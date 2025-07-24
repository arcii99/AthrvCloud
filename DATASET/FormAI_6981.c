//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define MB (1024*1024)

int main(void) {
    struct sysinfo info;
    while (1) {
        if (sysinfo(&info) != 0) {
            fprintf(stderr, "Error: failed to get system info.\n");
            exit(EXIT_FAILURE);
        }
        long total_ram = (long)info.totalram * info.mem_unit / MB;
        long free_ram = (long)info.freeram * info.mem_unit / MB;
        long used_ram = total_ram - free_ram;

        printf("\rUsed RAM: %ld MB, Free RAM: %ld MB, Total RAM: %ld MB",
            used_ram, free_ram, total_ram);
        fflush(stdout);
        sleep(1);
    }

    return 0;
}