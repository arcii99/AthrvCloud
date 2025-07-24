//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    long pagesize = sysconf(_SC_PAGESIZE);
    int mem_total_kb, mem_free_kb, mem_used_kb;

    FILE* fp = fopen("/proc/meminfo", "r");
    if (fp) {
        fscanf(fp, "MemTotal: %d kB", &mem_total_kb);
        fscanf(fp, "MemFree: %d kB", &mem_free_kb);
        fclose(fp);
    }

    mem_used_kb = mem_total_kb - mem_free_kb;

    printf("Total Memory: %d MB\n", mem_total_kb / 1024);
    printf("Memory Used: %d MB\n", mem_used_kb / 1024);
    printf("Memory Free: %d MB\n", mem_free_kb / 1024);

    int num_iterations = 10;
    int i;
    for (i=0; i<num_iterations; i++) {
        // allocate 100MB memory
        int *p = (int *) malloc(100*1024*1024);

        if (p == NULL) {
            printf("Error allocating memory.");
            exit(1);
        }

        printf("Memory allocated successfully! Remaining iterations: %d\n", num_iterations - i - 1);

        // wait for 5 seconds
        sleep(5);

        // free the memory
        free(p);
        printf("Memory freed successfully!\n");
    }

    return 0;
}