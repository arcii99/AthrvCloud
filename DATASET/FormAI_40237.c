//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: protected
#include <stdio.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define MB (1024 * 1024)

int main() {
    long ram_total, ram_free, ram_used;
    struct sysinfo sys_info;

    while(1) {
        if(sysinfo(&sys_info) != 0) {
            printf("Error getting system info.\n");
            return 1;
        }
        ram_total = sys_info.totalram / MB;
        ram_used = (sys_info.totalram - sys_info.freeram) / MB;
        ram_free = sys_info.freeram / MB;

        printf("Total RAM: %ld MB\n", ram_total);
        printf("Used RAM: %ld MB\n", ram_used);
        printf("Free RAM: %ld MB\n\n", ram_free);

        sleep(1);
    }

    return 0;
}