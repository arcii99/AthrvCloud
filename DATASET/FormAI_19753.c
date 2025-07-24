//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    char mem[10];
    char* command;
    FILE* procFile;
    
    while(1) {
        // Open the file that contains the RAM usage information for the current process
        procFile = fopen("/proc/self/status", "r");
        
        // Read the contents of the file line by line until we reach the line containing RAM information
        while(fgets(mem, 10, procFile)) {
            if(strncmp(mem, "VmRSS:", 6) == 0) {
                // The line containing RAM information has been found, output it
                printf("Current RAM usage: %s", mem);
                break;
            }
        }
        
        // Close the file and wait for a second before checking again
        fclose(procFile);
        sleep(1);
    }
    
    return 0;
}