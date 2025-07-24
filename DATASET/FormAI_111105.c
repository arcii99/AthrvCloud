//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: authentic
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define TOTAL_RAM 1024 // Total RAM in MB
#define INTERVAL 1 // Sleep interval in seconds

int main() {
    int total_ram = TOTAL_RAM * 1024 * 1024; // Converting total_ram from MB to Bytes
    int used_ram = 0;
    int pid = getpid(); // Getting PID of the current process
    
    while(1) {
        FILE* fp = fopen("/proc/self/status", "r"); // Opening the status file of the current process
        if(fp == NULL) {
            printf("Error opening file.\n");
            exit(1);
        }
        
        char line[128]; // Buffer to store each line
        while(fgets(line, sizeof(line), fp)) {
            sscanf(line, "VmRSS: %d", &used_ram); // Extracting the VmRSS (resident set size) value
        }
        fclose(fp); // Closing the file
        
        used_ram *= 1024; // Converting used_ram from KB to Bytes
        printf("Process ID: %d \tTotal RAM: %d MB \tUsed RAM: %d MB \tRAM Usage: %0.2f%%\n", pid, TOTAL_RAM, used_ram / (1024 * 1024), (float)used_ram / total_ram * 100); // Printing the RAM usage
        
        sleep(INTERVAL); // Sleeping for INTERVAL seconds
    }
    
    return 0;
}