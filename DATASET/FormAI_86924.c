//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

#define COLOR_BLUE  "\x1b[34m"
#define COLOR_RESET "\x1b[0m"

int main() {
    struct sysinfo si;
    long total_ram, used_ram, free_ram;
    float used_perc;

    while(1) {
        if(sysinfo(&si) != 0) {
            printf("An error occurred while getting system info.\n");
            exit(1);
        }

        total_ram = si.totalram;
        free_ram = si.freeram;
        used_ram = total_ram - free_ram;
        used_perc = ((float)used_ram / total_ram) * 100;

        printf("Total RAM: %ld\n", total_ram);
        printf("Used RAM: %ld [%0.1f%%]\n", used_ram, used_perc);
        printf("Free RAM: %ld\n", free_ram);

        if(used_perc > 80.0) {
            printf(COLOR_BLUE "WARNING: RAM usage is high!" COLOR_RESET "\n");
        }

        sleep(1);
    }

    return 0;
}