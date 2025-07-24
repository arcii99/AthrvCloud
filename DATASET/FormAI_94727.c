//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: paranoid
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 

#define BUFFER_SIZE 256 

int main() { 

    char command[BUFFER_SIZE]; 
    int memUsage = 0; 

    while(1) { 

        // Clear screen
        system("clear"); 

        // Get RAM usage
        FILE* file = fopen("/proc/meminfo", "r"); 
        if(file == NULL) {
            printf("Error: unable to open /proc/meminfo\n");
            exit(EXIT_FAILURE);
        }
        fscanf(file, "MemAvailable: %d kB", &memUsage); 
        fclose(file); 

        // Check for suspicious activity 
        if(memUsage < 2048) { 
            printf("Warning: low memory available\n");
            sprintf(command, "ps aux --sort=-%c | head -n 11", memUsage); 
            system(command); 
        } else if(memUsage > 1024000) { 
            printf("Warning: high memory usage detected\n"); 
            sprintf(command, "ps aux --sort=-%c | head -n 11", memUsage); 
            system(command); 
        } 

        // Wait for one second before checking again
        sleep(1); 

    } 

    return 0; 
}