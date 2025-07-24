//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo info;
    int PID = getpid();

    while (1) {
        sysinfo(&info);
        long long total_ram = info.totalram * info.mem_unit;
        long long free_ram = info.freeram * info.mem_unit;
        long long used_ram = total_ram - free_ram;
        printf("PID: %d | Total RAM: %lld | Used RAM: %lld | Free RAM: %lld\n",
            PID, total_ram, used_ram, free_ram);
        sleep(1);
    }

    return 0;
}