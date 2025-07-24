//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: peaceful
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

int main() {
    char command[MAX_LEN], mem_info[MAX_LEN];
    memset(mem_info, 0, sizeof(mem_info)); // Initialize mem_info with 0

    while(1) {
        // Clear the command array
        memset(command, 0, sizeof(command));

        // Read the current RAM usage from /proc/meminfo
        FILE *fp = fopen("/proc/meminfo", "r");
        if(fp == NULL) {
            printf("Error reading meminfo\n");
            return 1;
        }
        fgets(mem_info, MAX_LEN, fp);
        fclose(fp);

        // Extract the ram usage value from the mem_info string
        char* token = strtok(mem_info, ":");
        int ram_usage;
        if(token != NULL) {
            token = strtok(NULL, " ");
            ram_usage = atoi(token);
        }
        else {
            printf("Error reading RAM usage\n");
            return 1;
        }

        ram_usage /= 1024; // Convert to MB

        // Print the current RAM usage and sleep for 1 second
        printf("Current RAM usage: %d MB\n", ram_usage);
        sleep(1);
    }

    return 0;
}