//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_RAM_USAGE 100

void print_usage(int ram_usage) {
    printf("Current RAM usage: %d%%\n", ram_usage);
}

int main() {
    int total_ram = 8192; // Total RAM size in MB
    int used_ram = 0; // Used RAM size in MB
    int ram_usage = 0; // RAM usage percentage
    int interval = 1; // Refresh interval in seconds
    int max_usage = 0; // Maximum RAM usage
    int i = 0; // Counter

    srand(time(0)); // Initialize random seed

    while (used_ram < total_ram) {
        used_ram += (rand() % 5) + 1; // Add random amount of RAM usage
        ram_usage = (used_ram * 100) / total_ram; // Calculate usage percentage

        if (ram_usage > max_usage) {
            max_usage = ram_usage; // Update maximum usage
        }

        print_usage(ram_usage);

        if (ram_usage >= MAX_RAM_USAGE) {
            printf("WARNING: RAM usage exceeded %d%%\n", MAX_RAM_USAGE);
        }

        sleep(interval); // Wait for next refresh interval

        i++;

        if (i == 10) { // Simulate closing the program after 10 iterations
            break;
        }
    }

    printf("Maximum RAM usage: %d%%\n", max_usage);
    
    return 0;
}