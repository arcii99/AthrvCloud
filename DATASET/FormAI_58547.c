//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>

/* Structure to hold memory usage statistics */
typedef struct {
    int total_mem;
    int used_mem;
} mem_stats;

/* Function to get memory usage statistics */
mem_stats get_memory_stats() {
    mem_stats stats;
    FILE* fp;
    char buffer[1024];

    /* Open the proc/meminfo file */
    fp = fopen("/proc/meminfo", "r");

    /* Read the total memory and used memory */
    fgets(buffer, 1024, fp);
    sscanf(buffer, "MemTotal:%d kB", &stats.total_mem);
    fgets(buffer, 1024, fp);
    sscanf(buffer, "MemFree:%*d kB Buffers:%*d kB Cached:%*d kB", &stats.used_mem);

    /* Close the file and return the stats */
    fclose(fp);
    return stats;
}

int main() {
    while(1) {
        mem_stats stats = get_memory_stats();
        int used_percent = (stats.used_mem * 100) / stats.total_mem;

        /* Print the memory usage statistics */
        printf("Total Memory: %d kB\n", stats.total_mem);
        printf("Used Memory: %d kB (%d%%)\n", stats.used_mem, used_percent);

        /* Wait for 1 second before checking again */
        sleep(1);
    }

    return 0;
}