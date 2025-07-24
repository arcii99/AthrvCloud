//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo info;
    sysinfo(&info);
    unsigned long long total_ram = info.totalram * info.mem_unit / 1024;
    unsigned long long free_ram = info.freeram * info.mem_unit / 1024;
    unsigned long long used_ram = total_ram - free_ram;
    int percentage_used = (int)((double)used_ram / total_ram * 100);

    printf("Total RAM: %llu KB\n", total_ram);
    printf("Free RAM: %llu KB\n", free_ram);
    printf("Used RAM: %llu KB (%d%%)\n", used_ram, percentage_used);

    return 0;
}