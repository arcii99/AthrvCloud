//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_MEM_USAGE 500 // Arbitrary limit for demonstration purposes only
#define SLEEP_TIME 1 // Time in seconds between checks

int main() {
    FILE *file;
    char line[128];
    char *mem_usage_string;
    int mem_usage;
    
    while(1) {
        file = fopen("/proc/meminfo", "r"); // Open the file containing memory information
        
        if(file == NULL) {
            printf("Error: Could not open file!\n");
            exit(1);
        }
        
        while(fgets(line, sizeof(line), file)) { // Read through the file line by line
            if(sscanf(line, "Cached: %s", mem_usage_string) == 1) { // Look for the line containing the cached memory usage
                mem_usage = atoi(mem_usage_string); // Convert the memory usage string to an integer
                
                if(mem_usage > MAX_MEM_USAGE) { // If the memory usage is over the limit, print a warning
                    printf("Warning: Memory usage is at %d KB!\n", mem_usage);
                }
                
                break; // Exit the loop as soon as the desired line is found
            }
        }
        
        fclose(file); // Close the file
        
        sleep(SLEEP_TIME); // Wait for a specified amount of time before checking memory usage again
    }
    
    return 0;
}