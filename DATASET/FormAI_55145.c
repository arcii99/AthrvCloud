//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: minimalist
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 80

int main(void) {
    char line[MAX_LINE_LEN];
    char mem_total[MAX_LINE_LEN];
    char mem_free[MAX_LINE_LEN];
    char mem_avail[MAX_LINE_LEN];
    char mem_used[MAX_LINE_LEN];
    char percent_used[MAX_LINE_LEN];

    while (1) {
        FILE* fp = fopen("/proc/meminfo", "r");
        if (fp == NULL) {
            continue;
        }

        fgets(line, MAX_LINE_LEN, fp);
        sscanf(line, "MemTotal: %s", mem_total);

        fgets(line, MAX_LINE_LEN, fp);
        sscanf(line, "MemFree: %s", mem_free);

        fgets(line, MAX_LINE_LEN, fp);
        sscanf(line, "MemAvailable: %s", mem_avail);

        fclose(fp);

        long long total_mem = atoll(mem_total);
        long long free_mem = atoll(mem_free);
        long long avail_mem = atoll(mem_avail);
        long long used_mem = total_mem - avail_mem;
        double percent = ((double) used_mem) / total_mem;

        sprintf(mem_used, "%lld", used_mem);
        sprintf(percent_used, "%.2f%%", percent * 100);

        printf("Used: %s, Percent Used: %s\n", mem_used, percent_used);

        sleep(1);
    }

    return 0;
}