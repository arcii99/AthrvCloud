//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo info;
    int total_ram, used_ram;
    sysinfo(&info);
    total_ram = info.totalram / (1024*1024);
    used_ram = (info.totalram - info.freeram) / (1024*1024);
    printf("Total RAM: %d MB\n", total_ram);
    printf("Used RAM: %d MB\n", used_ram);
    printf("Free RAM: %d MB\n", (info.freeram / (1024*1024)));
    printf("RAM usage: %d%%\n", ((used_ram*100)/total_ram));
    return 0;
}