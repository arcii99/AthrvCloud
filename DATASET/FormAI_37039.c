//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sysinfo.h>

#define MB (1024 * 1024)

struct sys_info {
    unsigned long long mem_total;
    unsigned long long mem_free;
    unsigned long long swap_total;
    unsigned long long swap_free;
};

void get_sys_info(struct sys_info *si) {
    struct sysinfo info;
    sysinfo(&info);
    si->mem_total = (unsigned long long) info.totalram * info.mem_unit / MB;
    si->mem_free = (unsigned long long) info.freeram * info.mem_unit / MB;
    si->swap_total = (unsigned long long) info.totalswap * info.mem_unit / MB;
    si->swap_free = (unsigned long long) info.freeswap * info.mem_unit / MB;
}

int main() {
    struct sys_info si;
    get_sys_info(&si);

    printf("Total memory: %llu MB\n", si.mem_total);
    printf("Free memory: %llu MB\n", si.mem_free);
    printf("RAM usage: %llu%%\n", 100 - si.mem_free * 100 / si.mem_total);
    printf("Total swap: %llu MB\n", si.swap_total);
    printf("Free swap: %llu MB\n", si.swap_free);

    return 0;
}