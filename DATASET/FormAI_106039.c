//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define INTERVAL 2 // Sleep interval in seconds

int main() {
    char cpu_usage[50];
    FILE* fp;
    float usage;
    char command[50];
    
    while(1) {
        sprintf(command, "top -b -n 1 | grep \"Cpu(s)\" | awk '{print $2 + $4}'"); // Get CPU usage command
        fp = popen(command, "r"); // Execute command and open pipe to read result
        if (fp == NULL) {
            printf("Failed to fetch CPU usage\n");
            exit(1);
        }
        fgets(cpu_usage, sizeof(cpu_usage), fp); // Read CPU usage from pipe
        pclose(fp); // Close pipe

        usage = atof(cpu_usage); // Convert usage from string to float
        printf("CPU Usage: %.2f%%\n", usage); // Print CPU usage
        sleep(INTERVAL); // Sleep interval before checking again
    }

    return 0;
}