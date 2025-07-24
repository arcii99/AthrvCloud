//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    long ram_usage;
    FILE* fp = fopen("/proc/meminfo", "r"); // Opening the file that contains memory information
    if(fp == NULL) {
        printf("Error: Failed to open /proc/meminfo\n");
        exit(EXIT_FAILURE);
    }
    char buf[256], key[256];
    while(fgets(buf, sizeof(buf), fp)) {
        if(sscanf(buf, "%s %ld", key, &ram_usage) != 2) continue;
        if(strcmp(key, "MemAvailable:") == 0) break;
    }
    fclose(fp); // Closing the file as we no longer need it
    printf("Current RAM usage: %ld kB\n", ram_usage);
    return 0;
}