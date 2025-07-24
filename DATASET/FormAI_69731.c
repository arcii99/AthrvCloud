//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>

int main()
{
    struct sysinfo si;
    float total_memory_size, free_memory_size, used_memory_size, usage_percentage;

    while (1) {
        sysinfo(&si);
        total_memory_size = si.totalram / 1024.0 / 1024.0;
        free_memory_size = si.freeram / 1024.0 / 1024.0;
        used_memory_size = total_memory_size - free_memory_size;
        usage_percentage = (used_memory_size / total_memory_size) * 100;

        printf("\n///////////////////////////////////////////////\n");
        printf("                  MEMORY STATS                 \n");
        printf("///////////////////////////////////////////////\n\n");

        printf("TOTAL MEMORY: %.2f MB\n", total_memory_size);
        printf("USED MEMORY:  %.2f MB\n", used_memory_size);
        printf("FREE MEMORY:  %.2f MB\n", free_memory_size);
        printf("USAGE:        %.2f%%\n\n", usage_percentage);

        sleep(1); // sleep for 1 second before next refresh
        system("clear"); // clear the console screen
    }

    return 0;
}