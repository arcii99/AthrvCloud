//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: light-weight
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define RAM_STAT "/proc/meminfo"
#define SAMPLE_INTERVAL 1 //seconds

void print_usage(float usage) {
    printf("\rRAM usage: %.2f%%", usage);
    fflush(stdout);
}

float get_ram_usage() {
    FILE *memfile = fopen(RAM_STAT, "r");
    if (!memfile) {
        perror("Could not read " RAM_STAT);
        exit(1);
    }
    char temp[64];
    unsigned long memfree = 0;
    unsigned long memtotal = 0;
    while (fscanf(memfile, "%s %lu", temp, &memfree) != EOF) {
        if (strcmp(temp, "MemTotal:") == 0)
            memtotal = memfree;
        else if (strcmp(temp, "MemFree:") == 0)
            break;
    }
    fclose(memfile);
    float usage = 100.0 * ((float)(memtotal - memfree)) / memtotal;
    return usage;
}

int main() {
    printf("Monitoring RAM usage (Press Ctrl-C to exit)...\n");
    while(1) {
        float usage = get_ram_usage();
        print_usage(usage);
        sleep(SAMPLE_INTERVAL);
    }
    return 0;
}