//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo info;
    while(1) {
        sysinfo(&info);
        long long total_ram = info.totalram * info.mem_unit / 1024 / 1024; // Convert bytes to MB
        long long free_ram = info.freeram * info.mem_unit / 1024 / 1024; // Convert bytes to MB
        long long used_ram = total_ram - free_ram;
        printf("Total RAM: %lldMB | Used RAM: %lldMB | Free RAM: %lldMB\n", total_ram, used_ram, free_ram);
        sleep(1); // Delay for 1 second
    }
    return 0;
}