//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: expert-level
#include <stdio.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define SLEEP_TIME 1
#define MB_TO_BYTE 1048576

int main(void){
    while(1) {
        struct sysinfo system_info;
        sysinfo(&system_info);
        long total_ram = (system_info.totalram * system_info.mem_unit)/MB_TO_BYTE;
        long free_ram = (system_info.freeram * system_info.mem_unit)/MB_TO_BYTE;
        long used_ram = total_ram - free_ram;
        float percent_used = ((float) used_ram / (float) total_ram) * 100;

        printf("\r Total Memory: %ldMB | Used Memory: %ldMB | Free Memory: %ldMB | Memory Usage: %.2f%%", total_ram, used_ram, free_ram, percent_used);
        
        fflush(stdout);
        sleep(SLEEP_TIME);
    }
    return 0;
}