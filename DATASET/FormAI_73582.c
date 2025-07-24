//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo mem_info;

    while (1) {
        sysinfo(&mem_info);
        long long total_mem = mem_info.totalram / 1024;
        long long used_mem = (mem_info.totalram - mem_info.freeram) / 1024;

        printf("Total Memory: %lld KB\n", total_mem);
        printf("Used Memory: %lld KB\n", used_mem);

        sleep(1);
        system("clear"); // Clear console window
    }

    return 0;
}