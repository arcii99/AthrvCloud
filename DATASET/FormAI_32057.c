//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <unistd.h>

int main() {

    struct sysinfo sys_info;
    int mb_divisor = 1024 * 1024;
    char units[5] = "MB";

    while(1) {

        if(sysinfo(&sys_info) == 0) {

            long long total_ram = sys_info.totalram / mb_divisor;
            long long free_ram = sys_info.freeram / mb_divisor;
            long long used_ram = total_ram - free_ram;

            if(used_ram >= 1024) {
                used_ram = used_ram / 1024;
                strcpy(units, "GB");
            }
            
            printf("Total RAM: %lld %s | ", total_ram, units);
            printf("Free RAM: %lld %s | ", free_ram, units);
            printf("Used RAM: %lld %s\n", used_ram, units);

        } else {
            printf("Error getting system info.\n");
        }

        sleep(1);
    }

    return 0;
}