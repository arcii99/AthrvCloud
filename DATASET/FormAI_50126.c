//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#define GB_DIVISOR 1073741824

struct sys_info {
    long long totalram;
    long long freeram;
    long long usedram;
};

typedef struct sys_info sys_info;

unsigned long long get_total_ram() {
    struct sysinfo si;
    sysinfo(&si);
    return (unsigned long long)(si.totalram);
}

long long get_free_ram() {
    struct sysinfo si;
    sysinfo(&si);
    return (long long)(si.freeram);
}

sys_info get_system_info() {
    sys_info si;
    si.totalram = get_total_ram();
    si.freeram = get_free_ram();
    si.usedram = si.totalram - si.freeram;
    return si;
}

float calculate_ram_usage() {
    sys_info si = get_system_info();
    float usage = (float)(si.usedram) / si.totalram * 100;
    return usage;
}

void print_ram_usage() {
    float usage = calculate_ram_usage();
    printf("RAM USAGE: %.2f%%\n", usage);
}

int main() {
    print_ram_usage();
    return 0;
}