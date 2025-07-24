//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo mem_info; // sysinfo struct to store memory information
    long long total_memory; // Total RAM in kilobytes
    long long free_memory; // Free RAM in kilobytes
    long long used_memory; // Used RAM in kilobytes
    
    while(1) { // Keep monitoring RAM usage indefinitely
        printf("Getting memory information...\n");
        if(sysinfo(&mem_info) != 0) {
            perror("Error while getting system information!");
            exit(EXIT_FAILURE);
        }
        total_memory = (long long) mem_info.totalram * mem_info.mem_unit / 1024; // Calculate total RAM
        free_memory = (long long) mem_info.freeram * mem_info.mem_unit / 1024; // Calculate free RAM
        used_memory = total_memory - free_memory; // Calculate used RAM
        printf("Total RAM: %lld kB\n", total_memory);
        printf("Free RAM: %lld kB\n", free_memory);
        printf("Used RAM: %lld kB\n", used_memory);
        printf("RAM Usage: %.2f%%\n", (float) used_memory / total_memory * 100); // Calculate RAM usage percentage
        sleep(5); // Wait for 5 seconds and check again
    }
    
    return EXIT_SUCCESS;
}