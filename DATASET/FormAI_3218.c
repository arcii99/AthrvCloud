//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s [interval]\n", argv[0]);
        return 1;
    }
    
    int interval = atoi(argv[1]);
    
    if (interval <= 0) {
        printf("Invalid interval, please provide a positive integer.\n");
        return 1;
    }
    
    printf("Monitoring CPU usage every %d seconds...\n", interval);
    
    while (1) {
        char command[100];
        sprintf(command, "ps -A -o %%cpu | awk '{s+=$1} END {print s}'");
        
        FILE* pipe = popen(command, "r");
        if (!pipe) {
            perror("Error opening pipe");
            return 1;
        }
        
        char buffer[100];
        memset(buffer, 0, sizeof(buffer));
        fread(buffer, sizeof(char), sizeof(buffer), pipe);
        
        float cpu_usage = atof(buffer);
        printf("CPU usage: %.2f%%\n", cpu_usage);
        pclose(pipe);
        sleep(interval);
    }
    
    return 0;
}