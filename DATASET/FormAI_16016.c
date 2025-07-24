//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main(){

    while(1){
        FILE *meminfo = fopen("/proc/meminfo", "r");
        if(meminfo == NULL){
            printf("Unable to open meminfo file!\n");
            exit(EXIT_FAILURE);
        }

        char line[256];
        int total_mem = 0, free_mem = 0;

        // Read all lines of meminfo file
        while(fgets(line, sizeof(line), meminfo)){
            sscanf(line, "MemTotal: %d kB", &total_mem);
            sscanf(line, "MemFree: %d kB", &free_mem);
        }

        fclose(meminfo);

        // Calculate RAM usage percentage
        int used_mem = total_mem - free_mem;
        int ram_usage = (used_mem * 100) / total_mem;

        // Print RAM usage
        printf("RAM usage: %d%%\n", ram_usage);

        sleep(1); // Wait for 1 second before checking again
    }

    return 0;
}