//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    long cur_ram, total_ram;

    while(1) {
        FILE* fp = fopen("/proc/meminfo", "r");

        if (fp == NULL) {
            fprintf(stderr, "Error while opening the file '/proc/meminfo'.\n");
            exit(EXIT_FAILURE);
        }

        char line[128];
        fgets(line, sizeof(line), fp);
        sscanf(line, "MemTotal: %ld kB", &total_ram);

        fgets(line, sizeof(line), fp);
        sscanf(line, "MemFree: %ld kB", &cur_ram);

        fclose(fp);

        printf("Current RAM usage is %ld kB out of %ld kB.\n", 
               total_ram - cur_ram, total_ram);

        sleep(1);
    }

    return 0;
}