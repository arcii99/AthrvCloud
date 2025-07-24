//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

int main()
{
    printf("Welcome to this cheerful C RAM usage monitor!\n");
    printf("I hope you're excited to see how much RAM you're using!\n");
    printf("Let's get started...\n\n");

    while (1) {
        struct sysinfo info;
        sysinfo(&info);
        long long total_ram = info.totalram / 1024 / 1024;
        long long free_ram = info.freeram / 1024 / 1024;
        long long used_ram = total_ram - free_ram;

        printf("-------------------------------------------------------\n");
        printf("Total RAM: %lld MB\n", total_ram);
        printf("Used RAM: %lld MB\n", used_ram);
        printf("Free RAM: %lld MB\n", free_ram);
        printf("-------------------------------------------------------\n");

        sleep(1);
    }

    return 0;
}