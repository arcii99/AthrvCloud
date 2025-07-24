//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: protected
#include <stdio.h>
#include <unistd.h>

int main() {
    while(1) {
        FILE* fp = fopen("/proc/meminfo", "r");

        if(fp == NULL) {
            printf("Error opening /proc/meminfo\n");
            return 1;
        }

        char buff[256];
        int total_mem, free_mem, cached_mem;

        while(fgets(buff, sizeof(buff), fp)) {
            if(sscanf(buff, "MemTotal: %d", &total_mem) == 1) {
                continue;
            }

            if(sscanf(buff, "MemFree: %d", &free_mem) == 1) {
                continue;
            }

            if(sscanf(buff, "Cached: %d", &cached_mem) == 1) {
                fclose(fp);
                break;
            }
        }

        printf("Total memory: %d KB, free memory: %d KB, cached memory: %d KB\n", total_mem, free_mem, cached_mem);

        int used_mem = total_mem - free_mem - cached_mem;
        int used_percentage = (used_mem * 100) / total_mem;

        printf("Currently used memory: %d KB (%d%)\n", used_mem, used_percentage);
        printf("----------------------------------------\n");

        sleep(5);
    }

    return 0;
}