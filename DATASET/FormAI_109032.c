//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define SLEEP_TIME 1

int main()
{
    char buffer[BUFFER_SIZE];
    unsigned long total_mem, free_mem, used_mem;
    FILE *mem_info;

    int i;
    for (i = 0; i < 50; i++)
    {
        mem_info = fopen("/proc/meminfo", "r");
        if (mem_info == NULL)
        {
            printf("Error: Failed to open /proc/meminfo file.\n");
            exit(EXIT_FAILURE);
        }

        while (fgets(buffer, BUFFER_SIZE, mem_info))
        {
            if (sscanf(buffer, "MemTotal: %lu", &total_mem) == 1)
            {
                // do nothing and move forward
            }
            else if (sscanf(buffer, "MemFree: %lu", &free_mem) == 1)
            {
                // do nothing and move forward
            }
        }
        fclose(mem_info);

        used_mem = total_mem - free_mem;
        float used_mem_percentage = (float)used_mem / (float)total_mem * 100;

        printf("Used Memory: %lu kB (%.2f%%)\n", used_mem, used_mem_percentage);

        sleep(SLEEP_TIME);
    }

    return 0;
}