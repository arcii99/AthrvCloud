//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int total_mem, free_mem, used_mem;
    FILE* mem_info = fopen("/proc/meminfo", "r");
    if (mem_info == NULL) {
        printf("Error opening file '/proc/meminfo'\n");
        return 1;
    }
    fscanf(mem_info, "MemTotal: %d", &total_mem);
    fscanf(mem_info, "MemFree: %d", &free_mem);
    fclose(mem_info);
    used_mem = total_mem - free_mem;
    printf("Total memory: %d kB\n", total_mem);
    printf("Free memory: %d kB\n", free_mem);
    printf("Used memory: %d kB\n", used_mem);
    printf("\n");
    while (1) {
        system("clear"); // to clear the console each time
        mem_info = fopen("/proc/meminfo", "r");
        if (mem_info == NULL) {
            printf("Error opening file '/proc/meminfo'\n");
            return 1;
        }
        fscanf(mem_info, "MemTotal: %d", &total_mem);
        fscanf(mem_info, "MemFree: %d", &free_mem);
        fclose(mem_info);
        used_mem = total_mem - free_mem;
        float used_percent = (float) used_mem / total_mem * 100;
        printf("Total memory: %d kB\n", total_mem);
        printf("Free memory: %d kB\n", free_mem);
        printf("Used memory: %d kB (%.2f%%)\n", used_mem, used_percent);
        printf("=[");
        for (int i = 0; i < 40; i++) {
            if (((float) i / 40) * 100 <= used_percent) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("]=\n");
        sleep(1); // update the stats every second
    }
    return 0;
}