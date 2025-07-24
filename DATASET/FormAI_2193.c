//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // for sleep function

int main()
{
    FILE *fp;
    char buffer[1024];
    float total_mem, free_mem, used_mem;
    const char *memInfoFile = "/proc/meminfo";

    while(1) {
        sleep(1); // sleep for 1 second
        fp = fopen(memInfoFile, "r");

        if(fp == NULL) {
            fprintf(stderr, "Error opening file '%s'\n", memInfoFile);
            return 1;
        }

        while(fgets(buffer, sizeof(buffer), fp)) {
            if(strncmp(buffer, "MemTotal:", 9) == 0) {
                total_mem = atof(buffer + 9)/1024;
            }
            else if(strncmp(buffer, "MemFree:", 8) == 0) {
                free_mem = atof(buffer + 8)/1024;
            }
        }

        fclose(fp);

        used_mem = total_mem - free_mem;

        printf("Total Memory: %.2f MB\n", total_mem);
        printf("Used Memory: %.2f MB\n", used_mem);
        printf("Free Memory: %.2f MB\n", free_mem);
        printf("---------------------------------------\n");
    }

    return 0;
}