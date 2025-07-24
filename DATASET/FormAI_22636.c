//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
    unsigned long total;
    unsigned long used;
    double usage_percent;
} MemInfo;

void get_mem_info(MemInfo *mem_info) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;

    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Error opening /proc/meminfo");
        exit(EXIT_FAILURE);
    }
    while (getline(&line, &len, fp) != -1) {
        if (strstr(line, "MemTotal:") != NULL) {
            sscanf(line, "MemTotal: %lu", &(mem_info->total));
        }
        else if (strstr(line, "MemAvailable:") != NULL) {
            sscanf(line, "MemAvailable: %lu", &(mem_info->used));
        }
    }

    free(line);
    fclose(fp);

    mem_info->usage_percent = mem_info->used * 100.0 / mem_info->total;
}

int main() {
    MemInfo mem_info;
    while (1) {
        get_mem_info(&mem_info);
        printf("Current RAM usage: %.2f%%\n", mem_info.usage_percent);
        sleep(5);
    }
    return 0;
}