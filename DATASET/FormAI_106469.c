//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

#define INTERVAL 2 // in seconds
#define KB_TO_GB 1024 * 1024

int main(void)
{
    long ram_total, ram_free, ram_used;

    while (1)
    {
        struct sysinfo sys_info;
        if (sysinfo(&sys_info) != 0)
        {
            printf("Error in getting system info\n");
            exit(1);
        }

        ram_total = sys_info.totalram / KB_TO_GB;
        ram_free = sys_info.freeram / KB_TO_GB;
        ram_used = ram_total - ram_free;

        printf("Total RAM: %ldGB\n", ram_total);
        printf("Used RAM: %ldGB\n", ram_used);
        printf("Free RAM: %ldGB\n", ram_free);
        printf("-------------------------------------\n");

        sleep(INTERVAL);
    }

    return 0;
}