//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MEM_INFO_PATH "/proc/meminfo"

int main()
{
    FILE* file = fopen(MEM_INFO_PATH, "r");
    if (!file)
    {
        fprintf(stderr, "Error opening file: %s\n", MEM_INFO_PATH);
        exit(1);
    }

    float total_mem, used_mem, free_mem;
    char unit[10];

    fscanf(file, "MemTotal: %f %s\n", &total_mem, unit);
    fscanf(file, "MemFree: %f %s\n", &free_mem, unit);
    used_mem = total_mem - free_mem;

    printf("Total memory:\t%.2f %s\n", total_mem, unit);
    printf("Used memory:\t%.2f %s\n", used_mem, unit);
    printf("Free memory:\t%.2f %s\n", free_mem, unit);

    float used_mem_pct = (used_mem / total_mem) * 100.0;
    printf("Used memory %%:\t%.2f %%\n", used_mem_pct);

    fclose(file);

    return 0;
}