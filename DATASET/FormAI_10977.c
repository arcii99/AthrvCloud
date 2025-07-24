//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: systematic
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char command[MAX_LENGTH];
    float cpu_usage;
    int uptime, idle_time, cpu_time;
    int prev_idle_time = 0, prev_cpu_time = 0;
    char cpu_data[50];
    
    while(1) {
        // Run the 'uptime' command to get system information
        strcpy(command, "uptime");
        FILE* output = popen(command, "r");
        if (output == NULL) {
            printf("Failed to run command\n");
            exit(1);
        }

        // Parse the output and extract uptime and CPU usage data
        fgets(cpu_data, 50, output);
        sscanf(cpu_data, " %d %*s %*s %*s %*s %d %d", &uptime, &idle_time, &cpu_time);
        pclose(output);
        
        // Calculate the CPU usage percentage
        cpu_usage = ((float)(cpu_time - prev_cpu_time) / (float)((cpu_time + idle_time) - (prev_cpu_time + prev_idle_time))) * 100.0;

        // Update the previous CPU and idle times
        prev_idle_time = idle_time;
        prev_cpu_time = cpu_time;
        
        // Print the CPU usage percentage
        printf("Current CPU usage: %0.2f%%\n", cpu_usage);
        
        // Wait for 1 second before checking CPU usage again
        sleep(1);
    }
    return 0;
}