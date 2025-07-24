//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/sysinfo.h>

#define BUFFER_SIZE 256

int get_ram_usage() {
    struct sysinfo mem_info;
    sysinfo(&mem_info);
    long long total_ram = mem_info.totalram / 1024;
    long long free_ram = mem_info.freeram / 1024;
    float ram_usage = (float) (total_ram - free_ram) / total_ram * 100;
    return (int) ram_usage;
}

int main() {
    int delay_time = 1;
    printf("RAM usage monitor started\n");
    printf("--------------------------\n");

    while (1) {
        int ram_usage = get_ram_usage();
        printf("RAM usage: %d%%\n", ram_usage);
        if (ram_usage > 80) {
            printf("Warning: High RAM usage!\n");
            // Add your own custom logic here
        }
        sleep(delay_time);
        printf("\033[A\033[2K");
    }
    return 0;
}