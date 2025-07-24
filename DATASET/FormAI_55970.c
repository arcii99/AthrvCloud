//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {

    while(1) {
        struct sysinfo info;
        if(sysinfo(&info) == -1) {
            printf("Error: Failed to get system information\n");
            exit(1);
        }
        long long total_RAM = ((long long)info.totalram * (long long)info.mem_unit)/(1024*1024);
        long long free_RAM = ((long long)info.freeram * (long long)info.mem_unit)/(1024*1024);
        long long used_RAM = total_RAM - free_RAM;
        double usage_percentage = (double)used_RAM / (double)total_RAM * 100;

        char bar[25];
        int barLength = (int)(usage_percentage/4);

        for (int i = 0; i < 25; i++) {
            if (i <= barLength) {
                bar[i] = '#';
            } else {
                bar[i] = '-';
            }
        }
        bar[24] = '\0';

        printf("\n*********** SYSTEM STATISTICS ***********\n");
        printf("Total RAM: %lld MB\n", total_RAM);
        printf("Used RAM: %lld MB\n", used_RAM);
        printf("Free RAM: %lld MB\n", free_RAM);
        printf("RAM Usage: %lf%%\n", usage_percentage);
        printf("RAM Usage Bar: [%s]\n", bar);
        printf("****************************************\n");

        sleep(1);
    }

    return 0;
}