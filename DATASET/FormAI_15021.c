//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// This function returns the current RAM usage in bytes
unsigned long long getRAMUsage() {
    int pid = getpid();
    char command[40], size[20];
    sprintf(command, "pmap -x %d | tail -1 | awk '{print $2}'", pid);
    FILE* results = popen(command, "r");
    fgets(size, sizeof(size), results);
    pclose(results);
    return atoi(size) * 1024;
}

int main() {
    unsigned long long maxRAM = 0;
    printf("Starting RAM usage monitor...\n");
    while (1) {
        unsigned long long RAM = getRAMUsage();
        if (RAM > maxRAM) {
            maxRAM = RAM;
            printf("New max RAM usage: %llu bytes!\n", maxRAM);
        }
        printf("Current RAM usage: %llu bytes\n", RAM);
        sleep(1); // sleep for 1 second
    }
    return 0;
}