//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main(void) {
    char buffer[MAX_BUFFER_SIZE];
    int pid = getpid();
    sprintf(buffer, "/proc/%d/status", pid);
    FILE* file = fopen(buffer, "r");
    if (!file) {
        printf("Failed to open file for reading.\n");
        return 1;
    }
    unsigned int ram_usage = 0;
    while (fgets(buffer, MAX_BUFFER_SIZE, file)) {
        if (strncmp(buffer, "VmSize:", strlen("VmSize:")) == 0) {
            sscanf(buffer, "VmSize:%u", &ram_usage);
            break;
        }
    }
    fclose(file);
    printf("Current RAM usage: %u kB\n", ram_usage);
    return 0;
}