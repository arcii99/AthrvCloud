//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo info;
    long long total_ram, free_ram, used_ram;

    while (1) {
        if (sysinfo(&info) == -1) {
            fprintf(stderr, "sysinfo: error\n");
            exit(EXIT_FAILURE);
        }

        total_ram = info.totalram / 1024;
        free_ram = info.freeram / 1024;
        used_ram = total_ram - free_ram;

        printf("Total RAM: %lld KB\n", total_ram);
        printf("Free RAM: %lld KB\n", free_ram);
        printf("Used RAM: %lld KB\n", used_ram);

        usleep(1000000);
    }

    return 0;
}