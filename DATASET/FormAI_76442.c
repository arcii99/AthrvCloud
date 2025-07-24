//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

void printRamUsage() {
    char buffer[BUFFER_SIZE];

    FILE* file = fopen("/proc/meminfo", "r");

    if (!file) {
        printf("Failed to open /proc/meminfo.");
        return;
    }

    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        if (strstr(buffer, "MemTotal:") != NULL) {
            printf("Total RAM: %ld\n", atol(buffer + strlen("MemTotal:")) / 1024);
        
        } else if (strstr(buffer, "MemFree:") != NULL) {
            printf("Free RAM: %ld\n", atol(buffer + strlen("MemFree:")) / 1024);
        }   
    }

    fclose(file);
}

int main() {
    while (1) {
        printRamUsage();
        sleep(1);
        system("clear"); // Clear the console output for every iteration.
    }

    return 0;
}