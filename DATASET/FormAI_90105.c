//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 100

void parseLine(char* line, int* resident, int* shared) {
    if (strstr(line, "RssAnon:")) {
        sscanf(line, "RssAnon:%d kB", resident);
    }
    if (strstr(line, "RssFile:")) {
        sscanf(line, "RssFile:%d kB", shared);
    }
}

void getMemoryUsage(int* resident, int* shared) {
    FILE* file = fopen("/proc/self/statm", "r");
    char buffer[BUFFER_SIZE];
    fgets(buffer, BUFFER_SIZE, file);
    parseLine(buffer, resident, shared);
    fclose(file);
}

int main() {
    int resident, shared;
    while (1) {
        getMemoryUsage(&resident, &shared);
        printf("Resident memory usage: %d kB\n", resident);
        printf("Shared memory usage: %d kB\n", shared);
        sleep(1);
    }
    return 0;
}