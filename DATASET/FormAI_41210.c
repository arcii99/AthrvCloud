//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo info;
    int mb = 1024 * 1024;
    long long total_ram, free_ram, used_ram;

    while (1) {
        sysinfo(&info);
        total_ram = (long long)info.totalram * info.mem_unit / mb;
        free_ram = (long long)info.freeram * info.mem_unit / mb;
        used_ram = total_ram - free_ram;

        printf("Total RAM: %lld MB\n", total_ram);
        printf("Used RAM:  %lld MB\n", used_ram);

        usleep(1000000); // wait for 1 second before checking again
        system("clear"); // clears the console window for cleaner output
    }

    return 0;
}