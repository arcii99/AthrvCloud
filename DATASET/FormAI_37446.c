//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {
    printf("Welcome to the C RAM Usage Monitor!\n");

    struct sysinfo sys_info;
    int mb = 1024 * 1024;
    char *unit = "MB";

    while(1) {
        if(sysinfo(&sys_info) != 0) {
            printf("Error getting system info!\n");
            exit(1);
        }

        long long total_ram = sys_info.totalram / mb;
        long long free_ram = sys_info.freeram / mb;
        long long used_ram = total_ram - free_ram;

        printf("RAM Usage:\n");
        printf("  Total:\t%lld%s\n", total_ram, unit);
        printf("  Used:\t\t%lld%s\n", used_ram, unit);
        printf("  Free:\t\t%lld%s\n\n", free_ram, unit);

        sleep(1);
    }

    return 0;
}