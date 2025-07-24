//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo si;
    while (1) {
        if(sysinfo(&si) == 0) {
            long total_ram = si.totalram / 1024;
            long free_ram = si.freeram / 1024;
            long used_ram = total_ram - free_ram;
            float used_percent = ((float)used_ram / (float)total_ram) * 100;

            printf("Total RAM:\t%ld KB\n", total_ram);
            printf("Used RAM:\t%ld KB\n", used_ram);
            printf("Free RAM:\t%ld KB\n", free_ram);
            printf("Used Percent:\t%.2f%%\n\n", used_percent);
        }
        sleep(1);
    }
    return 0;
}