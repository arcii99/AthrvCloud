//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MB_TO_BYTES 1048576

int main(void) {
    FILE *fp;
    char mem_total[128], mem_free[128], mem_available[128];
    unsigned long long total_mem = 0, free_mem = 0, avail_mem = 0;
    float used_mem = 0.0;

    while (1) {
        fp = fopen("/proc/meminfo", "r");
        fgets(mem_total, sizeof(mem_total), fp);
        fgets(mem_free, sizeof(mem_free), fp);
        fgets(mem_available, sizeof(mem_available), fp);
        sscanf(mem_total, "MemTotal: %llu kB", &total_mem);
        sscanf(mem_free, "MemFree: %llu kB", &free_mem);
        sscanf(mem_available, "MemAvailable: %llu kB", &avail_mem);
        fclose(fp);

        used_mem = (float)(total_mem - avail_mem) / total_mem * 100.0;

        system("clear");
        printf("________________________________________\n");
        printf("|               Memory Usage            |\n");
        printf("|                                      |\n");
        printf("|   Total Memory:    %6.2f MB          |\n", (float)total_mem / MB_TO_BYTES);
        printf("|   Free Memory:     %6.2f MB          |\n", (float)free_mem / MB_TO_BYTES);
        printf("|   Used Memory:     %6.2f%%         |\n", used_mem);
        printf("|______________________________________|\n");

        sleep(1);
    }

    return 0;
}