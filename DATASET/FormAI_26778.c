//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 256

int main() {
    char line[MAX_LINE_SIZE];
    FILE* fp;
    int total_mem, free_mem, used_mem;

    while(1) {
        /* Open the "/proc/meminfo" file */
        fp = fopen("/proc/meminfo", "r");

        if(fp == NULL) {
            printf("Error: Could not open the \"/proc/meminfo\" file!\n");
            return 1;
        }

        /* Read the total and free memory from the file */
        while(fgets(line, MAX_LINE_SIZE, fp)) {
            if(strncmp(line, "MemTotal:", strlen("MemTotal:")) == 0) {
                sscanf(line, "MemTotal: %d", &total_mem);
            }

            if(strncmp(line, "MemFree:", strlen("MemFree:")) == 0) {
                sscanf(line, "MemFree: %d", &free_mem);
            }
        }

        /* Close the file */
        fclose(fp);

        /* Calculate the used memory */
        used_mem = total_mem - free_mem;

        /* Print the memory usage */
        printf("Total Memory: %d kB | Used Memory: %d kB | Free Memory: %d kB\n", total_mem, used_mem, free_mem);

        /* Wait for 1 second */
        sleep(1);
    }

    return 0;
}